#include <iostream>
#include <sstream>

struct Pessoa
{
  std::string nome;
  int idade;

  Pessoa(std::string nome = " ", int idade = 0) : nome{nome}, idade{idade}
  {
  }

  friend std::ostream &operator<<(std::ostream &os, const Pessoa &p) // Sobrecarga do operador << (ocorre quando ensinamos o operador a funcionar).
  {                                                                  // Passa os atributos do objeto para o fluxo de saída:
    os << "Nome: " << p.nome << "\nIdade: " << p.idade << '\n';
    return os;
  }
};

struct Moto
{
  Pessoa *motoqueiro; // Vai receber o endereço de um objeto externo.
  int tempo;
  int potencia{1};

  Moto(Pessoa *motoqueiro = nullptr, int tempo = 0) : motoqueiro{motoqueiro}, tempo{tempo}
  {
  }

  bool inserirMotoqueiro(Pessoa *p)
  { // Recebe o endereço do objeto.
    if (this->motoqueiro != nullptr)
    {
      std::cout << "Motoca ta lotada!\n";
      return false;
    }
    this->motoqueiro = p;
    return true;
  }

  std::string buzina()
  {
    if (this->motoqueiro != nullptr)
    {
      return "P" + std::string(this->potencia, 'I') + '\n';
    }
    else
    {
      return "Tem niguem na moto nao man.\n";
    }
  }

  Pessoa *removerMotoqueiro()
  {
    Pessoa *p = this->motoqueiro;
    this->motoqueiro = nullptr;
    return p;
  }

  void comprarTempo(int tempo)
  {
    this->tempo += tempo;
    return;
  }

  bool dirigir(int tempo)
  {
    if (this->motoqueiro == nullptr)
    {
      std::cout << "Tem niguem na moto nao man.\n";
      return false;
    }
    if (this->motoqueiro->idade > 10)
    {
      std::cout << "Ta maluco man! Tu vai quebrar a moto (Mais de 10 anos nao pode).\n";
      return false;
    }
    if (this->motoqueiro->idade < 4)
    {
      std::cout << "Ta maluco man! A crianca sabe nem andar direito com os pes.\n";
      return false;
    }
    if (this->tempo == 0)
    {
      std::cout << "Man. Primeiro tu tem que comprar tempo!\n";
      return true;
    }
    if (tempo > this->tempo)
    {
      std::cout << "So conssegiu dirigir " << this->tempo << " minutos.\n";
      this->tempo = 0;
      return true;
    }
    if (tempo == this->tempo)
    {
      std::cout << "Conssegiu dirigir por " << this->tempo << " minutos.\n";
      this->tempo -= tempo;
      return true;
    }

    std::cout << "Conssegiu dirigir por " << tempo << " minutos.\n";
    this->tempo -= tempo;
    std::cout << "Voce ainda pode dirigir por " << this->tempo << " minutos.\n";
    return true;
  }

  friend std::ostream &operator<<(std::ostream &os, Moto &m)
  {
    os << "Tempo: " << m.tempo << " Potencia: " << m.potencia << '\n';
    if (m.motoqueiro != nullptr)
    {
      os << "Motoqueiro:\n"
         << *m.motoqueiro;
    }
    else
    {
      std::cout << "Tem niguem na moto nao man.\n";
    }
    return os;
  }

  bool soCano(int cano)
  {
    if (motoqueiro == nullptr)
    {
      std::cout << "Tem niguem na moto nao man.\n";
    }
    else if (cano == 1)
    {
      std::cout << "Voce foi pego pela ROCAM. Desca da moto com a mao na cabeca!\n";
      return true;
    }
    else
    {
      std::cout << "Voce tem que digitar 1 apos o comando pra deixar a moto so o cano.\n";
    }
    return false;
  }

  bool grau(int intensidade)
  {
    if (motoqueiro == nullptr)
    {
      std::cout << "Tem niguem na moto nao man.\n";
      return false;
    }
    else if (intensidade > 0 && intensidade <= 5)
    {
      std::cout << "Grau bem sucedido. Muleke manja demais.\n";
      return false;
    }
    else if (intensidade > 0 && intensidade <= 9)
    {
      std::cout << "Se ferrou, a ROCAM te pegou!\n";
      return true;
    }
    else if (intensidade == 10)
    {
      std::cout << "Menino caiu e quebrou a cabeca no chao.\n";
      std::cout << "PROXIMO!\n";
      return true;
    }
    std::cout << "Man. Tu tem escolher uma intensidade de 1 a 10.\n";
    return false;
  }
};

int main()
{
  Moto moto;

  std::cout << "Comandos: \n"
            << "01. iniciar (inseir potencia da moto)\n"
            << "02. inserir (inserir o nome do motoca Jr e sua idade)\n"
            << "03. retirar (retirar o motoca Jr)\n"
            << "04. tempo (inserir tempo comprado)\n"
            << "05. dirigir (para dirigir a moto)\n"
            << "06. buzinar (para buzinar)\n"
            << "07. cano (inserir 1 para deixar a moto so o cano)\n"
            << "08. grau (inserir intensidade 1-10)\n"
            << "09. exit (para fechar o programa)\n\n";

  while (true)
  {
    // Pega a linha de entrada, transforma e string e envia para ss.
    std::cout << "$ ";

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::string comando;
    ss >> comando;
    if (comando == "exit")
    {
      break;
    }
    else if (comando == "iniciar") // Inserir potencia.
    {
      int potencia = 0;
      ss >> potencia;
      moto.potencia = potencia;
    }
    else if (comando == "show") // Printar moto.
    {
      std::cout << moto << '\n';
    }
    else if (comando == "inserir") // Inserir motoqueiro.
    {
      std::string nome;
      int idade;

      ss >> nome >> idade;
      Pessoa *pessoa = new Pessoa(nome, idade); // heap -> objeto criado dinamicamente que irá morrer somente quando a memoria for desalocada.
      if (!moto.inserirMotoqueiro(pessoa))
      {
        delete pessoa;
      }
    }
    else if (comando == "retirar") // Retirar motoqueiro
    {
      Pessoa *pessoa = moto.removerMotoqueiro();
      if (pessoa != nullptr)
      {
        delete pessoa; // heap -> desalocação de memória.
        moto.potencia = 1;
      }
      else
      {
        std::cout << "Nao tem niguem na moto nao po.\n";
      }
    }
    else if (comando == "tempo")
    {
      int tempo{0};
      ss >> tempo;
      moto.comprarTempo(tempo);
    }
    else if (comando == "dirigir")
    {
      int tempoPiloto{0};
      ss >> tempoPiloto;
      bool motocaRegularizado = moto.dirigir(tempoPiloto);
      if (!motocaRegularizado)
      {
        Pessoa *pessoa = moto.removerMotoqueiro();
        delete pessoa;
      }
    }
    else if (comando == "buzinar")
    {
      std::cout << moto.buzina();
    }
    else if (comando == "cano")
    {
      int cano{0};

      ss >> cano;
      bool rocamPegou = moto.soCano(cano);
      if (rocamPegou)
      {
        Pessoa *pessoa = moto.removerMotoqueiro();
        delete pessoa;
      }
    }
    else if (comando == "grau")
    {
      int intensidade{0};

      ss >> intensidade;

      bool seFerrou = moto.grau(intensidade);
      if (seFerrou)
      {
        Pessoa *pessoa = moto.removerMotoqueiro();
        delete pessoa;
      }
    }
    else
    {
      std::cout << "Comando invalido :/\n";
    }
  }

  return 0;
}