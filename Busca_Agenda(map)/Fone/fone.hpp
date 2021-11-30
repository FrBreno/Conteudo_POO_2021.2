#include <iostream>

using namespace std;

class Fone
{
  string id{};
  string number{};

public:
  Fone(string id, string number);
  bool validate(string number);
  string toString();

  string getNumber();
  string getId();
  void setId(string id);
  void setNumber(string number);
};