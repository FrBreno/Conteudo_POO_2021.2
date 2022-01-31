#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "testador.hpp"

//FILTER:
std::vector<int> clone(const std::vector<int> &vet)
{
  std::vector<int> control_c{};
  for (auto &i : vet)
  {
    control_c.push_back(i);
  }
  return control_c;
}

std::vector<int> pegar_homens(const std::vector<int> &vet)
{
  std::vector<int> men{};
  for (auto &i : vet)
  {
    if (i > 0)
    {
      men.push_back(i);
    }
  }
  return men;
}

std::vector<int> pegar_calmos(const std::vector<int> &vet)
{
  std::vector<int> calmos{};
  for (int i{0}; i < (int)vet.size(); i++)
  {
    int aux{vet[i]};
    if (abs(aux) < 10)
    {
      calmos.push_back(aux);
    }
  }
  return calmos;
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int> &vet)
{
  std::vector<int> mulheres_calmas{};

  for (int i{0}; i < (int)vet.size(); i++)
  {
    if (vet[i] < 0 && vet[i] > -10)
    {
      mulheres_calmas.push_back(vet[i]);
    }
  }
  return mulheres_calmas;
}

//ACESSO:
std::vector<int> inverter_com_copia(const std::vector<int> &vet)
{
  std::vector<int> copia{};

  for (int i{(int)vet.size() - 1}; i >= 0; i--)
  {
    copia.push_back(vet[i]);
  }
  return copia;
}

void inverter_inplace(std::vector<int> &vet)
{
  std::reverse(vet.begin(), vet.end());
  return;
}

int sortear(const std::vector<int> &vet)
{
  std::srand(std::time(0));
  int posicao = rand() % vet.size();
  return vet[posicao];
}

void embaralhar(std::vector<int> &vet)
{
  int vet_size{(int)vet.size()};
  std::vector<int> aux{};
  std::srand(std::time(0));

  for (int i{0}; i < vet_size; i++)
  {
    int posicao = rand() % (int)vet.size();
    aux.push_back(vet[posicao]);
    vet.erase(vet.begin() + posicao);
  }
  vet = aux;
  //std::cout << vet;
  return;
}

void ordenar(std::vector<int> &vet)
{
  //Selection sort:
  bool troca{};
  int menor_elemento{0};
  int posicao_menor_elemento{0};

  for (int i{0}; i < (int)vet.size() - 1; i++)
  {
    troca = false; //Ainda não iniciou o processo de troca.
    menor_elemento = vet[i];
    posicao_menor_elemento = i;

    for (int j{i + 1}; j < (int)vet.size(); j++) //percorre todo vector a partir do ultimo elemento verificado (o menor até então).
    {
      if (vet[j] < menor_elemento)
      {
        troca = true; //Troca em andamento
        menor_elemento = vet[j];
        posicao_menor_elemento = j;
      }
    }
    if (troca) //Toca em andamento? faz a troca : não faz a troca
    {
      int aux = vet[i];
      vet[i] = menor_elemento;
      vet[posicao_menor_elemento] = aux;
    }
  }
  return;
}

//CONJUNTOS:
std::vector<int> exclusivos(const std::vector<int> &vet)
{
  bool repeticao{};
  std::vector<int> privilegiados{};
  privilegiados.push_back(vet[0]);

  for (int i{1}; i < (int)vet.size(); i++)
  {
    repeticao = false;

    for (int j{0}; j < (int)privilegiados.size(); j++)
    {
      if (privilegiados[j] == vet[i]) //Caso hája do elemento em questão repetição
      {
        repeticao = true;
        break;
      }
    }

    if (!repeticao) //Se não houver repetição do elmento analisado:
    {
      privilegiados.push_back(vet[i]);
    }
  }
  return privilegiados;
}

std::vector<int> diferentes(const std::vector<int> &vet)
{
  std::vector<int> stress_nivel = vet;
  std::vector<int> retorno{};

  for (int i{0}; i < (int)stress_nivel.size(); i++)
  {
    if (stress_nivel[i] < 0)
    {
      stress_nivel[i] *= -1;
    }
  }

  retorno = exclusivos(stress_nivel);
  return retorno;
}

std::vector<int> abandonados(const std::vector<int> &vet)
{
  bool repetido{};
  std::vector<int> removidos{vet[0]};
  std::vector<int> excluidos{};

  for (int i{1}; i < (int)vet.size(); i++)
  {
    repetido = false;
    for (int j{0}; j < (int)removidos.size(); j++)
    {
      if (vet[i] == removidos[j])
      {
        repetido = true;
        break;
      }
    }

    if (!repetido)
    {
      removidos.push_back(vet[i]);
    }
    else if (repetido)
    {
      excluidos.push_back(vet[i]);
    }
  }
  return excluidos;
}

//FILTER_TESTES:
void clone_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << clone(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << clone(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << clone(fila03) << '\n';
  return;
}

void pegar_homens_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << pegar_homens(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << pegar_homens(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << pegar_homens(fila03) << '\n';

  return;
}

void pegar_calmos_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << pegar_calmos(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << pegar_calmos(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << pegar_calmos(fila03) << '\n';

  return;
}

void pegar_mulheres_calmas_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << pegar_mulheres_calmas(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << pegar_mulheres_calmas(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << pegar_mulheres_calmas(fila03) << '\n';

  return;
}

//ACESSO_TESTES:
void inverter_com_copia_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << inverter_com_copia(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << inverter_com_copia(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << inverter_com_copia(fila03) << '\n';

  return;
}

void inverter_inplace_testes(std::vector<int> &fila01, std::vector<int> &fila02, std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  inverter_inplace(fila01);
  std::cout << "Saida: " << fila01 << '\n';
  std::cout << "Entrada: " << fila02;
  inverter_inplace(fila02);
  std::cout << "Saida: " << fila02 << '\n';
  std::cout << "Entrada: " << fila03;
  inverter_inplace(fila03);
  std::cout << "Saida: " << fila03 << '\n';

  return;
}

void sortear_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << sortear(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << sortear(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << sortear(fila03) << '\n';
  return;
}

void embaralhar_testes(std::vector<int> &fila01, std::vector<int> &fila02, std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  embaralhar(fila01);
  std::cout << "Saida: " << fila01 << '\n';
  std::cout << "Entrada: " << fila02;
  embaralhar(fila02);
  std::cout << "Saida: " << fila02 << '\n';
  std::cout << "Entrada: " << fila03;
  embaralhar(fila03);
  std::cout << "Saida: " << fila03 << '\n';

  return;
}

void ordenar_testes(std::vector<int> &fila01, std::vector<int> &fila02, std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  ordenar(fila01);
  std::cout << "Saida: " << fila01 << '\n';
  std::cout << "Entrada: " << fila02;
  ordenar(fila02);
  std::cout << "Saida: " << fila02 << '\n';
  std::cout << "Entrada: " << fila03;
  ordenar(fila03);
  std::cout << "Saida: " << fila03 << '\n';

  return;
}

//CONJUNTO_TESTES:
void exclusivos_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << exclusivos(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << exclusivos(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << exclusivos(fila03) << '\n';

  return;
}

void diferentes_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << diferentes(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << diferentes(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << diferentes(fila03) << '\n';

  return;
}

void abandonados_testes(const std::vector<int> &fila01, const std::vector<int> &fila02, const std::vector<int> &fila03)
{
  std::cout << "Entrada: " << fila01;
  std::cout << "Saida: " << abandonados(fila01) << '\n';
  std::cout << "Entrada: " << fila02;
  std::cout << "Saida: " << abandonados(fila02) << '\n';
  std::cout << "Entrada: " << fila03;
  std::cout << "Saida: " << abandonados(fila03) << '\n';

  return;
}

int main()
{
  std::vector<int> fila1{-1, -7, -15, -23, -31, -48, -88, -53, -93, 4, 7, 15, 27, 33, 47, 51, 99, 43};
  std::vector<int> fila2{1, 3, 4, 3, -1, -2, -2};
  std::vector<int> fila3{5, -3, -1, 3, -50, 50, 1, -99, 5, 3, 10, 33, -18, 28, 40, -55};

  //OBS: Tire as funções abaixo dos comentários para realizar os testes.

  //FILTER_TESTES:
  //clone_testes(fila1, fila2, fila3);
  //pegar_homens_testes(fila1, fila2, fila3);
  //pegar_calmos_testes(fila1, fila2, fila3);
  //pegar_mulheres_calmas_testes(fila1, fila2, fila3);

  //ACESSO_TESTES:
  //inverter_com_copia_testes(fila1, fila2, fila3);
  //inverter_inplace_testes(fila1, fila2, fila3);
  //sortear_testes(fila1, fila2, fila3);
  //embaralhar_testes(fila1, fila2, fila3);
  //ordenar_testes(fila1, fila2, fila3);

  //CONJUNTO_TESTES:
  //exclusivos_testes(fila1, fila2, fila3);
  //diferentes_testes(fila1, fila2, fila3);
  //abandonados_testes(fila1, fila2, fila3);

  return 0;
}