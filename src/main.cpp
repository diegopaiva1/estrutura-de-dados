#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>

#include "Components/Deputy/Deputy.h"

std::vector<std::string> explode(std::string const & s, char delim)
{
  std::vector<std::string> result;
  std::istringstream iss(s);

  for (std::string token; std::getline(iss, token, delim); )
  {
    result.push_back(std::move(token));
  }

  return result;
}

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string commandLineFile = argv[1];

  std::ifstream inFile(commandLineFile);

  std::string line;
  std::vector<Deputy *> deputies;

  if (!inFile.is_open())
  {
    std::cout << "Falha na leitura do inFile" << std::endl;
    exit(1);
  }
  else
  {
    int lineNumber = 1;
    std::vector<std::string> deputyData;
    std::cout << "Processando..." << std::endl;
    while(std::getline(inFile, line))
    {
      // A primeira linha do arquivo é o cabeçalho contendo as colunas, portanto não queremos lê-la
      if(lineNumber != 1)
      {
        deputyData = (explode(line, ','));
        Deputy *deputy = new Deputy(deputyData.at(0), deputyData.at(1), deputyData.at(2), deputyData.at(3), deputyData.at(4), deputyData.at(5), deputyData.at(6), deputyData.at(7), deputyData.at(8), deputyData.at(9));
        deputies.push_back(deputy);
      }
      lineNumber++;
    }
  }

  for (int i = 0; i < deputies.size(); ++i)
  {
    std::cout << "Deputado " << i + 1 << ":" << std::endl;
    std::cout << "Nome: " << deputies.at(i)->name << std::endl;
    std::cout << "Id: " << deputies.at(i)->id << std::endl;
    std::cout << "Partido: " << deputies.at(i)->party << std::endl;
    std::cout << "Estado: " << deputies.at(i)->stateCode << std::endl;
    std::cout << "buggedDate: " << deputies.at(i)->buggedDate << std::endl;
    std::cout << "Data do recibo: " << deputies.at(i)->receiptDate << std::endl;
    std::cout << "Valor do recibo: " << deputies.at(i)->receiptValue << std::endl;
    std::cout << "Número do seguro social do recibo: " << deputies.at(i)->receiptSocialSecurityNumber << std::endl;
    std::cout << "Nome do estabelecimento: " << deputies.at(i)->establishmentName << std::endl;
    std::cout << "Descrição do recibo: " << deputies.at(i)->receiptDescription << std::endl;
    printf("\n");
  }

  inFile.close();

  return 0;
}
