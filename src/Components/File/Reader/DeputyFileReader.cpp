#include "DeputyFileReader.hpp"

std::vector<Deputy *> DeputyFileReader::constructDeputies(std::string fileName)
{
  std::ifstream inFile(fileName);

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
    std::string line;
    std::cout << "Processando..." << std::endl;
    while(std::getline(inFile, line))
    {
      // Não queremos ler a primeira linha do arquivo pois ela é o cabeçalho contendo as colunas
      if(lineNumber != 1)
      {
        data = explode(line, ';');
        Deputy *deputy = new Deputy(data);
        deputies.push_back(deputy);
      }
      lineNumber++;
    }
  }

  inFile.close();

  return deputies;
}

std::vector<std::string> DeputyFileReader::explode(std::string const & string, char delimiter)
{
  std::vector<std::string> result;
  std::istringstream iss(string);

  for (std::string token; std::getline(iss, token, delimiter); )
  {
    result.push_back(std::move(token));
  }

  return result;
}
