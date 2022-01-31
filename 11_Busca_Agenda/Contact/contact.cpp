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

// string Contact::toString()
// {
//   string flow = "- " + name;
//   for (int i{0}; i < (int)this->fones.size(); i++)
//   {
//     flow += " [";
//     flow += to_string(i) + ":" + this->fones[i].toString() + "]";
//   }

//   return flow;
// }

void Contact::setName(string name = "")
{
  if ((int)this->fones.size() > 0)
  {
    this->fones.clear();
  }
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