#ifndef SPENT_H_INCLUDED
#define SPENT_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

class Spent
{
public:
  std::string name; //nome do deputado ou partido
  int spent; //gasto total

  Spent() {};
  ~Spent() {};

  bool operator>(const Spent& it) const { return spent > it.spent; }
  bool operator<(const Spent& it) const { return spent < it.spent; }
  bool operator==(const Spent& it) const { return spent == it.spent; }
  bool operator!=(const Spent& it) const { return !(operator==(it)); }
  bool operator>=(const Spent& it) const { return spent >= it.spent; }
  bool operator<=(const Spent& it) const { return spent <= it.spent; }
};

#endif // SPENT_H_INCLUDED