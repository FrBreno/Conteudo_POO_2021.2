#include <iostream>
#include <sstream>
#include <vector>
#include <map>

// Quebra um texto em um vetor de strings:
std::vector<std::string> split(std::string s, char delim)
{
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string token;
  while (std::getline(ss, token, delim))
  {
    result.push_back(token);
  }
  return result;
}

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

// Transforma um dado qualquer em string:
template <typename T>
std::string value_to_string(T t)
{
  std::stringstream ss;
  ss << t;
  return ss.str();
}

// Transforma os elementos de um vetor em string, separados por um delimitador:
template <typename T>
std::string vec_to_string(std::vector<T> v, char delim)
{
  std::stringstream ss;
  for (auto t : v)
  {
    ss << t << delim;
  }
  return ss.str();
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

// Jogar os dados de um map em um vetor:
template <typename T>
std::vector<T> map_values(std::map<std::string, T> &m)
{
  std::vector<T> result;
  for (auto pair : m)
  {
    result.push_back(pair.second);
  }
  return result;
}