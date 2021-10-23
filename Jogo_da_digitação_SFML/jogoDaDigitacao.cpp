#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

struct PAINT
{
  sf::Font font;
  sf::Text texto;
  sf::RenderWindow &window;

  PAINT(sf::RenderWindow &window) : window(window)
  {
    if (!font.loadFromFile("fonts/PressStart2P-Regular.ttf"))
    {
      std::cout << "Font not loaded\n";
    }
    texto.setFont(font);
  }

  void write(std::string str, int x, int y, int size, sf::Color color)
  {
    texto.setString(str);
    texto.setCharacterSize(size);
    texto.setPosition(x, y);
    texto.setFillColor(color);
    window.draw(texto);
  }
};

struct BUBBLE
{
  int x;
  int y;
  char letter;
  int speed;
  bool alive{true};

  static const int rad{10}; // Todas as bolhas terão o mesmo raio - Atributo da classe e não do objeto.

  BUBBLE(int x, int y, char letter, int speed) : x{x}, y{y}, letter{letter}, speed{speed}
  {
  }

  void update()
  {
    this->y += this->speed; // this serve pra dizer que estamos falando do atributo do objeto e não de um possível parâmetro da função.
  }

  void draw(sf::RenderWindow &window)
  {
    sf::CircleShape circle(BUBBLE::rad);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::White);
    window.draw(circle);

    static PAINT pincel(window);
    pincel.write(std::string(1, letter), x + 0.4 * BUBBLE::rad, y + 3.5, BUBBLE::rad * 1.2, sf::Color::Black);
  }
};

struct BOARD
{
  sf::RenderWindow &window;
  std::vector<BUBBLE> bolhas;
  PAINT pincel;

  int hits{0};
  int misses{0};

  BOARD(sf::RenderWindow &window) : window{window}, pincel{window}
  {
    // Lembrete: push_back() trabalaho por cópias (valores estáticos).
    bolhas.push_back(BUBBLE(100, 100, 'A', 1));
    bolhas.push_back(BUBBLE(200, 100, 'B', 2));
    bolhas.push_back(BUBBLE(300, 100, 'C', 3));
  }

  void update()
  {
    if (this->check_new_bubble())
    {
      this->add_new_bubble();
    }
    for (BUBBLE &bolhas : bolhas) // Para cada bolha do vector, o endereço dela no vector como objeto BUBBLE desce a tela (update da classe BUBBLE).
    {
      bolhas.update();
    }
    this->mark_outside_bubbles();
    this->remove_dead_bubbles();
  }

  void remove_dead_bubbles()
  {
    std::vector<BUBBLE> vivas;
    for (BUBBLE &bolha : bolhas)
    {
      if (bolha.alive)
      {
        vivas.push_back(bolha);
      }
    }
    this->bolhas = vivas;
  }

  void mark_outside_bubbles()
  {
    for (BUBBLE &bolha : bolhas)
    {
      // OBS: a função getSize() retorna os valores x,y que determinam os limites das bordas da janela (no caso abaixo só nôs interessa o y, por isso getSize().y)
      if (bolha.y + 2 * BUBBLE::rad > (int)this->window.getSize().y)
      {
        if (bolha.alive)
        {
          bolha.alive = false;
          this->misses++;
        }
      }
    }
  }

  bool check_new_bubble()
  {
    static const int nova_bolha_tempoPartida{30};
    static int nova_bolha_temporizador{0};
    nova_bolha_temporizador--;
    if (nova_bolha_temporizador <= 0)
    {
      nova_bolha_temporizador = nova_bolha_tempoPartida;
      return true;
    }
    return false;
  }

  void mark_by_hit(char latter)
  {
    for (BUBBLE &bolha : bolhas)
    {
      if (bolha.letter == latter)
      {
        bolha.alive = false;
        this->hits++;
        break;
      }
    }
  }

  void add_new_bubble()
  {
    int x = rand() % ((int)this->window.getSize().x - 2 * BUBBLE::rad); // Gera um valor aleatório de 0 até o valor da "largura" da janela (eixo x - posição horizontal) - 2x o valor do raio (para a bolha não ser criada nas bordas da tela).
    int y = -2 * BUBBLE::rad;                                           // Para criar a bolha acima da borda superior (eixo x - posição vertical).
    int speed = rand() % 5 + 1;                                         // Para gerar um valor aleatório de 1 a 5.
    char letter = rand() % 26 + 'A';                                    // Gerar um valor de 0 a 25 com base em ASCII.
    bolhas.push_back(BUBBLE(x, y, letter, speed));
  }

  void draw()
  {
    pincel.write("Hits: " + std::to_string(this->hits) + "\n\nMisses: " + std::to_string(this->misses), 15, 15, 12, sf::Color::Yellow);
    pincel.write("Size: " + std::to_string(this->bolhas.size()), 15, 60, 12, sf::Color::Green);
    for (BUBBLE &bolhas : bolhas) // Desenha todas as bolhas do vector passando seu endereço para o objeto bolhas da classe BUBBLE, chamando o método draw da mesma classe.
    {
      bolhas.draw(window);
    }
  }
};

struct GAME
{
  sf::RenderWindow window;
  BOARD board;
  std::function<void()> on_update; // Função que recebe nada e não retorna nada.

  GAME() : window{sf::VideoMode(800, 600), "Bolhinhas"}, board{window}
  {
    this->on_update = [&]()
    {
      this->gameplay();
    };
    window.setFramerateLimit(60);
  }

  void process_events()
  {
    sf::Event evento;
    while (window.pollEvent(evento))
    {
      if (evento.type == sf::Event::Closed)
      {
        window.close();
      }
      else if (evento.type == sf::Event::TextEntered) //"Texto digitado".
      {
        char code = static_cast<char>(evento.text.unicode);
        code = toupper(code); // Transforma todos os caracteres percebidos em maiúsculo.
        board.mark_by_hit(code);
      }
    }
  }

  void gameOver()
  {
    static PAINT pincel(window);
    window.clear(sf::Color::Black);

    pincel.write("Game Over", 170, 270, 50, sf::Color::Red);
    window.display();
  }

  void gameplay()
  {
    board.update();

    window.clear(sf::Color::Black);
    board.draw();
    window.display();

    if (board.misses > 10)
    {
      this->on_update = [&]()
      {
        this->gameOver();
      };
    }
  }

  void main_loop()
  {
    while (window.isOpen())
    {
      process_events();
      on_update();
    }
  }
};

int main()
{
  GAME game;        // Cria o objeto e chama o construtor.
  game.main_loop(); // Detecção de eventos e desenho da janela.
  return 0;
}
