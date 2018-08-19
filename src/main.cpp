#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>

#include "Components/Deputy/Deputy.h"

// TODO - Refatorar esse main.cpp

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
    std::cout << "Falha na leitura do arquivo" << std::endl;
    exit(1);
  }
  else
  {
    int lineNumber = 1;
    std::vector<std::string> data;
    std::cout << "Processando..." << std::endl;
    while(std::getline(inFile, line))
    {
      // Não queremos ler a primeira linha do arquivo pois ela é o cabeçalho contendo as colunas
      if(lineNumber != 1)
      {
        data = explode(line, ',');
        Deputy *deputy = new Deputy(data);
        deputies.push_back(deputy);
      }
      lineNumber++;
    }
  }

  inFile.close();

  return 0;
}
