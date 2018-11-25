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

  bool hasQueryPrefix(std::string query)
  {
    toUppercase(query);
    return hasQueryPrefix(query, root->word);
  }

  bool hasQueryPrefix(std::string query, std::string word)
  {
    if (isPrefixOf(query, word))
    {
      return true;
    }
    else
    {
      std::string prefix;

      for (auto character : word)
      {
        prefix.push_back(character);

        if (prefix.compare(query) == 0)
          return true;
      }

      PatriciaNode* wordLastMatchingNode = getLastMatchingNode(word, root);

      std::string r = (query.substr(word.length()));

      if (r.length() > 0)
      {
        int position = getChildPosition(r);
        return hasQueryPrefix(query, query + wordLastMatchingNode->children.at(position)->word);
      }
    }

    return false;
  }

  void printAutocompletionSuggestions(std::string query)
  {
    toUppercase(query);

    if (!hasQueryPrefix(query))
    {
      return;
    }
    else
    {
      if (hasWord(query))
        std::cout << query << '\n';

      PatriciaNode* queryLastMatchingNode = getLastMatchingNode(query, root);
      int depth = getLastMatchingNodeDepth(query, queryLastMatchingNode);

      if (depth < queryLastMatchingNode->word.length())
      {
        if (hasWord(query + queryLastMatchingNode->word.substr(depth)))
          std::cout << query + queryLastMatchingNode->word.substr(depth) << '\n';
      }

      for (auto child : queryLastMatchingNode->children)
      {
        if (child != nullptr)
        {
          if (query.compare(queryLastMatchingNode->word) != 0)
          {
            if (query.length() <= queryLastMatchingNode->word.length())
            {
              std::string r = queryLastMatchingNode->word.substr(query.length());
              printAutocompletionSuggestions(query + r + child->word);
            }
            else
            {
              printAutocompletionSuggestions(query + child->word);
            }
          }
          else
          {
            printAutocompletionSuggestions(query + child->word);
          }
        }
      }
    }
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
      default:
        return word[0] - 65;
    }
  }

  PatriciaNode* getLastMatchingNode(std::string word, PatriciaNode *&node)
  {
    if (node == nullptr)
    {
      throw "err";
    }
    else if (node->word.compare(word) == 0)
    {
      return node;
    }
    else if (isPrefixOf(node->word, word))
    {
      std::string remainingCharacters = word.substr(node->word.length());

      if (remainingCharacters.length() > 0)
      {
        int position = getChildPosition(remainingCharacters);
        return getLastMatchingNode(remainingCharacters, node->children.at(position));
      }
    }

    return node;
  }

  int getLastMatchingNodeDepth(std::string word, PatriciaNode* node)
  {
    int depth = 0;
    PatriciaNode* aux = root;

    while (isPrefixOf(aux->word, word) && aux != node)
    {
      depth++;

      word = word.substr(aux->word.length());

      if (word.length() > 0)
      {
        int position = getChildPosition(word);
        aux = aux->children.at(position);
      }
    }

    return depth;
  }

  void toUppercase(std::string &word)
  {
    for (int i = 0; i < word.length(); i++)
      word[i] = toupper(word[i]);
  }
};

#endif // PATRICIATREE_H_INCLUDED
