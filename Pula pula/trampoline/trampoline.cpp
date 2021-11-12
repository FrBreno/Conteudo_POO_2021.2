#include "trampoline.hpp"

void Trampoline::remove_kid(string name, int age, int cont, bool play, list<shared_ptr<Kid>>::iterator it)
{
  advance(it, cont);
  if (!play)
  {
    this->waiting.erase(--it);
  }
  else
  {
    this->playing.erase(--it);
  }

  cout << name << ":" << age << " removido(a)\n";
}

Trampoline::Trampoline(int max, int idade_max, int idade_min) : max{max}, idade_max{idade_max}, idade_min{idade_min} {};

void Trampoline::arrive(shared_ptr<Kid> k)
{
  this->waiting.push_back(k);
  return;
}

void Trampoline::in()
{
  cout << (int)this->playing.size() << " " << this->max << endl;
  if ((int)this->playing.size() >= this->max)
  {
    cout << "Pula pula lotado!\n";
  }
  else if (this->waiting.front()->getAge() <= this->idade_max && this->waiting.front()->getAge() >= this->idade_min)
  {
    this->playing.push_back(this->waiting.front());
    this->waiting.pop_front();
  }
  else
  {
    cout << "A crianca nao esta inserida dentro dos limites de idade :/\n";
  }
  return;
}

void Trampoline::out()
{
  this->waiting.push_back(this->playing.front());
  this->playing.pop_front();
  return;
}

void Trampoline::remove(string name, int age)
{
  int cont{0};
  bool play{false};

  for (shared_ptr<Kid> i : this->waiting)
  {
    cont++;
    if (i->getName() == name && i->getAge() == age)
    {
      remove_kid(name, age, cont, play, this->waiting.begin());
      return;
    }
  }
  cont = 0;
  for (shared_ptr<Kid> i : this->playing)
  {
    play = true;
    cont++;
    if (i->getName() == name && i->getAge() == age)
    {
      remove_kid(name, age, cont, play, this->playing.begin());
      return;
    }
  }

  return;
}

void Trampoline::exit()
{
  for (int i{0}; i < (int)this->waiting.size(); i++)
  {
    this->waiting.pop_front();
    if ((int)this->waiting.size() == 1)
    {
      this->waiting.erase(this->waiting.begin());
    }
  }

  for (int i{0}; i < (int)this->playing.size(); i++)
  {
    this->playing.pop_front();
    if ((int)this->playing.size() == 1)
    {
      this->playing.erase(this->playing.begin());
    }
  }

  cout << toString() << endl;
  return;
}

void Trampoline::setParametros(int max, int idade_max, int idade_min)
{
  this->max = max;
  this->idade_max = idade_max;
  this->idade_min = idade_min;
  return;
}

string Trampoline::toString()
{
  list<shared_ptr<Kid>> aux;
  aux = this->waiting;
  aux.reverse();

  string line;
  for (shared_ptr<Kid> i : aux)
  {
    line += " >> " + i->toString();
  }
  line += " >> ";

  aux.clear();

  aux = this->playing;
  aux.reverse();
  line += "[";
  for (shared_ptr<Kid> i : aux)
  {
    line += " " + i->toString();
  }
  line += " ]";

  aux.clear();

  return line;
}
