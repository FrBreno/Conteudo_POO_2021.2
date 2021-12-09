#include "../Car/car.hpp"

class F1 : public Car
{
  bool halo{true};             // dispositivo de segurança essencial atualemnte
  bool aerodynamics{true};     // aerodinamica
  string tireRange{"unknown"}; // gama de pneus
  string carNumber{"unknown"}; // N° do carro

public:
  F1(string brand, string color, bool halo, bool aero, string tire, string number);

  void setHalo(bool halo);
  bool isHalo() const;

  void setAero(bool aero);
  bool isAero() const;

  void setTire(string tire);
  string getTire() const;

  void setNumber(string number);
  string getNumber() const;

  bool it_is_a_car();
  bool competitive();
  void toDrive();

  friend ostream &operator<<(ostream &os, const F1 &f)
  {
    os << *(Car *)&f;
    os << "Halo: " << (f.halo ? "yes" : "no") << endl;
    os << "Aerodynamics: " << (f.aerodynamics ? "good" : "bad") << endl;
    os << "Tire range: " << f.tireRange << endl;
    os << "Car number: " << f.carNumber << endl;
    return os;
  }
};