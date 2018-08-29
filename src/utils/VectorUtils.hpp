/**
 * @file    VectorUtils.hpp
 * @author  Diego Paiva e Silva
 * @date    22/08/2018
 *
 * A classe VectorUtils implementa algumas operações interessantes sobre a classe vector da C++ STL.
 * Apesar de a biblioteca já oferecer uma grande diversidade de operações, o intuito desta classe é
 * tornar algumas destas operações mais legíveis e implementar outras operações não especificadas.
 */

#ifndef VECTORUTILS_H_INCLUDED
#define VECTORUTILS_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>

class VectorUtils
{
public:
  template<typename T>
  static bool hasEvenSize(std::vector<T> v)
  {
    return v.size() % 2 == 0;
  }

  template<typename T>
  static int getMinElementIndex(std::vector<T> v, int startingIndex = 0)
  {
    return std::distance(v.begin(), std::min_element(v.begin() + startingIndex, v.end()));
  }

};

#endif // VECTORUTILS_H_INCLUDED
