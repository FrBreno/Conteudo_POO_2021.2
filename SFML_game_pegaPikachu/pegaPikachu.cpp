#include <SFML/Graphics.hpp>
#include <iostream>

void setSize(sf::Sprite &sprite, int width, int height)
{
  auto dim = sprite.getLocalBounds();
  sprite.setScale((float)width / dim.width, (float)height / dim.height);
  return;
}

//Entidade:
struct Entity
{
  //Atributos para o estado atual da entidade:
  int x{0};
  int y{0};
  int step{0};
  sf::Sprite sprite;

  //Construtor:
  Entity(int x, int y, int step, sf::Texture &texture)
  {
    //Processo de atribuição cópia:
    this->x = x;
    this->y = y;
    this->step = step;
    this->sprite.setTexture(texture);
  }

  //Métodos:
  void draw(sf::RenderWindow &window)
  {
    this->sprite.setPosition(x * step, y * step);
    setSize(this->sprite, step, step);
    window.draw(this->sprite);
  }
};

struct Board
{
  int nc{0};
  int nl{0};
  int step{0};
  sf::Sprite sprite;
  sf::RectangleShape rect;

  //Construtor:
  Board(int nc, int nl, int step, sf::Texture &texture)
  {
    this->nc = nc; //this é um ponteiro que "fala" que nc é um atributo da classe board, e não um parametro da função atual.
    this->nl = nl;
    this->step = step;
    this->sprite.setTexture(texture);
    setSize(this->sprite, nc * step, nl * step);
    this->sprite.setPosition(0, 0);
    //Desenho da matriz (opcional):
    /*
    this->rect.setSize(sf::Vector2f(step, step));
    this->rect.setFillColor(sf::Color::Transparent);
    this->rect.setOutlineColor(sf::Color::Black);
    this->rect.setOutlineThickness(2)*/
  }

  //Métodos:
  void draw(sf::RenderWindow &window)
  {
    window.draw(this->sprite);
    //Laço para desenho da matriz (opcional):
    /*
    for (int c = 0; c < nc; c++)
    {
      for (int l = 0; l < nl; l++)
      {
        rect.setPosition(c * step, l * step);
        window.draw(rect);
      }
    }*/
  }
};

void moveEntity(sf::Keyboard::Key key, Entity &entity, std::vector<sf::Keyboard::Key> moveKeys)
{
  if (key == moveKeys[0]) //Esquerda
  {
    entity.x--;
  }
  else if (key == moveKeys[1]) //Para cima
  {
    entity.y--;
  }
  else if (key == moveKeys[2]) //Direita
  {
    entity.x++;
  }
  else if (key == moveKeys[3]) //Para baixo
  {
    entity.y++;
  }

  return;
}

//Carregamento da textura:
sf::Texture loadTexture(std::string path)
{
  sf::Texture texture;
  if (!texture.loadFromFile(path))
  {
    std::cout << "Error loading texture\n";
    exit(1);
  }
  return texture;
}

int main()
{

  //Equipe Rocket - Edition:
  sf::Texture rocket_tex{loadTexture("Equipe Rocket.png")};
  sf::Texture pikachu_tex{loadTexture("pikachu.png")};
  sf::Texture pallet_tex{loadTexture("Cidade de Pallet.png")};

  const int STEP{100};

  Entity rocket(1, 1, STEP, rocket_tex);
  Entity pikachu(3, 3, STEP, pikachu_tex);
  Board board(7, 5, STEP, pallet_tex);

  //Criando a janela:
  sf::RenderWindow window(sf::VideoMode(board.nc * STEP, board.nl * STEP), "Cidade de Pallet");

  //Análise de eventos:
  while (window.isOpen())
  {
    sf::Event e;
    while (window.pollEvent(e))
    {
      if (e.type == sf::Event::Closed) //Fechar janela
      {
        window.close();
      }
      else if (e.type == sf::Event::KeyPressed)
      {
        moveEntity(e.key.code, rocket, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
        moveEntity(e.key.code, pikachu, {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
      }
    }

    //Atualização e pintura da tela:

    window.clear();
    board.draw(window);
    rocket.draw(window);
    pikachu.draw(window);
    window.display();
  }

  return 0;
}
