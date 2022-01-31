#include "contact.hpp"

Contact::Contact(string name = "") : name{name} {}
void Contact::addFone(Fone fone)
{
  if (fone.validate(fone.getNumber()))
  {
    this->fones.push_back(fone);
  }
  return;
}

void Contact::rmFone(int index)
{
  if (index >= (int)this->fones.size() || index < 0)
  {
    cout << "[ERROR!] Indice nao encontrado!\n";
    return;
  }
  this->fones.erase(fones.begin() + index);
  return;
}

void Contact::setName(string name = "")
{
  this->name = name;
  return;
}

string Contact::getName()
{
  return this->name;
}

vector<Fone> Contact::getFones()
{
  return this->fones;
}