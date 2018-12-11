#include "components/TreePerformanceMeasurer.hpp"
#include "components/CoalescedHashComparisonsMeasurer.hpp"
#include "components/QuickSortMeasurer.hpp"
#include "components/HashTableComparisonsMeasurer.hpp"
#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/HeapSort.hpp"
#include "algorithms/sorting/InsertionSort.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/QuickSort.hpp"
#include "algorithms/sorting/SelectionSort.hpp"
#include "data-structures/hash-table/HashTableSeparateChaining.hpp"
#include "data-structures/hash-table/HashTableCoalescedChaining.hpp"
#include "data-structures/hash-table/HashTableOpenAddressing.hpp"
#include "data-structures/tree/avl/AVLTree.hpp"
#include "data-structures/tree/b/BTree.hpp"
#include "data-structures/tree/red-black/RedBlackTree.hpp"
#include "data-structures/tree/patricia/PatriciaTree.hpp"
#include "data-structures/tree/splay/SplayTree.hpp"
#include "components/deputy/Deputy.hpp"
#include "components/deputy/DeputyHashTable.hpp"
#include "components/deputy/file/reader/DeputyFileReader.hpp"

int main(int argc, char const *argv[])
{
  DeputyFileReader deputyFileReader;
  std::vector<Deputy> deputies = deputyFileReader.constructDeputies("dataset/deputies.csv");

  system("cls || clear");

  while (true)
  {
    int option;
    int operation;
    std::vector<int> validOptions = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    std::string outFileName;
    SortingAlgorithmPerformanceMeasurer sortingMeasurer;
    HashTableComparisonsMeasurer hashMeasurer;
    TreePerformanceMeasurer treeMeasurer;
    QuickSortMeasurer quickSortMeasurer;
    CoalescedHashComparisonsMeasurer coalescedHashMeasurer;

    std::cout << "=================================================== MENU ===================================================\n" << '\n';

    std::cout << "1.  Computar estatísticas de desempenho: HeapSort" << '\n';
    std::cout << "2.  Computar estatísticas de desempenho: InsertionSort" << '\n';
    std::cout << "3.  Computar estatísticas de desempenho: MergeSort" << '\n';
    std::cout << "4.  Computar estatísticas de desempenho: QuickSort Recursivo Clássico" << '\n';
    std::cout << "5.  Computar estatísticas de desempenho: QuickSort Mediana" << '\n';
    std::cout << "6.  Computar estatísticas de desempenho: QuickSort Inserção" << '\n';
    std::cout << "7.  Computar estatísticas de desempenho: SelectionSort" << '\n';
    std::cout << "8.  Computar estatísticas de desempenho: Hash Endereçamento Aberto - Sondagem Linear" << '\n';
    std::cout << "9.  Computar estatísticas de desempenho: Hash Endereçamento Aberto - Sondagem Quadrática" << '\n';
    std::cout << "10. Computar estatísticas de desempenho: Hash Endereçamento Aberto - Duplo Hash" << '\n';
    std::cout << "11. Computar estatísticas de desempenho: Hash Encadeamento Separado" << '\n';
    std::cout << "12. Computar estatísticas de desempenho: Hash Encadeamento Coalescido" << '\n';
    std::cout << "13. Computar estatísticas de desempenho: Árvore AVL" << '\n';
    std::cout << "14. Computar estatísticas de desempenho: Árvore Vermelho e Preta" << '\n';
    std::cout << "15. Computar estatísticas de desempenho: Árvore Splay" << '\n';
    std::cout << "16. Computar estatísticas de desempenho: Árvore B" << '\n';
    std::cout << "17. Computar deputados que mais gastam" << '\n';
    std::cout << "18. Computar deputados que menos gastam" << '\n';
    std::cout << "19. Computar partidos que mais gastam" << '\n';
    std::cout << "20. Computar partidos que menos gastam" << '\n';
    std::cout << "21. Buscar gasto\n" << '\n';

    std::cout << "Selecione uma opção: ";
    std::cin >> option;

    bool isValidOption = false;

    for (int validOption : validOptions)
      if (option == validOption)
        isValidOption = true;

    while (!isValidOption)
    {
      std::cout << "\nOpção inválida! Selecione uma opção: ";
      std::cin >> option;
    }

    std::cout << "\nComputando..." << '\n';
    switch (option)
    {
      case 1:
        sortingMeasurer.storePerformanceResults("dataset/entrada.txt", new HeapSort(), "heapsort.txt");
      break;
      case 2:
        sortingMeasurer.storePerformanceResults("dataset/entrada.txt", new InsertionSort(), "insertionsort.txt");
      break;
      case 3:
        sortingMeasurer.storePerformanceResults("dataset/entrada.txt", new MergeSort(), "mergesort.txt");
      break;
      case 4:
        sortingMeasurer.storePerformanceResults("dataset/entrada.txt", new QuickSort(), "quicksort.txt");
      break;
      case 5:
        int k;
        std::cout << "\nDigite k (número de elementos da mediana): ";
        std::cin >> k;
        quickSortMeasurer.storePerformanceResults("dataset/entrada.txt", new QuickSort(), true, false, k, 0, "quicksort-mediana.txt");
      break;
      case 6:
        int m;
        std::cout << "\nDigite m (número de elementos ordenados pelo InsertionSort): ";
        std::cin >> m;
        quickSortMeasurer.storePerformanceResults("dataset/entrada.txt", new QuickSort(), false, true, 0, m, "quicksort-insercao.txt");
      break;
      case 7:
        sortingMeasurer.storePerformanceResults("dataset/entrada.txt", new SelectionSort(), "selectionsort.txt");
      break;
      case 8:
        hashMeasurer.storeComparisonsResults("dataset/entrada.txt",
                                             new HashTableOpenAddressing("Linear Probing"),
                                             "hash-sondagem-linear.txt");
      break;
      case 9:
        hashMeasurer.storeComparisonsResults("dataset/entrada.txt",
                                             new HashTableOpenAddressing("Quadratic Probing"),
                                             "hash-sondagem-quadratica.txt");
      break;
      case 10:
        hashMeasurer.storeComparisonsResults("dataset/entrada.txt",
                                             new HashTableOpenAddressing("Double Hashing"),
                                             "hash-duplo-hashing.txt");
      break;
      case 11:
        hashMeasurer.storeComparisonsResults("dataset/entrada.txt", new HashTableSeparateChaining(),
                                             "hash-encadeamento-separado.txt");
      break;
      case 12:
        // TODO - Consertar um erro no hashMeasurer pro encadeamento coalescido
        coalescedHashMeasurer.storeComparisonsResults("dataset/entrada.txt", new HashTableCoalescedChaining(),
                                                      "hash-encadeamento-coalescido.txt");
      break;
      case 13:
        int operation;
        std::cout << "\n1. Inserção" << '\n';
        std::cout << "2. Busca" << '\n';
        std::cout << "3. Remoção" << '\n';
        std::cout << "\nDigite a operação que deseja realizar: ";
        std::cin >> operation;

        while (operation != 1 && operation != 2 && operation != 3)
        {
          std::cout << "\nOperação inválida! Digite novamente: ";
          std::cin >> operation;
        }

        if (operation == 1)
          outFileName = "saida-insercao-avl.txt";
        else if (operation == 2)
          outFileName = "saida-busca-avl.txt";
        else
          outFileName = "saida-remocao-avl.txt";

        treeMeasurer.storePerformanceResults("dataset/entrada.txt", new AVLTree(),
                                             operation, outFileName);
      break;
      case 14:
        std::cout << "\n1. Inserção" << '\n';
        std::cout << "2. Busca" << '\n';
        std::cout << "3. Remoção" << '\n';
        std::cout << "\nDigite a operação que deseja realizar: ";
        std::cin >> operation;

        while (operation != 1 && operation != 2 && operation != 3)
        {
          std::cout << "\nOperação inválida! Digite novamente: ";
          std::cin >> operation;
        }

        if (operation == 1)
          outFileName = "saida-insercao-redblack.txt";
        else if (operation == 2)
          outFileName = "saida-busca-redblack.txt";
        else
          outFileName = "saida-remocao-redblack.txt";

        treeMeasurer.storePerformanceResults("dataset/entrada.txt", new RedBlackTree(),
                                             operation, outFileName);
      break;
      case 15:
        std::cout << "\n1. Inserção" << '\n';
        std::cout << "2. Busca" << '\n';
        std::cout << "3. Remoção" << '\n';
        std::cout << "\nDigite a operação que deseja realizar: ";
        std::cin >> operation;

        while (operation != 1 && operation != 2 && operation != 3)
        {
          std::cout << "\nOperação inválida! Digite novamente: ";
          std::cin >> operation;
        }

        if (operation == 1)
          outFileName = "saida-insercao-splay.txt";
        else if (operation == 2)
          outFileName = "saida-busca-splay.txt";
        else
          outFileName = "saida-remocao-splay.txt";

        treeMeasurer.storePerformanceResults("dataset/entrada.txt", new SplayTree(),
                                             operation, outFileName);
      break;
      case 16:
        int pageSize;
        std::cout << "\n1. Inserção" << '\n';
        std::cout << "2. Busca" << '\n';
        std::cout << "3. Remoção" << '\n';
        std::cout << "\nDigite a operação que deseja realizar: ";
        std::cin >> operation;

        while (operation != 1 && operation != 2 && operation != 3)
        {
          std::cout << "\nOperação inválida! Digite novamente: ";
          std::cin >> operation;
        }

        std::cout << "\nDigite o tamanho do bloco: ";
        std::cin >> pageSize;

        if (operation == 1)
          outFileName = "saida-insercao-b.txt";
        else if (operation == 2)
          outFileName = "saida-busca-b.txt";
        else
          outFileName = "saida-remocao-b.txt";

        treeMeasurer.storePerformanceResults("dataset/entrada.txt", new BTree(pageSize),
                                             operation, outFileName);
      break;
      case 17:
      {
        int N;
        std::cout << "\nDigite o valor de N (será exibido os N primeiros deputados que mais gastam): ";
        std::cin >> N;
        DeputyHashTable ht(deputies, 0.75);

        ht.highestsSpent(N);
      }
      break;
      case 18:
      {
        int N;
        std::cout << "\nDigite o valor de N (será exibido os N primeiros deputados que menos gastam): ";
        std::cin >> N;
        DeputyHashTable ht(deputies, 0.75);

        ht.lowestsSpent(N);
      }
      break;
      case 19:
      {
        int N;
        std::cout << "\nDigite o valor de N (será exibido os N primeiros partidos que mais gastam): ";
        std::cin >> N;
        DeputyHashTable ht(deputies, 0.75, "partido");

        ht.highestsSpent(N);
      }
      break;
      case 20:
      {
        int N;
        std::cout << "\nDigite o valor de N (será exibido os N primeiros partidos que menos gastam): ";
        std::cin >> N;
        DeputyHashTable ht(deputies, 0.75, "partido");

        ht.lowestsSpent(N);
      }
      break;
      case 21:
      {
        std::string gasto;
        std::cout << "\nDigite o gasto que deseja encontrar: ";
        std::cin >> gasto;

        PatriciaTree *patriciaTree = new PatriciaTree();

        for (auto deputy : deputies)
        {
          // Quebra os gastos por palavra (vetor de palavras)
          std::vector<std::string> gasto = deputyFileReader.explode(deputy.receiptDescription, ' ');

          for (auto palavra : gasto)
            patriciaTree->insert(palavra);
        }

        if (patriciaTree->hasWord(gasto))
          std::cout << "Gasto encontrado" << '\n';
        else
        {
          std::cout << "Gasto não encontrado! Talvez você queira dizer: " << '\n';
          patriciaTree->printAutocompletionSuggestions(gasto);
        }
      }
      break;
    }
  }

  return 0;
}
