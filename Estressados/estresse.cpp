#include <iostream>
#include <vector>
#include <algorithm>

//Busca:
bool existe(std::vector<int> fila, int x)
{
  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (fila[i] == x)
    {
      return true;
    }
  }
  return false;
}

int contar(std::vector<int> fila, int x)
{
  int cont = 0;
  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (fila[i] == x)
    {
      cont++;
    }
  }
  return cont;
}

int procurar_valor(std::vector<int> fila, int x)
{
  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (fila[i] == x)
    {
      return i;
    }
  }
  return -1;
}

int procurar_valor_apartir(std::vector<int> fila, int x, int inicio)
{
  for (int i = inicio; i < (int)fila.size(); i++)
  {
    if (fila[i] == x)
    {
      return i;
    }
  }
  return -1;
}

//Melhor caso:
int procurar_menor(std::vector<int> fila)
{
  sort(fila.begin(), fila.end());
  return fila[0];
}

int procurar_menor_pos(std::vector<int> fila)
{
  int menor = fila[0];
  int indice = 0;

  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (fila[i] < menor)
    {
      menor = fila[i];
      indice = i;
    }
  }
  return indice;
}

int procurar_menor_pos_apartir(std::vector<int> fila, int inicio)
{
  int menor = fila[inicio];
  int indice = inicio;

  for (int i = inicio; i < (int)fila.size(); i++)
  {
    if (fila[i] < menor)
    {
      menor = fila[i];
      indice = i;
    }
  }
  return indice;
}

int procurar_melhor_pos_se(std::vector<int> fila)
{
  int menor = 100;
  int indice = -1;

  for (int i = 0; i < (int)fila.size(); i++)
  {
    if ((fila[i] > 0) && (fila[i] < menor))
    {
      menor = fila[i];
      indice = i;
    }
  }

  return indice;
}

//Contagem:
float calcular_stress_medio(std::vector<int> fila)
{
  float soma = 0;
  float media = 0;

  for (int i = 0; i < (int)fila.size(); i++)
  {
    soma += abs(fila[i]);
  }

  media = soma / fila.size();
  return media;
}

std::string mais_homens_ou_mulheres(std::vector<int> fila)
{
  int compare = 0;

  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (fila[i] > 0)
    {
      compare++;
    }
    else
    {
      compare--;
    }
  }

  if (compare > 0)
  {
    return "homens";
  }
  else if (compare < 0)
  {
    return "mulheres";
  }

  return "empate";
}

std::string qual_metade_eh_mais_estressada(std::vector<int> fila)
{
  //OBS: Estou considerando que a quantidade de pessoas na fila seja um n° par.
  int tamanho_fila{};
  tamanho_fila = fila.size() / 2;

  int primeira = 0;
  int segunda = 0;

  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (i < tamanho_fila)
    {
      primeira += abs(fila[i]);
    }
    else
    {
      segunda += abs(fila[i]);
    }
  }

  if (primeira > segunda)
  {
    return "primeira";
  }
  else if (segunda > primeira)
  {
    return "segunda";
  }

  return "empate";
}

std::string homens_sao_mais_estressados_que_mulheres(std::vector<int> fila)
{
  float estresse_homens = 0;
  int size_homens = 0;
  float media_homens = 0;

  float estresse_mulheres = 0;
  int size_mulheres = 0;
  float media_mulheres;

  for (int i = 0; i < (int)fila.size(); i++)
  {
    if (fila[i] > 0)
    {
      estresse_homens += abs(fila[i]);
      size_homens++;
    }
    else if (fila[i] < 0)
    {
      estresse_mulheres += abs(fila[i]);
      size_mulheres++;
    }
  }

  media_homens = estresse_homens / size_homens;
  media_mulheres = estresse_mulheres / size_mulheres;

  if (media_homens > media_mulheres)
  {
    return "Os homens estao mais estressados (media de estresse dos homens maior)";
  }
  else if (media_mulheres > media_homens)
  {
    return "As mulheres estao mais estressadas (media de estresse das mulheres maior)";
  }

  return "Os homens e as mulheres estao igualmente estressados (mesma media de estresse)";
}

int main()
{
  //A seguir, alguns casos de teste para as funções acima.

  //Busca - testes:
  std::cout << "Testes - funcao existe:\n";
  std::cout << existe({-1, -50, -99}, -1) << '\n';
  std::cout << existe({-1, -50, -99}, 10) << "\n\n";

  std::cout << "Testes - funcao contar:\n";
  std::cout << contar({-1, -50, -1, -99}, -1) << '\n';
  std::cout << contar({-1, -50, -1, -99}, 10) << "\n\n";

  std::cout << "Testes - funcao procurar_valor:\n";
  std::cout << procurar_valor({-1, -50, -1, -99}, -50) << '\n';
  std::cout << procurar_valor({-1, -50, -1, -99}, 10) << "\n\n";

  std::cout << "Testes - funcao procurar_valor_apartir:\n";
  std::cout << procurar_valor_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << '\n';
  std::cout << procurar_valor_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << '\n';
  std::cout << procurar_valor_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << "\n\n";

  //Melhro caso - testes:
  std::cout << "Testes - funcao procurar_menor:\n";
  std::cout << procurar_menor({5, 3, -1, -50, -1, -99}) << '\n';
  std::cout << procurar_menor({5, -3, -1, -25, 1, -70}) << "\n\n";

  std::cout << "Testes - funcao procurar_menor_pos:\n";
  std::cout << procurar_menor_pos({5, 3, -1, -50, -1, -99}) << '\n';
  std::cout << procurar_menor_pos({-99, 3, -1, -50, -1, 5}) << '\n';
  std::cout << procurar_menor_pos({-50, 3, -1, -99, -1, 5}) << "\n\n";

  std::cout << "Testes - funcao procurar_menor_pos_apartir:\n";
  std::cout << procurar_menor_pos_apartir({5, 3, -1, -50, -1, 10}, 3) << '\n';
  std::cout << procurar_menor_pos_apartir({-50, 3, -1, 5, -1, 10}, 3) << '\n';
  std::cout << procurar_menor_pos_apartir({-50, 3, -1, 5, -1, 10}, 1) << "\n\n";

  std::cout << "Testes - funcao procurar_melhor_pos_se:\n";
  std::cout << procurar_melhor_pos_se({5, 3, -1, -50, -1, -99}) << '\n';
  std::cout << procurar_melhor_pos_se({-1, -50, -1, -99}) << '\n';
  std::cout << procurar_melhor_pos_se({-99, 5, -1, -50, -1, 3}) << "\n\n";

  //Contagem - testes:
  std::cout << "Testes - funcao calcular_stress_medio:\n";
  std::cout << calcular_stress_medio({5, -8, -50, -75, 20, 35}) << '\n';
  std::cout << calcular_stress_medio({3, -4, -25, -47, -20, 35}) << '\n';
  std::cout << calcular_stress_medio({-3, -4, -25, -47, -20, -35}) << "\n\n";

  std::cout << "Testes - funcao mais_homens_ou_mulheres:\n";
  std::cout << mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99}) << '\n';
  std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99}) << '\n';
  std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99}) << "\n\n";

  std::cout << "Testes - funcao qual_metade_eh_mais_estressada:\n";
  std::cout << qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99}) << '\n';
  std::cout << qual_metade_eh_mais_estressada({50, 98, 2, -50, -1, -99}) << '\n';
  std::cout << qual_metade_eh_mais_estressada({-51, 99, 1, -50, -1, -99}) << "\n\n";

  std::cout << "Testes - funcao homens_sao_mais_estressados_que_mulheres:\n";
  std::cout << homens_sao_mais_estressados_que_mulheres({50, 98, 2, -50, -1, -99}) << '\n';
  std::cout << homens_sao_mais_estressados_que_mulheres({52, 98, 2, -50, -1, -99}) << '\n';
  std::cout << homens_sao_mais_estressados_que_mulheres({50, 98, 2, -79, -1, -99}) << '\n';

  return 0;
}