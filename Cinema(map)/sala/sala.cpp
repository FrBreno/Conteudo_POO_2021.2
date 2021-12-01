#include "sala.hpp"

Sala::Sala(int capacidade) : capacidade{capacidade} {}

void Sala::setCapacidade(int capacidade)
{
  this->capacidade = capacidade;
  for (int i{0}; i < capacidade; i++)
  {
    this->cadeiras[i] = nullptr; // Cria as cadeiras com a posição das mesmas como chaveamento.
  }
  return;
}

int Sala::getCapacidade()
{
  return this->capacidade;
}

map<int, shared_ptr<Cliente>> *Sala::getCadeiras()
{
  return &cadeiras;
}

void Sala::exit()
{
  this->cadeiras.clear();

  return;
}