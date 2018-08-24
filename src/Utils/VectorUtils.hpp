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
  static std::vector<T> generateSubvectorFrom(std::vector<T> v, int startingIndex, int lastIndex)
  {
    std::vector<T> subvector;
    for (int i = startingIndex; i <= lastIndex; i++)
    {
      subvector.push_back(v.at(i));
    }
    return subvector;
  }

  template<typename T>
  static void generateSortedVectorByMergingTwoSortedVectors(std::vector<T> sorted1, std::vector<T> sorted2,
                                                            std::vector<T> &merged)
  {
    int firstVectorIterator = 0;
    int secondVectorIterator = 0;
    for (unsigned int i = 0; i < sorted1.size() + sorted2.size(); i++)
    {
      if(vectorWasFullyCovered(sorted1, firstVectorIterator) &&
         !vectorWasFullyCovered(sorted2, secondVectorIterator))
      {
        // Basta inserir em merged os elementos do array que não foi todo percorrido
        merged.at(i) = sorted2.at(secondVectorIterator);
        secondVectorIterator++;
      }
      else if(vectorWasFullyCovered(sorted2, secondVectorIterator) &&
              !vectorWasFullyCovered(sorted1, firstVectorIterator))
      {
        merged.at(i) = sorted1.at(firstVectorIterator);
        firstVectorIterator++;
      }
      else {
        // Continuamos comparando os elementos e os inserindo em merged
        if(sorted2.at(secondVectorIterator) < sorted1.at(firstVectorIterator))
        {
          merged.at(i) = sorted2.at(secondVectorIterator);
          secondVectorIterator++;
        }
        else
        {
          merged.at(i) = sorted1.at(firstVectorIterator);
          firstVectorIterator++;
        }
      }
    }
  }

  template<typename T>
  static int getMinElementIndex(std::vector<T> v, int startingIndex = 0)
  {
    return std::distance(v.begin(), std::min_element(v.begin() + startingIndex, v.end()));
  }

private:

  template<typename T>
  static bool vectorWasFullyCovered(std::vector<T> v, int iterator)
  {
    return iterator >= v.size();
  }
};

#endif // VECTORUTILS_H_INCLUDED
