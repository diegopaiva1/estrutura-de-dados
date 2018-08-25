/**
 * @file    Deputy.h
 * @author  Diego Paiva e Silva
 * @date    19/08/2018
 *
 * Esta classe armazena os dados dos deputados. Por se tratar de uma estrutura feita somente para
 * armazenar e acessar tais dados, todas as variáveis são públicas.
 */

#ifndef DEPUTY_H_INCLUDED
#define DEPUTY_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

class Deputy
{
public:
  Deputy(std::vector<std::string> data);
  ~Deputy() {};
  std::string buggedDate;
  std::string id;
  std::string name;
  std::string party;
  std::string receiptDate;
  std::string receiptSocialSecurityNumber;
  std::string receiptDescription;
  std::string stateCode;
  std::string establishmentName;
  int receiptValue;
  bool operator>(const Deputy& deputy) const { return receiptValue > deputy.receiptValue; }
  bool operator<(const Deputy& deputy) const { return receiptValue < deputy.receiptValue; }
  bool operator==(const Deputy& deputy) const { return receiptValue == deputy.receiptValue; }
  bool operator!=(const Deputy& deputy) const { return !(operator==(deputy)); }
  bool operator>=(const Deputy& deputy) const { return receiptValue >= deputy.receiptValue; }
  bool operator<=(const Deputy& deputy) const { return receiptValue <= deputy.receiptValue; }
};

#endif // DEPUTY_H_INCLUDED
