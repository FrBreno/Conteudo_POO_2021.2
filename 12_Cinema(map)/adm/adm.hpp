#include "../sala/sala.hpp"

class Adm
{
  Sala sala{0};
  map<int, shared_ptr<Cliente>> *cadeirasAdm;

public:
  void criarSala(int capacidade);
  int buscaCadeira(string id);

  bool reservar(string id, string fone, int ind);
  shared_ptr<Cliente> cancelar(string id);
  string toString();
  void exitAdm();
};