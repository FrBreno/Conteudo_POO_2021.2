#include "tweet.hpp"

Tweet::Tweet(int id, const std::string &userName, const std::string &msg) : id{id}, userName{userName}, msg{msg} {}

int Tweet::getId() const
{
  return this->id;
}

std::string Tweet::getSender() const
{
  return this->userName;
}

std::string Tweet::getMsg() const
{
  return this->msg;
}

void Tweet::like(const std::string &username)
{
  this->likes.insert(username);
}

std::set<std::string> Tweet::getLikes() const
{
  return this->likes;
}

void Tweet::setRt(Tweet *rt)
{
  this->rt = rt;
}

void Tweet::setDeleted()
{
  this->deleted = true;
}

bool Tweet::isDeleted() const
{
  return this->deleted;
}

std::ostream &operator<<(std::ostream &os, const Tweet &mes)
{
  int size = (int)mes.likes.size();

  os << mes.id << ":";
  if (mes.isDeleted())
  {
    os << " (esse tweet foi deletado)";
  }
  else
  {
    os << mes.userName << " (" << mes.msg << ")";
    if (size > 0)
    {
      os << " [";
      for (auto like : mes.likes)
      {
        os << like;
        if (size > 1)
        {
          os << ", ";
        }
        size--;
      }
      os << "]";
    }

    if (mes.rt != nullptr)
    {
      os << "\n\t";
      os << *mes.rt;
    }
  }
  return os;
}