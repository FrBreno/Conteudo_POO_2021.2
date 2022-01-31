#include "../kid/kid.hpp"
#include <memory>
#include <list>
#include <utility>

using namespace std;

class Trampoline
{
  list<shared_ptr<Kid>> playing; //logando
  list<shared_ptr<Kid>> waiting; //esperando
  int max{0};
  int idade_max{0};
  int idade_min{0};

  void remove_kid(string name, int age, int cont, bool play, list<shared_ptr<Kid>>::iterator it);

public:
  Trampoline(int max, int idade_max, int idade_min);
  void arrive(shared_ptr<Kid> k); //Colocar na fila de espera.
  void in();                      //Entrar no pula pula.
  void out();                     //Sair do pula pula.
  void remove(string name, int age);
  void exit();
  void setParametros(int max, int idade_max, int idade_min);
  string toString();
};
