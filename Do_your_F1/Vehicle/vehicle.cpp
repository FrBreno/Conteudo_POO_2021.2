#include "vehicle.hpp"

Vehicle::Vehicle(bool engine, int wheels, int maxSpeed) : engine{engine}, wheels{wheels}, maxSpeed{maxSpeed}
{
}

void Vehicle::setEngine(bool engine)
{
  this->engine = engine;
}
bool Vehicle::isEngine() const
{
  return this->engine;
}

void Vehicle::setWheels(int wheels)
{
  this->wheels = wheels;
}
int Vehicle::getWheels() const
{
  return this->wheels;
}

void Vehicle::setMaxSpeed(int max)
{
  this->maxSpeed = max;
}
int Vehicle::getMaxSpeed() const
{
  return this->maxSpeed;
}