/**
 * @file    PatriciaTree.hpp
 * @author  Diego Paiva e Silva
 * @date    18/10/2018
 */

#ifndef PATRICIATREE_H_INCLUDED
#define PATRICIATREE_H_INCLUDED

#include <string>
#include <queue>
#include "PatriciaNode.hpp"

class PatriciaTree
{
public:
  PatriciaNode *root;

  PatriciaTree() { root = nullptr; }

  ~PatriciaTree() {}

  PatriciaNode* insert(std::string word)
  {
    toUppercase(word);
    return insert(word, root);
  }

  bool hasWord(std::string word)
  {
    toUppercase(word);
    return hasWord(word, root);
  }

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

        std::cout << node->word << " (" << node->isCompleteWord << ") ";

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
  PatriciaNode* insert(std::string word, PatriciaNode *&node)
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
      int childInsertionPosition;

      if (isPrefixOf(node->word, word))
      {
        std::string remainingCharacters = word.substr(node->word.length());

        if (remainingCharacters.length() > 0)
        {
          childInsertionPosition = getChildPosition(remainingCharacters);
          node->children.at(childInsertionPosition) = insert(
            remainingCharacters, node->children.at(childInsertionPosition)
          );
        }

        if (word.compare(node->word) == 0)
          node->isCompleteWord = true;
      }
      else
      {
        std::string commonPrefixString;
        commonPrefixString.reserve(std::max(word.length(), node->word.length()));

        // Preenche o prefixo comum encontrado (se existir)
        for (int i = 0; i < node->word.length() && word[i] == node->word[i]; i++)
          commonPrefixString.push_back(node->word[i]);

        // Parte remanescente da palavra do nó (que não faz parte do prefixo comum)
        std::string remainingCharactersFromNode = node->word.substr(commonPrefixString.length());

        // Parte remanescente da palavra de entrada (que não faz parte do prefixo comum)
        std::string remainingCharactersFromInputWord = word.substr(commonPrefixString.length());

        PatriciaNode *commonPrefixNode = new PatriciaNode(commonPrefixString);

        node->word = remainingCharactersFromNode;

        if (node->word.length() > 0)
        {
          childInsertionPosition = getChildPosition(node->word);
          commonPrefixNode->children.at(childInsertionPosition) = node;
        }

        if (remainingCharactersFromInputWord.length() > 0)
        {
          childInsertionPosition = getChildPosition(remainingCharactersFromInputWord);
          commonPrefixNode->children.at(childInsertionPosition) = insert(
            remainingCharactersFromInputWord, commonPrefixNode->children.at(childInsertionPosition)
          );
        }

        commonPrefixNode->isCompleteWord = false;

        if (node == root)
          root = commonPrefixNode;

        return commonPrefixNode;
      }
    }

    return node;
  }

  bool hasWord(std::string word, PatriciaNode *&node)
  {
    if (node == nullptr)
    {
      return false;
    }
    else if (node->word.compare(word) == 0 && node->isCompleteWord)
    {
      return true;
    }
    else if (isPrefixOf(node->word, word))
    {
      std::string remainingCharacters = word.substr(node->word.length());

      if (remainingCharacters.length() > 0)
      {
        int position = getChildPosition(remainingCharacters);
        return hasWord(remainingCharacters, node->children.at(position));
      }
    }

    return false;
  }

  // @returns true se word1 é prefixo de word2 e false caso contrário
  bool isPrefixOf(std::string word1, std::string word2)
  {
    int i = 0;

    while (word2[i] != '\0' && word1[i] == word2[i])
      i++;

    return i == word1.length();
  }

 /* Mapeia a posição do filho utilizando o código ASCII da primeira letra. Isso significa que se o primeiro
  * caracter é, por exemplo, a letra 'C' (ASCII = 67), então a posição do filho é 2. Esse cálculo segue a
  * lógica de manter o padrão:
  * Posição 0 => a, Posição 1 => b, Posição 2 => c e assim por diante.
  * Caracteres especiais são mapeados em posições específicas.
  */
  int getChildPosition(std::string word)
  {
    switch (word[0])
    {
      case '"':
        return 26;
        break;
      case ',':
        return 27;
        break;
      case '&':
        return 28;
        break;
      case '.':
        return 29;
        break;
      case ' ':
        return 30;
        break;
      default:
        return word[0] - 65;
    }
  }

  void toUppercase(std::string &word)
  {
    for (int i = 0; i < word.length(); i++)
      word[i] = toupper(word[i]);
  }
};

#endif // PATRICIATREE_H_INCLUDED
