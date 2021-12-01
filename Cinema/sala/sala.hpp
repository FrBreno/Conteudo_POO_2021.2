#include "../cliente/cliente.hpp"
#include <vector>
#include <memory>

class Sala
{
  vector<shared_ptr<Cliente>> cadeiras;
  int capacidade{0};

public:
  Sala(int capacidade);
  void setCapacidade(int capacidade);
  int getCapacidade();
  vector<shared_ptr<Cliente>> *getCadeiras();
  void exit();
};