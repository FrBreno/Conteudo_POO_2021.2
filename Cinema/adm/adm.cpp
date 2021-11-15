#include "adm.hpp"
#include <iterator>

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
  int cont{0};
  if (ind >= sala.getCapacidade())
  {
    cout << "Digite apenas cadeiras do numero 0 ao " << sala.getCapacidade() - 1 << endl;
    return false;
  }
  for (shared_ptr<Cliente> i : this->cadeirasAdm)
  {
    if (cont == ind && i->getId() != "-")
    {
      cout << "Ja tem gente sentada ai ja man.\n";
      return false;
    }
    if (i->getId() == id)
    {
      cout << "ERROR! Ja tem gente com esse ID na sala.\n";
      return false;
    }
    cont++;
  }

  list<shared_ptr<Cliente>>::iterator it;
  it = this->cadeirasAdm.begin();
  advance(it, ind);
  this->cadeirasAdm.insert(it, make_shared<Cliente>(fone, id));
  this->cadeirasAdm.erase(it);

  return true;
}

void Adm::cancelar(string id)
{
  int cont{0};
  list<shared_ptr<Cliente>>::iterator it;
  it = this->cadeirasAdm.begin();

  for (shared_ptr<Cliente> i : this->cadeirasAdm)
  {
    if (i->getId() == id)
    {
      advance(it, cont);
      this->cadeirasAdm.insert(it, make_shared<Cliente>("0", "-"));
      this->cadeirasAdm.erase(it);
      return;
    }
    cont++;
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
    for (shared_ptr<Cliente> i : this->cadeirasAdm)
    {
      line += i->toString() + " ";
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