#include "adm.hpp"

void Adm::criarSala(int capacidade)
{
  if (this->sala.getCapacidade() != 0)
  {
    sala.exit();
  }
  this->sala.setCapacidade(capacidade);
  this->cadeirasAdm = sala.getCadeiras();
}

int Adm::buscaCadeira(string id)
{
  int i{0};
  for (shared_ptr<Cliente> it : *cadeirasAdm)
  {
    if (it != nullptr && it->getId() == id)
    {
      return i;
    }
    i++;
  }
  return -1;
}

bool Adm::reservar(string id, string fone, int ind)
{
  if (ind >= this->sala.getCapacidade())
  {
    if (this->sala.getCapacidade() == 0)
    {
      cout << "Tu tem que inicializar a sala primeiro Adm!\n";
      return false;
    }
    cout << "Digite apenas cadeiras do numero 0 ao " << this->sala.getCapacidade() - 1 << endl;
    return false;
  }

  if (this->buscaCadeira(id) != -1)
  {
    cout << "ERROR! Ja tem gente com esse ID na sala.\n";
    return false;
  }

  vector<shared_ptr<Cliente>>::iterator pos_cadeira = this->cadeirasAdm->begin() + ind;
  if (*pos_cadeira != nullptr)
  {
    cout << "Ja tem gente sentada ai ja man.\n";
    return false;
  }
  *pos_cadeira = make_shared<Cliente>(fone, id);
  return true;
}

shared_ptr<Cliente> Adm::cancelar(string id)
{
  int i = this->buscaCadeira(id);
  if (i != -1)
  {
    vector<shared_ptr<Cliente>>::iterator it = this->cadeirasAdm->begin() + i;
    return exchange(*it, nullptr);
  }
  cout << "Id nao encontrado (cliente nao esta no cinema)\n";
  return nullptr;
}

string Adm::toString()
{
  string line;

  if (sala.getCapacidade() == 0)
  {
    line = "[ ]";
  }
  else
  {
    line = "[ ";
    for (auto &cadeira : *cadeirasAdm)
    {
      if (cadeira != nullptr)
      {
        line += cadeira->toString() + " ";
      }
      else
      {
        line += "- ";
      }
    }
    line += "]";
  }

  return line;
}

void Adm::exitAdm()
{
  this->sala.exit();
  delete this->cadeirasAdm;
  return;
}