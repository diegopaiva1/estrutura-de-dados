/**
 * @file    DeputyFileReader.hpp
 * @author  Diego Paiva e Silva
 * @date    19/08/2018
 *
 * A classe DeputyFileReader realiza a leitura do dataset de deputados e retorna, através do método
 * constructDeputies, um vector contendo todos os deputados (objetos da classe Deputy).
 * O formato esperado do arquivo é:
 *
 * Linha 1:       col1;col2;col3;col4;col5;col6;col7;col8;col9;col10
 * Demais linhas: val1;val2;val3;val4;val5;val6;val7;val8;val9;val10
 *
 * Linhas fora do formato esperado podem gerar erros de execução indesejados.
 */

#ifndef DEPUTYFILEREADER_H_INCLUDED
#define DEPUTYFILEREADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>

#include "../../Deputy.hpp"

class DeputyFileReader
{
public:
  DeputyFileReader() {};
  ~DeputyFileReader() {};

  std::vector<Deputy> constructDeputies(std::string fileName)
  {
    std::ifstream inFile(fileName);

    std::vector<Deputy> deputies;

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
      while (std::getline(inFile, line) && lineNumber <= 1000001)
      {
        // Não queremos ler a primeira linha do arquivo pois ela é o cabeçalho contendo as colunas
        if (lineNumber != 1)
        {
          data = explode(line, ';');
          Deputy *deputy = new Deputy(data);
          deputy->gasto_id = lineNumber - 1;
          deputies.push_back(*deputy);
        }
        lineNumber++;
      }
    }

    inFile.close();

    return deputies;
  }

  std::vector<std::string> explode(std::string const & string, char delimiter)
  {
    std::vector<std::string> result;
    std::istringstream iss(string);

    for (std::string token; std::getline(iss, token, delimiter); )
      result.push_back(std::move(token));

    return result;
  }
};

#endif // DEPUTYFILEREADER_H_INCLUDED
