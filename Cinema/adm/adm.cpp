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

bool Adm::reservar(string id, string fone, int ind)
{
  if (ind >= sala.getCapacidade())
  {
    if (this->sala.getCapacidade() == 0)
    {
      cout << "Tu tem que inicializar a sala primeiro Adm!\n";
      return false;
    }
    cout << "Digite apenas cadeiras do numero 0 ao " << sala.getCapacidade() - 1 << endl;
    return false;
  }
  else if (cadeirasAdm[ind] != nullptr)
  {
    cout << "Ja tem gente sentada ai ja man.\n";
    return false;
  }
  else
  {
    for (int i{0}; i < sala.getCapacidade(); i++)
    {
      if (this->cadeirasAdm[i] != nullptr && this->cadeirasAdm[i]->getId() == id)
      {
        cout << "ERROR! Ja tem gente com esse ID na sala.\n";
        return false;
      }
    }
    this->cadeirasAdm[ind] = make_shared<Cliente>(fone, id);
  }
  return true;
}

void Adm::cancelar(string id)
{
  for (int i{0}; i < sala.getCapacidade(); i++)
  {
    if (this->cadeirasAdm[i] != nullptr && this->cadeirasAdm[i]->getId() == id)
    {
      cadeirasAdm[i] = nullptr;
      return;
    }
  }
  cout << "Id nao encontrado (cliente nao esta no cinema)\n";
  return;
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
    for (int i{0}; i < sala.getCapacidade(); i++)
    {
      if (cadeirasAdm[i] != nullptr)
      {
        line += cadeirasAdm[i]->toString() + " ";
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
  sala.exit();
  this->cadeirasAdm.clear();
  return;
}