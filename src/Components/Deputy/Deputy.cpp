#include "Deputy.h"

Deputy::Deputy(std::string buggedDate, std::string receiptDate, std::string id, std::string party, std::string stateCode,
               std::string name, std::string receiptSocialSecurityNumber, std::string receiptDescription,
               std::string establishmentName, std::string receiptValue)
{
  this->buggedDate = buggedDate;
  this->id = id;
  this->name = name;
  this->party = party;
  this->receiptDate = receiptDate;
  this->receiptSocialSecurityNumber = receiptSocialSecurityNumber;
  this->receiptDescription = receiptDescription;
  this->stateCode = stateCode;
  this->establishmentName = establishmentName;
  this->receiptValue = receiptValue;
}
