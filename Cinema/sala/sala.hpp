#include "../cliente/cliente.hpp"
#include <list>
#include <memory>

class Sala
{
  list<shared_ptr<Cliente>> cadeiras;
  int capacidade{0};

public:
  Sala(int capacidade);
  void setCapacidade(int capacidade);
  int getCapacidade();
  list<shared_ptr<Cliente>> getCadeiras();
  void exit();
};