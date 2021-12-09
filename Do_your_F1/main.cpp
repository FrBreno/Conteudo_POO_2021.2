#include "F1/f1.hpp"

void vehicle(Vehicle &v)
{
  cout << v << endl;
  return;
}

void car(Car &c)
{
  cout << "It is a car? R->" << (c.verification() ? "yes" : "no") << endl;
  c.toDrive();
  cout << c << endl;
  return;
}

void f1(F1 &fOne)
{
  cout << "It is a F1? R->" << (fOne.verification() ? "yes" : "no") << endl;
  cout << "This F1 is competitive? R->" << (fOne.competitive() ? "yes" : "no") << endl;
  fOne.toDrive();
  cout << fOne << endl;
  return;
}

void visaoCar(Car &c)
{
  Vehicle &v = c;
  vehicle(v);
  return;
}

void visaoF1(F1 &fOne)
{
  Car &c = fOne;
  Vehicle &v = fOne;

  car(c);
  vehicle(v);
  return;
}

int main()
{
  Vehicle veiculo(false, 2, 100);
  Car carro(false, 3, 150, "Fiat", "Red");
  F1 fOne("Ferrari", "Red", true, true, "Soft", "16");

  // Trabalhando com cada classe individualmente:
  cout << "\nVEHICLE:\n";
  vehicle(veiculo);

  cout << "\nCAR:\n\n";
  car(carro);

  cout << "\nF1:\n\n";
  f1(fOne);

  // Trabalhando com a visão entre as classes herdeiras/herdadas:
  cout << "\nVISAO_CAR:\n";
  visaoCar(carro);

  cout << "\nVISAO_F1:\n\n";
  visaoF1(fOne);

  return 0;
}