#include <iostream>
#include <sstream>
#include <vector>

// Ler um dado qualquer de um fluxo:
template <typename T>
T read(std::stringstream &ss)
{
  T dado{};
  ss >> dado;
  return dado;
}

// Substitui, em uma string, o char delim pelo char ' ';
void divide_str(std::string &s, char delim)
{
  for (int i{0}; i < (int)s.length(); i++)
  {
    if (s[i] == delim)
    {
      s[i] = ' ';
    }
  }
  return;
}
