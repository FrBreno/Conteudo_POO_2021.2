#include <iostream>
using namespace std;

auto soma(auto a, auto b)
{
  return a + b;
}

int main()
{

  std::cout << "Salve!\n";
  std::cout << soma(7, 6) << '\n';
  return 0;
}
