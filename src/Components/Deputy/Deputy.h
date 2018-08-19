/**
 * @file    Deputy.h
 * @author  Diego Paiva e Silva
 * @date    19/08/2018
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
  std::string id;
  std::string name;
  std::string party;
  std::string receiptDate;
  std::string receiptSocialSecurityNumber;
  std::string receiptDescription;
  std::string stateCode;
  std::string establishmentName;
  std::string receiptValue;
  Deputy(std::vector<std::string> data);
  ~Deputy() {};
};

#endif // DEPUTY_H_INCLUDED
