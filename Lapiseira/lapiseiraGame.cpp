#include <iostream>

struct GRAFITE
{
  float calibre{0.0f}; // Em mm
  int tamanho{0};      // Em mm
  std::string dureza{"NULL"};

  GRAFITE(float calibre = 0.0f, int tamanho = 0, std::string dureza = "NULL") : calibre{calibre}, tamanho{tamanho}, dureza{dureza}
  {
  }

  int desgastePorFolha()
  {
    if (dureza == "HB")
    {
      return 1;
    }
    else if (dureza == "2B")
    {
      return 2;
    }
    else if (dureza == "4B")
    {
      return 4;
    }
    else if (dureza == "6B")
    {
      return 6;
    }

    return 0;
  }

  std::string toString()
  {
    std::string aux = "Grafite: [" + std::to_string(this->calibre) + " : " + dureza + " : " + std::to_string(this->tamanho) + "]";
    return aux;
  }
};

struct LAPISEIRA
{
  float calibre{0.3f}; // Em mm.
  GRAFITE grafite;

  LAPISEIRA(float calibre = 0.3f) : calibre{calibre}
  {
  }

  bool inserir(GRAFITE grafite)
  {
    float calibre_grafite;
    int tamanho_grafite;
    std::string dureza_grafite;

    std::cin >> calibre_grafite >> dureza_grafite >> tamanho_grafite;

    if (calibre_grafite != this->calibre)
    {
      std::cout << "ERROR! Calibre incompativel\n";
      return false;
    }

    grafite.calibre = calibre_grafite;
    grafite.dureza = dureza_grafite;
    grafite.tamanho = tamanho_grafite;
    this->grafite = grafite;

    return true;
  }

  GRAFITE remover()
  {
    this->grafite.calibre = 0.0f;
    this->grafite.tamanho = 0;
    this->grafite.dureza = "NULL";

    return grafite;
  }

  bool write(int folhas)
  {
    int follhasEscritas{0};

    if (this->grafite.dureza == "NULL")
    {
      std::cout << "ERROR! Sem grafite na lapiseira\n";
      return false;
    }

    while (folhas > 0)
    {
      int desgaste = grafite.desgastePorFolha();

      if (this->grafite.tamanho == 0 || desgaste > this->grafite.tamanho)
      {

        std::cout << "Texto incompleto!\n";
        std::cout << follhasEscritas << " folhas foram escritas\n";

        std::cout << "\nCabou o grafite :/\n";
        remover();
        return false;
      }
      grafite.tamanho -= desgaste;

      follhasEscritas++;
      folhas--;
    }

    if (folhas == 0 && this->grafite.tamanho == 0)
    {
      std::cout << "\nCabou o grafite :/\n";
      remover();
      return false;
    }

    return true;
  }

  std::string toString()
  {
    std::string aux = "Calibre: " + std::to_string(this->calibre) + ", ";
    return aux;
  }
};

int main()
{
  int x{0};
  bool existe_grafite{false};
  int folhas{0};
  float calibre_lapiseira;

  std::cout << "Digite o calibre de sua lapiseira: ";
  std::cin >> calibre_lapiseira;

  LAPISEIRA lapiseira{calibre_lapiseira};

  while (x != 1)
  {
    if (existe_grafite)
    {
      std::string sn;
      std::cout << "Existe um grafite na lapiseira. Deseja remove-lo? [s/n]\n";
      std::cin >> sn;

      if (sn == "s")
      {
        lapiseira.remover();
        existe_grafite = false;
      }
    }
    if (!existe_grafite)
    {
      std::cout << "\nDigite o calibre, a dureza e o tamanho do grafite em mm (respectivamente): ";

      existe_grafite = lapiseira.inserir(lapiseira.grafite);
    }

    std::cout << "\nDigite a quantidade de folhas a serem escritas: ";
    std::cin >> folhas;
    existe_grafite = lapiseira.write(folhas);

    std::cout << "Tecle 1 para encerrar o programa ou 2 para continuar: ";
    std::cin >> x;
  }

  std::cout << lapiseira.toString() << lapiseira.grafite.toString() << '\n';
  return 0;
}