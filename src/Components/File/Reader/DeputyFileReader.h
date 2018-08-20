/**
 * @file    DeputyFileReader.h
 * @author  Diego Paiva e Silva
 * @date    19/08/2018
 *
 * A classe DeputyFileReader realiza a leitura do dataset de deputados e retorna, através do método read,
 * um vector contendo todos os deputados (objetos da classe Deputy).
 * O formato esperado do arquivo é:
 *
 * Linha 1:       col1,col2,col3,col4,col5,col6,col7,col8,col9,col10
 * Demais linhas: val1,val2,val3,val4,val5,val6,val7,val8,val9,val10
 *
 * Linhas fora do formato esperado podem gerar erros de execução indesejáveis.
 */

#ifndef DEPUTYFILEREADER_H_INCLUDED
#define DEPUTYFILEREADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>

#include "../../Deputy/Deputy.h"

class DeputyFileReader
{
private:
  std::vector<std::string> explode(std::string const & string, char delimiter);
public:
  DeputyFileReader() {};
  ~DeputyFileReader() {};
  std::vector<Deputy *> read(std::string fileName);
};

#endif // DEPUTYFILEREADER_H_INCLUDED
