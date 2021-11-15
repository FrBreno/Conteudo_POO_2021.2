#include "cliente.hpp"

Cliente::Cliente(string fone = "0000", string id = "-") : fone{fone}, id{id} {}

string Cliente::toString()
{
  if (this->id == "-")
  {
    return this->id;
  }
  return this->id + ":" + this->fone;
}

string Cliente::getFone()
{
  return this->fone;
}
string Cliente::getId()
{
  return this->id;
}
void Cliente::setFone(string fone)
{
  this->fone = fone;
  return;
}
void Cliente::setId(string id)
{
  this->id = id;
  return;
}