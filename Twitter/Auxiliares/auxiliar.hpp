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

// Mesma funcionalidade da função acima, mas trabalhando com vetor de ponteiros:
template <typename T>
std::string vec_ptr_to_string(std::vector<T> v, char delim)
{
  std::stringstream ss;
  for (auto t : v)
  {
    ss << *t << delim;
  }
  return ss.str();
}
