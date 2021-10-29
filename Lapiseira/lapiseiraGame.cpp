#include <iostream>
#include <sstream>
#include <vector>

struct GRAFITE
{
  float calibre; // Em mm
  int tamanho;   // Em mm
  std::string dureza;

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
  float calibre; // Em mm.
  GRAFITE *grafite = nullptr;

  LAPISEIRA(float calibre = 0.3f) : calibre{calibre}
  {
  }

  bool inserir(GRAFITE *grafite)
  {
    if (grafite->calibre != this->calibre)
    {
      std::cout << "ERROR! Calibre incompativel\n";
      this->grafite = nullptr;
      return false;
    }
    if (this->grafite != nullptr)
    {
      std::cout << "ERROR! Ja existe grafite\n";
      return false;
    }
    this->grafite = grafite;
    return true;
  }

  GRAFITE *remover()
  {
    GRAFITE *cis = this->grafite;
    this->grafite = nullptr;
    return cis;
  }

  bool write(int folhas)
  {
    int follhasEscritas{0};

    if (this->grafite == nullptr)
    {
      std::cout << "ERROR! Sem grafite na lapiseira\n";
      return false;
    }

    while (folhas > 0)
    {
      int desgaste = grafite->desgastePorFolha();

      if (this->grafite->tamanho == 0 || desgaste > this->grafite->tamanho)
      {

        std::cout << "\nTexto incompleto!\n";
        std::cout << follhasEscritas << " folhas foram escritas\n";

        std::cout << "\nCabou o grafite :/\n";
        remover();
        return false;
      }
      grafite->tamanho -= desgaste;
      follhasEscritas++;
      folhas--;
    }

    if (folhas == 0 && this->grafite->tamanho == 0)
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
  LAPISEIRA bic;

  while (true)
  {
    std::cout << "$ ";

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::string comando;
    ss >> comando;

    if (comando == "end")
    {
      break;
    }
    else if (comando == "init")
    {
      float calibre{0};
      ss >> calibre;
      bic.calibre = calibre;
    }
    else if (comando == "show")
    {
      std::cout << bic.toString();
      if (bic.grafite == nullptr)
      {
        std::cout << "Grafite: null\n";
      }
      else
      {
        std::cout << bic.grafite->toString() << std::endl;
      }
    }
    else if (comando == "inserir")
    {
      float calibre{0};
      std::string dureza;
      int tamanho;

      ss >> calibre >> dureza >> tamanho;
      GRAFITE *grafite = new GRAFITE(calibre, tamanho, dureza);

      if (!bic.inserir(grafite))
      {
        delete grafite;
      }
    }
    else if (comando == "remover")
    {
      GRAFITE *grafite = bic.remover();
      if (grafite != nullptr)
      {
        delete grafite;
      }
      else
      {
        std::cout << "Tem grafite na lapiseira nao man!\n";
      }
    }
    else if (comando == "write")
    {
      int folhas{0};

      ss >> folhas;
      bic.write(folhas);
    }
  }

  return 0;
}