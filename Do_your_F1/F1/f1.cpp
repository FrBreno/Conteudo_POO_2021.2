#include "f1.hpp"

F1::F1(string brand, string color, bool halo, bool aero, string tire, string number) : Car{true, 4, 320, brand, color}, halo{halo}, aerodynamics{aero}, tireRange{tire}, carNumber{number}
{
  this->mark = "F1";
}

void F1::setHalo(bool halo)
{
  this->halo = halo;
}
bool F1::isHalo() const
{
  return this->halo;
}

void F1::setAero(bool aero)
{
  this->aerodynamics = aero;
}
bool F1::isAero() const
{
  return this->aerodynamics;
}

void F1::setTire(string tire)
{
  this->tireRange = tire;
}
string F1::getTire() const
{
  return this->tireRange;
}

void F1::setNumber(string number)
{
  this->carNumber = number;
}
string F1::getNumber() const
{
  return this->carNumber;
}

bool F1::it_is_a_car() // Isso é um carro de F1?
{
  if (Car::it_is_a_car() && this->halo)
  {
    return true;
  }
  return false;
}

bool F1::competitive()
{
  if (this->aerodynamics)
  {
    return true;
  }
  return false;
}

void F1::toDrive()
{
  if (this->it_is_a_car())
  {
    if (this->competitive())
    {
      cout << "You are fighting for the podium! (voce esta lutando pelo podio)\n";
    }
    else
    {
      cout << "P20 guys, this is bad :/ (P20 galera, isso é ruim)\n";
    }
    return;
  }
  cout << "The " << this->mark << " did not start :/ (O F1 nao ligou)\n";
  return;
}