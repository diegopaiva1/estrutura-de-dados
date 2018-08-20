#include "DeputyFileReader.h"

void DeputyFileReader::read(std::string fileName, std::vector<Deputy *> &deputies)
{
  std::ifstream inFile(fileName);

  std::string line;

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
}

std::vector<std::string> DeputyFileReader::explode(std::string const & s, char delim)
{
  std::vector<std::string> result;
  std::istringstream iss(s);

  for (std::string token; std::getline(iss, token, delim); )
  {
    result.push_back(std::move(token));
  }

  return result;
}
