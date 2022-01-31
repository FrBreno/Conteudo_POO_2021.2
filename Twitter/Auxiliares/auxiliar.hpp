#include <iostream>
#include <sstream>
#include <vector>

// Ler um dado qualquer de um fluxo:
template <typename T>
T read(std::stringstream &ss)
{
  T dado;
  ss >> dado;
  return dado;
}

template <typename T>
T read_str(std::stringstream &ss)
{
  int cont{0};
  T dado;
  T aux;
  while (ss >> aux)
  {
    if (cont != 0)
    {
      dado += " ";
    }
    dado += aux;
    cont++;
  }

  return dado;
}
