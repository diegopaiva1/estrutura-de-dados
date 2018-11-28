#include <iostream>
#include "data-structures/tree/avl/AVLTree.hpp"
#include "data-structures/tree/b/BTree.hpp"
#include "data-structures/tree/patricia/PatriciaTree.hpp"
#include "data-structures/tree/red-black/RedBlackTree.hpp"
#include "data-structures/tree/splay/SplayTree.hpp"
#include "components/TreePerformanceMeasurer.hpp"

int main(int argc, char const *argv[])
{
  // ==================== Exemplos práticos das árvores implementadas ====================

  // Instanciando a árvore AVL e seus algoritmos de inserção, busca e remoção
  AVLTree *avlTree = new AVLTree();
  avlTree->insert(50);
  avlTree->insert(78);
  avlTree->insert(112);
  avlTree->insert(120);
  avlTree->remove(120);
  avlTree->get(50);
  avlTree->get(120);

  // Instanciando a árvore B com m = 3 e seus algoritmos de inserção, busca e remoção
  BTree *bTree3 = new BTree(3);
  bTree3->insert(50);
  bTree3->insert(78);
  bTree3->insert(112);
  bTree3->insert(120);
  bTree3->remove(120);
  bTree3->get(50);
  bTree3->get(120);

  // Instanciando a árvore B com m = 5 e seus algoritmos de inserção, busca e remoção
  BTree *bTree5 = new BTree(5);
  bTree5->insert(50);
  bTree5->insert(78);
  bTree5->insert(112);
  bTree5->insert(120);
  bTree5->remove(120);
  bTree5->get(50);
  bTree5->get(120);

  // Instanciando a árvore B com m = 7 e seus algoritmos de inserção, busca e remoção
  BTree *bTree7 = new BTree(7);
  bTree7->insert(50);
  bTree7->insert(78);
  bTree7->insert(112);
  bTree7->insert(120);
  bTree7->remove(120);
  bTree7->get(50);
  bTree7->get(120);

  // Instanciando a árvore rubro-negra e seus algoritmos de inserção, busca e remoção
  RedBlackTree *redBlackTree = new RedBlackTree();
  redBlackTree->insert(50);
  redBlackTree->insert(78);
  redBlackTree->insert(112);
  redBlackTree->insert(120);
  redBlackTree->remove(120);
  redBlackTree->get(50);
  redBlackTree->get(120);

  // Instanciando a árvore de espalhamento e seus algoritmos de inserção, busca e remoção
  SplayTree *splayTree = new SplayTree();
  splayTree->insert(50);
  splayTree->insert(78);
  splayTree->insert(112);
  splayTree->insert(120);
  splayTree->remove(120);
  splayTree->get(50);
  splayTree->get(120);

  // ================= Fim dos exemplos práticos das árvores implementadas =======================
  // =============================================================================================

  // ================= Busca dos gastos dos deputados utilizando Árvore Patrícia =================

  PatriciaTree *patriciaTree = new PatriciaTree();

  DeputyFileReader deputyFileReader;
  std::vector<Deputy> deputies = deputyFileReader.constructDeputies("dataset/deputies.csv");

  for (auto deputy : deputies)
  {
    // Quebra os gastos por palavra (vetor de palavras)
    std::vector<std::string> gasto = deputyFileReader.explode(deputy.receiptDescription, ' ');

    for (auto palavra : gasto)
      patriciaTree->insert(palavra);
  }

  // Método que avalia se este gasto está presente na árvore
  patriciaTree->hasWord("TELEPHONY") ? std::cout << "Gasto encontrado" << '\n'
                                     : std::cout << "Gasto não encontrado" << '\n';

  // Printa todas as sugestões de gastos com o prefixo "T"
  patriciaTree->printAutocompletionSuggestions("T");

  // ========== Fim da busca dos gastos dos deputados utilizando Árvore Patrícia =================
  // =============================================================================================

  /* Classe utilizada para medir a performance de uma determinada árvore como parâmetro.
   * Neste exemplo estamos testando o desempenho da AVL com escrita das estatisticas no
   * arquivo "saidaInsercao.txt". Os tamanhos dos conjuntos de teste estão definidos no
   * arquivo "dataset/entrada.txt"
   */ 
  TreePerformanceMeasurer tpm;
  tpm.storePerformanceResults("dataset/entrada.txt", new AVLTree(), "saidaInsercao.txt");

  return 0;
}
