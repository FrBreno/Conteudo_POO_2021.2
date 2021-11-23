#include "fone.hpp"

Fone::Fone(string id, string number) : id{id}, number{number} {}

bool Fone::validate(string number)
{
  for (int i{0}; i < (int)number.length(); i++)
  {
    if (((int)number[i] < 48 && (int)number[i] != 46 && (int)number[i] != 41 && (int)number[i] != 40) || (int)number[i] > 57)
    {
      cout << "[ERROR!] Invalid number\n";
      return false;
    }
  }
  return true;
}

string Fone::toString()
{
  return this->id + ":" + this->number;
}

string Fone::getNumber()
{
  return this->number;
}

string Fone::getId()
{
  return this->id;
}

void Fone::setId(string id)
{
  this->id = id;
  return;
}

void Fone::setNumber(string number)
{
  this->number = number;
  return;
}