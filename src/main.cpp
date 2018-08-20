#include <iostream>
#include <string>

#include "Components/Deputy/Deputy.h"
#include "Components/File/Reader/DeputyFileReader.h"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  std::vector<Deputy *> deputies;

  DeputyFileReader *deputyFileReader = new DeputyFileReader();

  deputyFileReader->read(fileName, deputies);

  return 0;
}
