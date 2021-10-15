#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "testador.hpp"

// MAP:
std::vector<int> sozinhos(const std::vector<int> &vet)
{
  std::vector<int> aux{};
  bool repete{false};

  for (int i{0}; i < (int)vet.size() - 1; i++)
  {
    repete = false;
    for (int j{0}; j < (int)vet.size(); j++)
    {
      if (i != j && abs(vet[i]) == abs(vet[j]))
      {
        repete = true;
        break;
      }
    }

    if (!repete)
    {
      aux.push_back(vet[i]);
    }
  }
  return aux;
}

int mais_ocorrencias(const std::vector<int> &vet)
{
  int ocorrencias{1};

  for (int i{0}; i < (int)vet.size() - 1; i++)
  {
    int cont_repet{1};
    for (int j{i + 1}; j < (int)vet.size(); j++)
    {
      if (abs(vet[i]) == abs(vet[j]))
      {
        cont_repet++;
      }
    }
    if (cont_repet > ocorrencias)
    {
      ocorrencias = cont_repet;
    }
  }

  return ocorrencias;
}

std::vector<int> mais_recorrentes(const std::vector<int> &vet)
{
  std::vector<int> recorrencias{};
  int n_recorrencias{1};

  for (int i{0}; i < (int)vet.size() - 1; i++)
  {
    int repeticoes{1};
    for (int j{i + 1}; j < (int)vet.size(); j++)
    {
      if (abs(vet[i]) == abs(vet[j]))
      {
        repeticoes++;
      }
    }
    if (repeticoes > n_recorrencias)
    {
      n_recorrencias = repeticoes;
      recorrencias.clear();
      recorrencias.push_back(abs(vet[i]));
    }
    else if (repeticoes == n_recorrencias)
    {
      recorrencias.push_back(abs(vet[i]));
    }
  }

  return recorrencias;
}

// PROXIMIDADE:
int briga(const std::vector<int> &vet)
{
  int n_brigas{0};

  for (int i{1}; i < (int)vet.size() - 1; i++)
  {
    if (abs(vet[i]) > 50 && abs(vet[i - 1]) > 30 && abs(vet[i + 1]) > 30)
    {
      n_brigas++;
    }
  }

  return n_brigas;
}

std::vector<int> apaziguado(const std::vector<int> &vet)
{
  std::vector<int> pos_apaziguados{};

  for (int i{0}; i < (int)vet.size(); i++)
  {
    if (abs(vet[i]) > 80 && (abs(vet[i - 1]) < 10 || abs(vet[i + 1]) < 10))
    {
      pos_apaziguados.push_back(i);
    }
  }

  return pos_apaziguados;
}

// SEQUÊNCIAS:
std::vector<int> funcao_geral_sequencias(const std::vector<int> &vet, std::vector<int> &grupos)
{
  // Esta função armazena no vector "grupos" o número de pessoas do mesmo sexo que aparecem em sequência.
  int conta_grupos{0};
  std::vector<int> aux{}; // Converte os números negativos em 0 (feminino) e os positivos em 1 (masculina) -> Isso facilitará a análise.
  grupos.clear();

  for (int i{0}; i < (int)vet.size(); i++)
  {
    if (vet[i] > 0)
    {
      aux.push_back(1);
    }
    else if (vet[i] < 0)
    {
      aux.push_back(0);
    }
  }

  // Contagem das sequências:
  for (int i{0}; i < (int)aux.size(); i++)
  {
    conta_grupos++;
    if (aux[i] != aux[i + 1] && i != (int)aux.size() - 1)
    {
      grupos.push_back(conta_grupos);
      conta_grupos = 0;
    }
  }
  // Análise do último elemento:
  if (aux[(int)aux.size() - 1] != aux[aux.size() - 2])
  {
    grupos.push_back(1);
  }
  else
  {
    grupos.push_back(conta_grupos);
  }

  return grupos;
}

int quantos_times(const std::vector<int> &vet, std::vector<int> &grupos)
{
  int n_times{0};
  std::vector<int> aux{};
  aux = funcao_geral_sequencias(vet, grupos);

  // Contagem de todos os grupos de pessoas do mesmo sexo com mais de uma pessoa inserida:
  for (int i{0}; i < (int)aux.size(); i++)
  {
    if (aux[i] > 1)
    {
      n_times++;
    }
  }

  return n_times;
}

void maior_time(const std::vector<int> &vet, std::vector<int> &grupos)
{
  int maior{0};
  int indice_maior{0};
  int nao_tem_time{-1};
  int repet_maior{0};
  std::vector<int> aux{};
  aux = funcao_geral_sequencias(vet, grupos);

  for (int i{0}; i < (int)aux.size(); i++)
  {
    if (aux[i] == 1)
    {
      nao_tem_time++;
    }
    if (aux[i] != 1 && aux[i] > maior)
    {
      maior = aux[i];
      indice_maior = i - nao_tem_time;
    }
    else if (aux[i] != 1 && aux[i] == maior)
    {
      repet_maior = maior;
    }
  }

  if (maior == 0)
  {
    std::cout << "Nao foi possivel formar times :/\n\n";
    return;
  }
  if (maior == repet_maior)
  {
    std::cout << "Nao houve um unico time maior, e sim alguns times maiores com " << repet_maior << " pessoas cada.\n\n";
    return;
  }

  std::cout << "O " << indice_maior << "* time e o maior com " << maior << " pessoas.\n\n";
  return;
}

int sozinhos_times(const std::vector<int> &vet, std::vector<int> &grupos)
{
  int sozinhos{0};
  std::vector<int> aux{};
  aux = funcao_geral_sequencias(vet, grupos);

  for (int i{0}; i < (int)aux.size(); i++)
  {
    if (aux[i] == 1)
    {
      sozinhos++;
    }
  }

  return sozinhos;
}

// GRUPOS:
int casais(const std::vector<int> &vet)
{
  int n_casais{0};
  std::vector<int> homens{};
  std::vector<int> mulheres{};

  for (int i{0}; i < (int)vet.size(); i++)
  {
    if (vet[i] > 0)
    {
      homens.push_back(vet[i]);
    }
    else
    {
      mulheres.push_back(abs(vet[i]));
    }
  }

  for (int i{0}; i < (int)mulheres.size(); i++)
  {
    int buffer{0};
    for (int j{0}; j < (int)homens.size(); j++)
    {
      if (mulheres[i] == homens[j])
      {
        n_casais++;
        homens[j] = 0;
        break;
      }
      else if (homens[j] == 0)
      {
        buffer++;
      }
    }
    if (buffer == (int)homens.size())
    {
      break;
    }
  }
  return n_casais;
}

int trios(const std::vector<int> &vet)
{
  int n_trios{0};
  std::vector<int> clone{};

  for (int i{0}; i < (int)vet.size(); i++)
  {
    clone.push_back(abs(vet[i]));
  }

  sort(clone.begin(), clone.end());

  for (int i{0}; i < (int)clone.size() - 2; i++)
  {
    if (clone[i] == clone[i + 1] && clone[i + 1] == clone[i + 2])
    {
      n_trios++;
      i += 2;
    }
  }
  return n_trios;
}

// ALTERAÇÕES:
std::vector<int> remove(std::vector<int> &vet, int x)
{
  int indice{-1};
  for (int i{0}; i < (int)vet.size(); i++)
  {
    if (vet[i] == x)
    {
      indice = i;
      break;
    }
  }
  if (indice == -1) // Caso o elemento x não pertença a fila.
  {
    return vet;
  }

  vet.erase(vet.begin() + indice);
  return vet;
}

std::vector<int> insert(std::vector<int> &vet, int x, int y)
{
  std::vector<int> copia{};
  for (int i{0}; i < y; i++)
  {
    copia.push_back(vet[i]);
  }
  copia.push_back(x);
  for (int i{y}; i < (int)vet.size(); i++)
  {
    copia.push_back(vet[i]);
  }
  vet.clear();
  vet = copia;
  return vet;
}

std::vector<int> dance(std::vector<int> &vet)
{
  int indice{0};
  std::vector<int> fila_vazia{};
  bool retira_proximo{false};
  bool retira_anterior{false};

  while (indice < (int)vet.size())
  {
    if ((int)vet.size() == 2)
    {
      if (vet[0] == vet[1])
      {
        vet.clear();
        vet = fila_vazia;
        return vet;
      }
    }
    if (retira_anterior)
    {
      indice--;
      vet.erase(vet.begin() + indice);
      retira_anterior = false;
    }
    else if (retira_proximo)
    {
      vet.erase(vet.begin() + indice);
      retira_proximo = false;
    }
    else if (abs(vet[indice]) == abs(vet[indice - 1]) && indice != 0)
    {
      vet.erase(vet.begin() + indice);
      retira_anterior = true;
    }
    else if (abs(vet[indice]) == abs(vet[indice + 1]) && indice != (int)vet.size() - 1)
    {
      vet.erase(vet.begin() + indice);
      retira_proximo = true;
    }
    else
    {
      indice++;
    }
  }

  return vet;
}

// TESTES:

// TESTES_MAP:
void sozinhos_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, const std::vector<int> &vet6)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << sozinhos(vet1) << '\n';

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << sozinhos(vet2) << '\n';

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << sozinhos(vet3) << '\n';

  std::cout << "Entrada: " << vet4;
  std::cout << "Saida: " << sozinhos(vet4) << '\n';

  std::cout << "Entrada: " << vet5;
  std::cout << "Saida: " << sozinhos(vet5) << '\n';

  std::cout << "Entrada: " << vet6;
  std::cout << "Saida: " << sozinhos(vet6) << '\n';
  return;
}

void mais_ocorrencias_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, const std::vector<int> &vet6)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << mais_ocorrencias(vet1) << "\n\n";

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << mais_ocorrencias(vet2) << "\n\n";

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << mais_ocorrencias(vet3) << "\n\n";

  std::cout << "Entrada: " << vet4;
  std::cout << "Saida: " << mais_ocorrencias(vet4) << "\n\n";

  std::cout << "Entrada: " << vet5;
  std::cout << "Saida: " << mais_ocorrencias(vet5) << "\n\n";

  std::cout << "Entrada: " << vet6;
  std::cout << "Saida: " << mais_ocorrencias(vet6) << "\n\n";
  return;
}

void mais_recorrentes_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, const std::vector<int> &vet6)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << mais_recorrentes(vet1) << '\n';

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << mais_recorrentes(vet2) << '\n';

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << mais_recorrentes(vet3) << '\n';

  std::cout << "Entrada: " << vet4;
  std::cout << "Saida: " << mais_recorrentes(vet4) << '\n';

  std::cout << "Entrada: " << vet5;
  std::cout << "Saida: " << mais_recorrentes(vet5) << '\n';

  std::cout << "Entrada: " << vet6;
  std::cout << "Saida: " << mais_recorrentes(vet6) << '\n';

  return;
}

// TESTES_PROXIMIDADE:
void briga_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3)
{
  std::vector<int> aaa{50, -98, 31, -51, 31, -99};
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << briga(vet1) << " brigas diferentes\n\n";

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << briga(vet2) << " brigas diferentes\n\n";

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << briga(vet3) << " brigas diferentes\n\n";

  std::cout << "Entrada: " << aaa;
  std::cout << "Saida: " << briga(aaa) << " brigas diferentes\n\n";

  return;
}

void apaziguado_teste(const std::vector<int> &vet1, const std::vector<int> &vet2)
{
  std::vector<int> vet3{83, -4, 65, 8, -99, 12};

  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << apaziguado(vet1) << '\n';

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << apaziguado(vet2) << '\n';

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << apaziguado(vet3) << '\n';

  return;
}

// TESTES_SEQUÊNCIA:
void quantos_times_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, std::vector<int> &grupos)
{
  std::vector<int> vet6{-5, 1, -3, 5, -10, 11};

  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << quantos_times(vet1, grupos) << " times\n\n";

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << quantos_times(vet2, grupos) << " times\n\n";

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << quantos_times(vet3, grupos) << " times\n\n";

  std::cout << "Entrada: " << vet4;
  std::cout << "Saida: " << quantos_times(vet4, grupos) << " times\n\n";

  std::cout << "Entrada: " << vet5;
  std::cout << "Saida: " << quantos_times(vet5, grupos) << " times\n\n";

  std::cout << "Entrada: " << vet6;
  std::cout << "Saida: " << quantos_times(vet6, grupos) << " times\n\n";

  return;
}

void maior_time_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, std::vector<int> &grupos)
{
  std::vector<int> vet6{-5, 1, -3, 5, -10, 11};
  std::vector<int> vet7{-5, -1, 3, 5, -10, -11};

  std::cout << "\nEntrada: " << vet1;
  maior_time(vet1, grupos);

  std::cout << "Entrada: " << vet2;
  maior_time(vet2, grupos);

  std::cout << "Entrada: " << vet3;
  maior_time(vet3, grupos);

  std::cout << "Entrada: " << vet4;
  maior_time(vet4, grupos);

  std::cout << "Entrada: " << vet5;
  maior_time(vet5, grupos);

  std::cout << "Entrada: " << vet6;
  maior_time(vet6, grupos);

  std::cout << "Entrada: " << vet7;
  maior_time(vet7, grupos);

  return;
}

void sozinhos_times_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, std::vector<int> &grupos)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << sozinhos_times(vet1, grupos) << "\n\n";

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << sozinhos_times(vet2, grupos) << "\n\n";

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << sozinhos_times(vet3, grupos) << "\n\n";

  std::cout << "Entrada: " << vet4;
  std::cout << "Saida: " << sozinhos_times(vet4, grupos) << "\n\n";

  std::cout << "Entrada: " << vet5;
  std::cout << "Saida: " << sozinhos_times(vet5, grupos) << "\n\n";
  return;
}

// TESTES_GRUPOS:
void casais_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, const std::vector<int> &vet6)
{
  std::vector<int> vet7{-1, -2, -3, -4};
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << casais(vet1) << "\n\n";

  std::cout << "Entrada: " << vet2;
  std::cout << "Saida: " << casais(vet2) << "\n\n";

  std::cout << "Entrada: " << vet3;
  std::cout << "Saida: " << casais(vet3) << "\n\n";

  std::cout << "Entrada: " << vet4;
  std::cout << "Saida: " << casais(vet4) << "\n\n";

  std::cout << "Entrada: " << vet5;
  std::cout << "Saida: " << casais(vet5) << "\n\n";

  std::cout << "Entrada: " << vet6;
  std::cout << "Saida: " << casais(vet6) << "\n\n";

  std::cout << "Entrada: " << vet7;
  std::cout << "Saida: " << casais(vet7) << "\n\n";

  return;
}

void trios_teste(const std::vector<int> &vet1, const std::vector<int> &vet2, const std::vector<int> &vet3, const std::vector<int> &vet4, const std::vector<int> &vet5, const std::vector<int> &vet6)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << trios(vet1) << "\n";

  std::cout << "\nEntrada: " << vet2;
  std::cout << "Saida: " << trios(vet2) << "\n";

  std::cout << "\nEntrada: " << vet3;
  std::cout << "Saida: " << trios(vet3) << "\n";

  std::cout << "\nEntrada: " << vet4;
  std::cout << "Saida: " << trios(vet4) << "\n";

  std::cout << "\nEntrada: " << vet5;
  std::cout << "Saida: " << trios(vet5) << "\n";

  std::cout << "\nEntrada: " << vet6;
  std::cout << "Saida: " << trios(vet6) << "\n";

  return;
}

// TESTES_ALTERAÇÃO:
void remove_teste(std::vector<int> &vet1, std::vector<int> &vet2, std::vector<int> &vet3, std::vector<int> &vet4, std::vector<int> &vet5, std::vector<int> &vet6)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << remove(vet1, -3) << "\n";

  std::cout << "\nEntrada: " << vet2;
  std::cout << "Saida: " << remove(vet2, 1) << "\n";

  std::cout << "\nEntrada: " << vet3;
  std::cout << "Saida: " << remove(vet3, 5) << "\n";

  std::cout << "\nEntrada: " << vet4;
  std::cout << "Saida: " << remove(vet4, -51) << "\n";

  std::cout << "\nEntrada: " << vet5;
  std::cout << "Saida: " << remove(vet5, -31) << "\n";

  std::cout << "\nEntrada: " << vet6;
  std::cout << "Saida: " << remove(vet6, 40) << "\n";

  return;
}

void insert_teste(std::vector<int> &vet1, std::vector<int> &vet2, std::vector<int> &vet3, std::vector<int> &vet4, std::vector<int> &vet5, std::vector<int> &vet6)
{
  std::cout << "\nEntrada: " << vet1;
  std::cout << "Saida: " << insert(vet1, 1, 0) << '\n';

  std::cout << "\nEntrada: " << vet2;
  std::cout << "Saida: " << insert(vet2, 3, 1) << '\n';

  std::cout << "\nEntrada: " << vet3;
  std::cout << "Saida: " << insert(vet3, 3, 5) << '\n';

  std::cout << "\nEntrada: " << vet4;
  std::cout << "Saida: " << insert(vet4, 99, 7) << '\n';

  std::cout << "\nEntrada: " << vet5;
  std::cout << "Saida: " << insert(vet5, -85, 0) << '\n';

  std::cout << "\nEntrada: " << vet6;
  std::cout << "Saida: " << insert(vet6, -85, 4) << '\n';

  return;
}

void dance_teste()
{
  std::vector<int> fila1{1, 5, 4, 5, -3, 3, -5, 2, 3, -3};
  std::vector<int> fila2{1, 2, 3, 4, 5, -5, -4, 3, -2, 1};
  std::vector<int> fila3{1, 2, 3, 4, 5, -7, -4, 3, -2, 1};
  std::vector<int> fila4{1, 5, 4, 3, -1, -5, -5, 3, -3, -4};

  std::cout << "\nEntrada: " << fila1;
  std::cout << "Saida: " << dance(fila1) << '\n';

  std::cout << "Entrada: " << fila2;
  std::cout << "Saida: " << dance(fila2) << '\n';

  std::cout << "Entrada: " << fila3;
  std::cout << "Saida: " << dance(fila3) << '\n';

  std::cout << "Entrada: " << fila4;
  std::cout << "Saida: " << dance(fila4) << '\n';

  return;
}

int main()
{
  std::vector<int> fila1{1, 3, 4, 3, -1, -3, -3};
  std::vector<int> fila2{1, 3, 4, 5, -1, -5, -5};
  std::vector<int> fila3{1, 5, 4, 3, -1, -5, -5, 3, -3, -4};
  std::vector<int> fila4{5, -3, -1, 31, -51, 50, -55, -99, 45, 3, 10, 33, -18, 28, 40, -55};
  std::vector<int> fila5{-31, -51, -31, -51, -31, 51, 31, 51, -51, -51};
  std::vector<int> fila6{5, -83, -81, 81, -51, 85, -55, -99, 5, 3, 10, 93, -8, -98, 40, -55};

  std::vector<int> times{};

  // PARA TESTAR, DESFAÇA ALGUM DOS COMENTÁRIOS ABAIXO PARA CHAMAR A FUNÇÃO DE TESTE DESEJADA.

  // TESTES_MAP:
  // sozinhos_teste(fila1, fila2, fila3, fila4, fila5, fila6);
  // mais_ocorrencias_teste(fila1, fila2, fila3, fila4, fila5, fila6);
  // mais_recorrentes_teste(fila1, fila2, fila3, fila4, fila5, fila6);

  // TESTES_PROXIMIDADE:
  // briga_teste(fila4, fila5, fila6);
  // apaziguado_teste(fila4, fila6);

  // TESTES_SEQUÊNCIA:
  // quantos_times_teste(fila1, fila3, fila4, fila5, fila6, times);
  // maior_time_teste(fila1, fila3, fila4, fila5, fila6, times);
  // sozinhos_times_teste(fila1, fila3, fila4, fila5, fila6, times);

  // TESTES_GRUPOS:
  // casais_teste(fila1, fila2, fila3, fila4, fila5, fila6);
  // trios_teste(fila1, fila2, fila3, fila4, fila5, fila6);

  // TESTES_ALTERAÇÃO
  // remove_teste(fila1, fila2, fila3, fila4, fila5, fila6);
  // insert_teste(fila1, fila2, fila3, fila4, fila5, fila6);
  // dance_teste();

  return 0;
}
