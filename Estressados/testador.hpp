#pragma once

#include <iostream>
#include <vector>

//Para imprimir os elementos do vector direto pelo fluxo de saída ("ostream").
std::ostream &operator<<(std::ostream &sai, const std::vector<int> &vet)
{
  sai << "[ ";
  for (auto i : vet)
  {
    sai << i << " ";
  }
  sai << "]\n";
  return sai;
}
