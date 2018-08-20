/**
 * @file    DeputyFileReader.h
 * @author  Diego Paiva e Silva
 * @date    19/08/2018
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
  std::vector<std::string> explode(std::string const & s, char delim);
public:
  DeputyFileReader() {};
  ~DeputyFileReader() {};
  void read(std::string fileName, std::vector<Deputy *> &deputies);
};

#endif // DEPUTYFILEREADER_H_INCLUDED
