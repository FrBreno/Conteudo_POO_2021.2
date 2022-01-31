#include "kid.hpp"

Kid::Kid(string name, int age) : name{name}, age{age} {}

void Kid::setName(string name)
{
  this->name = name;
  return;
}
void Kid::setAge(int age)
{
  this->age = age;
  return;
}
string Kid::getName()
{
  return this->name;
}
int Kid::getAge()
{
  return this->age;
}
string Kid::toString()
{
  return this->name + ":" + to_string(this->age);
}