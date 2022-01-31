#include <iostream>

using namespace std;

class Vehicle
{
  bool engine{true}; // motor
  int wheels{2};     // rodas
  int maxSpeed{15};  // velocidade máxima
protected:
  string mark{"vehicle"};

public:
  Vehicle(bool engine, int wheels, int maxSpeed);
  void setEngine(bool engine);
  bool isEngine() const;

  void setWheels(int wheels);
  int getWheels() const;

  void setMaxSpeed(int max);
  int getMaxSpeed() const;

  friend ostream &operator<<(ostream &os, const Vehicle &v)
  {
    // Printa os atributos da classe (caracterristicas do veiculo).
    os << "\n"
       << v.mark << " technical sheet (Ficha tecnica do " << v.mark << "):\n";
    os << "Engine: " << (v.engine ? "yes" : "no") << endl;
    os << "Wheels: " << v.wheels << endl;
    os << "MaxSpeed: " << v.maxSpeed << endl;
    return os;
  }
};