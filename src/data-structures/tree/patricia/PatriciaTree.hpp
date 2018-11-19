/**
 * @file    PatriciaTree.hpp
 * @author  Diego Paiva e Silva
 * @date    18/10/2018
 */

#ifndef PATRICIATREE_H_INCLUDED
#define PATRICIATREE_H_INCLUDED

#include <string.h>
#include "PatriciaNode.hpp"

class PatriciaTree
{
public:
  PatriciaNode *root;

  PatriciaTree() { root = nullptr; }

  ~PatriciaTree() {}

  PatriciaNode* insert(char* word) { return insert(word, root); }

  PatriciaNode* insert(char* word, PatriciaNode *&node)
  {
    if (node == nullptr)
    {
      PatriciaNode* newNode = new PatriciaNode(word);

      if (root == nullptr)
        root = newNode;

      return newNode;
    }
    else
    {
      int wordLength = strlen(word);
      int nodeWordLength = strlen(node->word);

      if (isPrefixOf(node->word, word))
      {
        int remainingCharactersLength = wordLength - nodeWordLength + 1; // +1 é para armazenar o '\0'

        char* remainingCharacters = new char[remainingCharactersLength];

        // Copia o resto da palavra (parte que não é prefixo) para 'remainingCharacters'
        for (int i = 0, j = nodeWordLength; word[j] != '\0'; i++, j++)
          remainingCharacters[i] = word[j];

       /* Posição de inserção do filho no vetor de filhos do nó atual. A posição é calculada utilizando
        * o código ASCII da primeira letra da parte remanescente (parte que não é prefixo). Isso significa
        * que se o primeiro caracter pós-prefixo é, por exemplo, a letra 'C' (ASCII = 67), então a posição
        * do filho é 2. Esse cálculo segue a lógica de manter o padrão:
        * Posição 0 => A, Posição 1 => B, Posição 2 => C e assim por diante.
        */
        int position = remainingCharacters[0] - 65;

        node->children.at(position) = insert(remainingCharacters, node->children.at(position));
      }
      else
      {
        char* commonPrefixString = new char[nodeWordLength + 1];
        char *remainingCharacters = new char[nodeWordLength + 1];

        // Preenche o prefixo comum encontrado
        for (int i = 0; i < nodeWordLength && word[i] == node->word[i]; i++)
          commonPrefixString[i] = node->word[i];

        // Pega a parte remanescente da palavra (que não faz parte do prefixo comum)
        for (int i = strlen(commonPrefixString), j = 0; i < nodeWordLength; i++, j++)
          remainingCharacters[j] = node->word[i];

        PatriciaNode *commonPrefixNode = new PatriciaNode(commonPrefixString);

        node->word = remainingCharacters;

        int position = remainingCharacters[0] - 65;

        commonPrefixNode->children.at(position) = insert(
          node->word, commonPrefixNode->children.at(position)
        );

        // delete [] commonPrefixString;
        // delete [] remainingCharacters;
      }
    }

    return node;
  }

private:
  // @returns true se word1 é prefixo de word2 e false caso contrário
  bool isPrefixOf(char *word1, char *word2)
  {
    int i = 0;

    while (word2[i] != '\0' && word1[i] == word2[i])
      i++;

    return i == strlen(word1);
  }
};

#endif // PATRICIATREE_H_INCLUDED
