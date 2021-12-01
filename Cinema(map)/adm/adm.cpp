#include "adm.hpp"

void Adm::criarSala(int capacidade)
{
  if (this->sala.getCapacidade() != 0)
  {
    sala.exit(); // Exclui as cadeiras da sala anterior
  }
  this->sala.setCapacidade(capacidade);
  this->cadeirasAdm = sala.getCadeiras(); // Ponteiro aponta para as cadeiras.
}

int Adm::buscaCadeira(string id)
{
  // Percorre o map até encontrar o "id", ou retorna -1 caso não encontre.
  for (auto &[pos, cliente] : *cadeirasAdm)
  {
    if (cliente != nullptr && cliente->getId() == id)
    {
      return pos;
    }
  }
  return -1;
}

bool Adm::reservar(string id, string fone, int ind)
{
  if (ind >= this->sala.getCapacidade()) // Verifica se o "ind" foi passado incorretamente.
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

  map<int, shared_ptr<Cliente>>::iterator it = cadeirasAdm->find(ind);
  if (it->second != nullptr)
  {
    cout << "Ja tem gente sentada ai ja man.\n";
    return false;
  }
  it->second = make_shared<Cliente>(fone, id);
  return true;
}

shared_ptr<Cliente> Adm::cancelar(string id)
{
  int i = this->buscaCadeira(id);
  if (i != -1)
  {
    return exchange(cadeirasAdm->find(i)->second, nullptr);
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
      if (cadeira.second != nullptr)
      {
        line += cadeira.second->toString() + " ";
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
  this->cadeirasAdm = nullptr;
  return;
}