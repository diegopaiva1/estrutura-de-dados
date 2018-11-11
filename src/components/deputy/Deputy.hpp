/**
 * @file    Deputy.hpp
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
  std::string buggedDate;
  int id;
  std::string name;
  std::string party;
  std::string receiptDate;
  std::string receiptSocialSecurityNumber;
  std::string receiptDescription;
  std::string stateCode;
  std::string establishmentName;
  int receiptValue;
  int gasto_id;

  Deputy(std::vector<std::string> data)
  {
    // Cada indice corresponde à coluna em que o dado se encontra no arquivo de leitura
    this->buggedDate = data.at(0);
    this->receiptDate = data.at(1);
    this->id = std::stoi(data.at(2));
    this->party = data.at(3);
    this->stateCode = data.at(4);
    this->name = data.at(5);
    this->receiptSocialSecurityNumber = data.at(6);
    this->receiptDescription = data.at(7);
    this->establishmentName = data.at(8);
    this->receiptValue = std::stoi(data.at(9));
  };
  Deputy() {};
  ~Deputy() {};

  bool operator>(const Deputy& deputy) const { return receiptValue > deputy.receiptValue; }
  bool operator<(const Deputy& deputy) const { return receiptValue < deputy.receiptValue; }
  bool operator==(const Deputy& deputy) const { return receiptValue == deputy.receiptValue; }
  bool operator!=(const Deputy& deputy) const { return !(operator==(deputy)); }
  bool operator>=(const Deputy& deputy) const { return receiptValue >= deputy.receiptValue; }
  bool operator<=(const Deputy& deputy) const { return receiptValue <= deputy.receiptValue; }
};

#endif // DEPUTY_H_INCLUDED
