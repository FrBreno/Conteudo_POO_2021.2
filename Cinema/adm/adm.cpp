#include "adm.hpp"

void Adm::criarSala(int capacidade)
{
  if ((int)this->cadeirasAdm.size() != 0)
  {
    sala.exit();
  }
  this->sala.setCapacidade(capacidade);
  this->cadeirasAdm = sala.getCadeiras();
}

int Adm::buscaCadeira(string id)
{
  for (int i{0}; i < this->sala.getCapacidade(); i++)
  {
    if (this->cadeirasAdm[i] != nullptr && this->cadeirasAdm[i]->getId() == id)
    {
      //Tem gente!
      return i;
    }
  }
  //Cadeira livre:
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
  if (this->cadeirasAdm[ind] != nullptr)
  {
    cout << "Ja tem gente sentada ai ja man.\n";
    return false;
  }

  if (this->buscaCadeira(id) != -1)
  {
    cout << "ERROR! Ja tem gente com esse ID na sala.\n";
    return false;
  }

  this->cadeirasAdm[ind] = make_shared<Cliente>(fone, id);
  return true;
}

shared_ptr<Cliente> Adm::cancelar(string id)
{
  int i = this->buscaCadeira(id);
  if (i != -1)
  {
    return exchange(this->cadeirasAdm[i], nullptr);
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
    for (int i{0}; i < this->sala.getCapacidade(); i++)
    {
      if (this->cadeirasAdm[i] != nullptr)
      {
        line += this->cadeirasAdm[i]->toString() + " ";
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
  this->cadeirasAdm.clear();
  return;
}