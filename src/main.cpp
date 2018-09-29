#include "data-structures/hash-table/HashTableSeparateChaining.hpp"
#include "data-structures/hash-table/HashTableOpenAddressing.hpp"
#include "components/HashTablePerfomanceMeasurer.hpp"

void process_mem_usage(double &vm_usage, double& resident_set);

int main(int argc, char const *argv[])
{
  // Initialize random seed
  srand(time(NULL));

  // Arquivo passado por linha de comando
  std::string inFile = argv[1];

  if (argv[2])
  {
    std::vector<int> data;
    int SIZE = atoi(argv[2]);
    double vm_usage, rss;

    for (int i = 0; i < SIZE; i++)
    {
      data.push_back(rand() % SIZE + 1);
    }

    HashTableSeparateChaining *hashTable = new HashTableSeparateChaining(data, 0.75);

    process_mem_usage(vm_usage, rss);

    std::cout << "Gasto de memória total = " << rss << " kbytes" << std::endl;
  }
  else
  {
    HashTablePerfomanceMeasurer *measurer = new HashTablePerfomanceMeasurer();
    measurer->storePerfomanceResults(inFile, new HashTableOpenAddressing("Double Hashing"));
  }

  return 0;
}

void process_mem_usage(double& vm_usage, double& resident_set)
{
  vm_usage     = 0.0;
  resident_set = 0.0;

  // the two fields we want
  unsigned long vsize;
  long rss;
  {
      std::string ignore;
      std::ifstream ifs("/proc/self/stat", std::ios_base::in);
      ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
          >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
          >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> vsize >> rss;
  }

  long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
  vm_usage = vsize / 1024.0;
  resident_set = rss * page_size_kb;
}
