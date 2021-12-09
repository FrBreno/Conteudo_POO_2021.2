#include "car.hpp"

Car::Car(bool engine, int wheels, int maxSpeed, string brand, string color) : Vehicle{engine, wheels, maxSpeed}, brand{brand}, color{color}
{
  this->mark = "car";
}

void Car::setBrand(string brand)
{
  this->brand = brand;
}
string Car::getBrand() const
{
  return this->brand;
}

void Car::setColor(string color)
{
  this->color = color;
}
string Car::getColor() const
{
  return this->color;
}

bool Car::it_is_a_car()
{
  if (this->isEngine() && this->getWheels() == 4)
  {
    return true;
  }
  return false;
}

void Car::toDrive()
{
  if (this->it_is_a_car())
  {
    cout << "Are you driving! (Voce esta dirigindo!)\n";
    return;
  }
  cout << "The " << this->mark << " did not start :/ (O carro nao ligou)\n";
  return;
}