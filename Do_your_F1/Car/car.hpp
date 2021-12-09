#include "../Vehicle/vehicle.hpp"

class Car : public Vehicle
{
  string brand{"unknown"}; // marca
  string color{"unknown"}; // cor
public:
  Car(bool engine, int wheels, int maxSpeed, string brand, string color);

  void setBrand(string brand);
  string getBrand() const;

  void setColor(string color);
  string getColor() const;

  virtual bool verification(); // it is a car?
  virtual void toDrive();

  friend ostream &operator<<(ostream &os, Car &c)
  {
    os << *(Vehicle *)&c;
    os << "Brand: " << c.brand << endl;
    os << "Color: " << c.color << endl;
    return os;
  }
};