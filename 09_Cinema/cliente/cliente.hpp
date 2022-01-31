#include <iostream>

using namespace std;

class Cliente
{
  string fone{};
  string id{};

public:
  Cliente(string fone, string id);
  string toString();
  string getFone();
  string getId();
  void setFone(string fone);
  void setId(string id);
};