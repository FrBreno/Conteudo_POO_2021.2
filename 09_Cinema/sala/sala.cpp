#include "sala.hpp"

Sala::Sala(int capacidade) : capacidade{capacidade} {}

void Sala::setCapacidade(int capacidade)
{
  this->capacidade = capacidade;
  for (int i{0}; i < capacidade; i++)
  {
    this->cadeiras.push_back(nullptr);
  }
  return;
}

int Sala::getCapacidade()
{
  return this->capacidade;
}

vector<shared_ptr<Cliente>> *Sala::getCadeiras()
{
  return &cadeiras;
}

void Sala::exit()
{
  this->cadeiras.clear();

  return;
}