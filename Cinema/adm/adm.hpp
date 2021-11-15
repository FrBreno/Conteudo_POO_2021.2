#include "../sala/sala.hpp"

class Adm
{
  Sala sala{0};
  list<shared_ptr<Cliente>> cadeirasAdm;

public:
  void criarSala(int capacidade);
  bool reservar(string id, string fone, int ind);
  void cancelar(string id);
  string toString();
  void exitAdm();
};