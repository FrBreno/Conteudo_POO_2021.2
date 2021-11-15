#include "sala.hpp"

Sala::Sala(int capacidade) : capacidade{capacidade} {}

void Sala::setCapacidade(int capacidade)
{
  this->capacidade = capacidade;
  for (int i{0}; i < capacidade; i++)
  {
    this->cadeiras.push_back(make_shared<Cliente>("0", "-"));
  }
  return;
}

int Sala::getCapacidade()
{
  return this->capacidade;
}

list<shared_ptr<Cliente>> Sala::getCadeiras()
{
  return this->cadeiras;
}

void Sala::exit()
{
  this->cadeiras.clear();

  return;
}