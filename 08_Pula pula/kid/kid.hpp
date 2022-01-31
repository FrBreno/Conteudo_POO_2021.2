#include <iostream>

using namespace std;

class Kid
{

  int age{0};
  string name{};

public:
  Kid(string name, int age);
  void setName(string name);
  string toString();

  void setAge(int age);
  int getAge();
  string getName();
};