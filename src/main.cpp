/* Todos os algoritmos de ordenação e de tabela hash estão dentro da função main.
 * Descomente as partes que forem ser utilizadas. Compile passando um arquivo como
 * parâmetro. Ex: bin/estruturaDados dataset/entrada.txt.
 */

#include "components/HashTableComparisonsMeasurer.hpp"
#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/HeapSort.hpp"
#include "algorithms/sorting/InsertionSort.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/SelectionSort.hpp"
#include "algorithms/sorting/QuickSort.hpp"
#include "data-structures/hash-table/HashTableSeparateChaining.hpp"
#include "data-structures/hash-table/HashTableOpenAddressing.hpp"
#include "data-structures/hash-table/HashTableCoalescedChaining.hpp"
#include "components/deputy/Deputy.hpp"
#include "components/deputy/DeputyHashTable.hpp"
#include "components/deputy/file/reader/DeputyFileReader.hpp"

#define MAX 1000

int main(int argc, char const *argv[])
{
  // Initialize random seed
  srand(time(NULL));

  // Arquivo passado por linha de comando
  std::string inFile = argv[1];

  std::vector<int> randomNumbers;
  // Preenchendo vetor com números aleatórios
  for (int i = 0; i < MAX; i++)
  {
    randomNumbers.push_back(rand() % MAX + 1);
  }

  // // Vetor com os deputados da base de dados
  DeputyFileReader *deputyFileReader = new DeputyFileReader();
  // std::vector<Deputy> deputies = deputyFileReader->constructDeputies("dataset/deputies.csv");

  // /* Tabelas Hash de encadeamento separado, endereçamento aberto (sondagem quadratica)
  //  * e encadeamento coalescido. Método get para retornar o dado se ele existir.
  //  */
  // HashTableSeparateChaining *h1 = new HashTableSeparateChaining(randomNumbers, 0.75);
  // HashTableOpenAddressing *h2 = new HashTableOpenAddressing(randomNumbers, 0.75, "Quadratic Probing");
  // HashTableCoalescedChaining *h3 = new HashTableCoalescedChaining(randomNumbers, 0.75);

  // try
  // {
  //   h1->get(350);
  //   h2->get(350);
  //   h3->get(350);
  // }
  // catch (char const* exception)
  // {
  //   std::cerr << exception << std::endl;
  // }

  // HeapSort *heapSort = new HeapSort();
  // heapSort->sort(randomNumbers);
  // heapSort->sort(deputies);

  // InsertionSort *insertionSort = new InsertionSort();
  // insertionSort->sort(randomNumbers);
  // insertionSort->sort(deputies);

  MergeSort *mergeSort = new MergeSort();
  mergeSort->sort(randomNumbers);
  // mergeSort->sort(deputies);

  // SelectionSort *selectionSort = new SelectionSort();
  // selectionSort->sort(randomNumbers);
  // selectionSort->sort(deputies);

  // QuickSort *quickSort = new QuickSort();
  // quickSort->sort(randomNumbers); // Recursivo clássico
  // quickSort->sort(randomNumbers, 5); // Mediana com k = 5
  // quickSort->sort(randomNumbers, 0, 10); // Inserção com n = 10

  // Imprimindo os numeros ordenados
  for (auto n : randomNumbers)
  {
    std::cout << n << std::endl;
  }

  // // Imprimindo os deputados ordenados
  // for (auto deputy : deputies)
  // {
  //   std::cout << "ID: " << deputy.id << std::endl;
  //   std::cout << "Nome: " << deputy.name << std::endl;
  //   std::cout << "Partido: " << deputy.party << std::endl;
  //   std::cout << "Valor do recibo: " << deputy.receiptValue << std::endl;
  //   std::cout << std::endl;
  // }

  // /* Classe para armazenar as estatisticas de um algoritmo de ordenação em arquivo txt (o arquivo
  //  * padrão é saida.txt, para mudar o arquivo passe um terceiro parâmetro),
  //  * passando o arquivo de entrada com os tamanhos dos conjuntos para gerar aleatórios e testar
  //  */
  // SortingAlgorithmPerformanceMeasurer *sapm = new SortingAlgorithmPerformanceMeasurer();
  // sapm->storePerformanceResults(inFile, new QuickSort());

  // /* Classe para armazenar as estatisticas de uma hash table em arquivo txt (o arquivo
  //  * padrão é hash-out.txt, para mudar o arquivo passe um terceiro parâmetro), passando o
  //  * arquivo de entrada com os tamanhos dos conjuntos para gerar aleatórios e testar
  //  */
  // HashTableComparisonsMeasurer *htcm = new HashTableComparisonsMeasurer();
  // htcm->storeComparisonsResults(inFile, new HashTableSeparateChaining());

  std::vector<Deputy> deps = deputyFileReader->constructDeputies("dataset/teste.csv");
  DeputyHashTable *ht = new DeputyHashTable(deps, 0.75);

  ht->highestsSpent(5);

  return 0;
}
