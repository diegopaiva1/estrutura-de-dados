#include "Deputy.hpp"

Deputy::Deputy(std::vector<std::string> data)
{
  // Cada número corresponde à coluna em que o dado se encontra no arquivo de leitura
  this->buggedDate = data.at(0);
  this->receiptDate = data.at(1);
  this->id = data.at(2);
  this->party = data.at(3);
  this->stateCode = data.at(4);
  this->name = data.at(5);
  this->receiptSocialSecurityNumber = data.at(6);
  this->receiptDescription = data.at(7);
  this->establishmentName = data.at(8);
  this->receiptValue = data.at(9);
}
