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
};