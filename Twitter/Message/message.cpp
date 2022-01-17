#include "message.hpp"

Message::Message() {}

Message::Message(int id, std::string userName, std::string msg) : id{id}, userName{userName}, msg{msg} {}

void Message::like(std::string userName)
{
  this->likes.insert(userName);
}

int Message::getId() const
{
  return this->id;
}

std::ostream &operator<<(std::ostream &os, const Message &mes)
{
  int size = (int)mes.likes.size();

  os << mes.id << ":" << mes.userName;
  os << " (" << mes.msg << ") [";
  for (auto like : mes.likes)
  {
    os << " " << like;
    if (size > 1)
    {
      os << ",";
    }
  }
  os << " ]";
  return os;
}