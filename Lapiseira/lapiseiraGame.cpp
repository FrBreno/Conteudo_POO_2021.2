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

  std::string toString(int cont)
  {
    std::string aux = "Grafite " + std::to_string(cont) + ": [" + std::to_string(this->calibre) + " : " + dureza + " : " + std::to_string(this->tamanho) + "]";
    return aux;
  }
};

struct LAPISEIRA
{
  float calibre; // Em mm.
  // GRAFITE *grafite = nullptr;
  std::vector<GRAFITE> grafites;

  LAPISEIRA(float calibre = 0.3f) : calibre{calibre}
  {
  }

  bool inserir(GRAFITE *grafite)
  {
    int soma{0};

    if (grafite->calibre != this->calibre)
    {
      std::cout << "ERROR! Calibre incompativel\n";
      return false;
    }
    for (int i{0}; i < (int)this->grafites.size(); i++)
    {
      soma += this->grafites[i].tamanho;
    }
    if ((soma + grafite->tamanho) > 150)
    {
      int falta = 150 - soma;
      std::cout << "ERROR! Lapiseira cheia. Nao coloque um grafite maior que " << falta << std::endl;
      return false;
    }
    grafites.push_back(*grafite);
    return true;
  }

  GRAFITE *remover()
  {
    GRAFITE *cis = &this->grafites[(int)this->grafites.size() - 1];
    this->grafites.pop_back();
    return cis;
  }

  bool write(int folhas)
  {
    int follhasEscritas{0};

    if ((int)this->grafites.size() == 0)
    {
      std::cout << "ERROR! Sem grafite na lapiseira\n";
      return false;
    }

    while (folhas > 0)
    {
      int desgaste = this->grafites[0].desgastePorFolha();
      bool trocaGrafite{false};

      if (this->grafites[0].tamanho == 0 || desgaste > this->grafites[0].tamanho)
      {
        if (desgaste > this->grafites[0].tamanho && (int)this->grafites.size() > 1)
        {
          trocaGrafite = true;
          int diferenca = desgaste - this->grafites[0].tamanho;
          this->grafites[0].tamanho = 0;
          for (int i{1}; i < (int)this->grafites.size(); i++)
          {
            int aux = diferenca;
            diferenca -= this->grafites[i].tamanho;
            this->grafites[i].tamanho -= aux;
            if (this->grafites[i].tamanho > 0)
            {
              break;
            }
            else
            {
              this->grafites.erase(this->grafites.begin() + i);
            }
          }
        }
        if ((int)this->grafites.size() == 1)
        {
          std::cout << "\nTexto incompleto!\n";
          std::cout << follhasEscritas << " folhas foram escritas\n";

          std::cout << "\nCabou o grafite :/\n";
        }
        this->grafites.erase(this->grafites.begin());
        if ((int)this->grafites.size() == 0)
        {
          return false;
        }
      }
      if (!trocaGrafite)
      {
        this->grafites[0].tamanho -= desgaste;
      }
      follhasEscritas++;
      folhas--;
    }

    if (folhas == 0 && this->grafites[0].tamanho == 0)
    {
      this->grafites.erase(this->grafites.begin());
      if ((int)this->grafites.size() == 0)
      {
        std::cout << "\nCabou o grafite :/\n";
      }
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
      if ((int)bic.grafites.size() == 0)
      {
        std::cout << "Grafite: null\n";
      }
      else
      {
        for (int i{0}; i < (int)bic.grafites.size(); i++)
        {
          std::cout << bic.grafites[i].toString(i + 1) << std::endl;
        }
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