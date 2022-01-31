#include "../cliente/cliente.hpp"
#include <memory>
#include <map>

class Sala
{
  map<int, shared_ptr<Cliente>> cadeiras;
  int capacidade{0};

public:
  Sala(int capacidade);
  // Os métodos "cancelar, reservar e toString" estão na classe Adm.
  void setCapacidade(int capacidade);
  int getCapacidade();
  map<int, shared_ptr<Cliente>> *getCadeiras();
  void exit();
};