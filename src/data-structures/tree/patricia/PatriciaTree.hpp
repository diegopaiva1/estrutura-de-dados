/**
 * @file    PatriciaTree.hpp
 * @author  Diego Paiva e Silva
 * @date    18/10/2018
 */

#ifndef PATRICIATREE_H_INCLUDED
#define PATRICIATREE_H_INCLUDED

#include <string.h>
#include <queue>
#include "PatriciaNode.hpp"

class PatriciaTree
{
public:
  PatriciaNode *root;

  PatriciaTree() { root = nullptr; }

  ~PatriciaTree() {}

  PatriciaNode* insert(char* word) { return insert(word, root); }

  void printKeysByLevel()
  {
    if (root == nullptr)
    {
      return;
    }
    else
    {
      std::queue<PatriciaNode *> queue;
      queue.push(root);

      while (!queue.empty())
      {
        PatriciaNode *node = queue.front();

        std::cout << node->word << " ";

        queue.pop();

        for (auto child : node->children)
        {
          if (child != nullptr)
            queue.push(child);
        }
      }
      printf("\n");
    }
  }

private:
  PatriciaNode* insert(char* word, PatriciaNode *&node)
  {
    if (node == nullptr)
    {
      PatriciaNode* newNode = new PatriciaNode(word);

      if (root == node)
        root = newNode;

      return newNode;
    }
    else
    {
      // Posição de inserção do filho no vetor de filhos do nó atual
      int position;

      int wordLength = strlen(word);
      int nodeWordLength = strlen(node->word);

      if (isPrefixOf(node->word, word))
      {
        int remainingCharactersLength = wordLength - nodeWordLength + 1; // +1 é para armazenar o '\0'

        char* remainingCharacters = new char[remainingCharactersLength];

        // Copia o resto da palavra (parte que não é prefixo) para 'remainingCharacters'
        for (int i = 0, j = nodeWordLength; word[j] != '\0'; i++, j++)
          remainingCharacters[i] = word[j];

        position = remainingCharacters[0] - 65;

        node->children.at(position) = insert(remainingCharacters, node->children.at(position));
      }
      else
      {
        char* commonPrefixString = new char[nodeWordLength + 1];
        char *remainingCharactersFromNode = new char[nodeWordLength + 1];
        char *remainingCharactersFromInputWord = new char[nodeWordLength + 1];

        // Preenche o prefixo comum encontrado
        for (int i = 0; i < nodeWordLength && word[i] == node->word[i]; i++)
          commonPrefixString[i] = node->word[i];

        // Pega a parte remanescente da palavra do nó (que não faz parte do prefixo comum)
        for (int i = strlen(commonPrefixString), j = 0; i < nodeWordLength; i++, j++)
          remainingCharactersFromNode[j] = node->word[i];

        // Pega a parte remanescente da palavra de entrada (que não faz parte do prefixo comum)
        for (int i = strlen(commonPrefixString), j = 0; i < wordLength; i++, j++)
          remainingCharactersFromInputWord[j] = word[i];

        PatriciaNode *commonPrefixNode = new PatriciaNode(commonPrefixString);

        node->word = remainingCharactersFromNode;

        if (strlen(node->word) > 0)
        {
          position = getChildPosition(node->word);

          commonPrefixNode->children.at(position) = node;
        }

        if (strlen(remainingCharactersFromInputWord) > 0)
        {
          position = getChildPosition(remainingCharactersFromInputWord);

          commonPrefixNode->children.at(position) = insert(
            remainingCharactersFromInputWord, commonPrefixNode->children.at(position)
          );
        }

        if (node == root)
          root = commonPrefixNode;

        return commonPrefixNode;
      }
    }

    return node;
  }

  // @returns true se word1 é prefixo de word2 e false caso contrário
  bool isPrefixOf(char *word1, char *word2)
  {
    int i = 0;

    while (word2[i] != '\0' && word1[i] == word2[i])
      i++;

    return i == strlen(word1);
  }

 /* Calcula a posição do filho utilizando o código ASCII da primeira letra. Isso significa que se o primeiro
  * caracter é, por exemplo, a letra 'C' (ASCII = 67), então a posição do filho é 2. Esse cálculo segue a
  * lógica de manter o padrão:
  * Posição 0 => A, Posição 1 => B, Posição 2 => C e assim por diante.
  */
  int getChildPosition(char *word)
  {
    return word[0] - 65;
  }
};

#endif // PATRICIATREE_H_INCLUDED
