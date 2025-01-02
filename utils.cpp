#include "utils.h"
#include "data-generator.h"

bool isValidAlgorithm(string algorithm) {
  return (algorithm == SELECTION_SORT || algorithm == INSERTION_SORT ||
          algorithm == BINARY_INSERTION_SORT || algorithm == BUBBLE_SORT ||
          algorithm == SHAKER_SORT || algorithm == SHELL_SORT ||
          algorithm == HEAP_SORT || algorithm == MERGE_SORT ||
          algorithm == QUICK_SORT || algorithm == COUNTING_SORT ||
          algorithm == RADIX_SORT || algorithm == FLASH_SORT);
}

bool isValidInputSize(int size) {
  return (size > 0);
}

bool isValidInputOrder(string inputOrder) {
  return (inputOrder == RANDOM || inputOrder == NEARLY_SORTED ||
          inputOrder == SORTED || inputOrder == REVERSE_SORTED);
}

bool isValidOutputParam(string outputParam) {
  return (outputParam == TIME || outputParam == COMPARISONS ||
          outputParam == BOTH);
}

vector<vector<int>> generateInput(int size, string order) {
  vector<vector<int>> input;
  if (order == RANDOM) {
    input.push_back(generateRandomData(size));
    writeDataToFile(input[0], "input.txt");
  } else if (order == NEARLY_SORTED) {
    input.push_back(generateNearlySortedData(size));
    writeDataToFile(input[0], "input.txt");
  } else if (order == SORTED) {
    input.push_back(generateSortedData(size));
    writeDataToFile(input[0], "input.txt");
  } else if (order == REVERSE_SORTED) {
    input.push_back(generateReverseData(size));
    writeDataToFile(input[0], "input.txt");
  } else if (order == ALL_ORDERS) {
    input.push_back(generateRandomData(size));
    writeDataToFile(input[0], "input_1.txt");
    input.push_back(generateNearlySortedData(size));
    writeDataToFile(input[1], "input_2.txt");
    input.push_back(generateSortedData(size));
    writeDataToFile(input[2], "input_3.txt");
    input.push_back(generateReverseData(size));
    writeDataToFile(input[3], "input_4.txt");
  }
  return input;
}

vector<vector<int>> readInput(ifstream& file) {
  vector<vector<int>> input(1);
  int size;
  file >> size;
  input[0].resize(size);
  for (int& i : input[0]) {
    file >> i;
  }
  return input;
}

void writeDataToFile(vector<int>& data, string filename) {
  ofstream file(filename);
  file << data.size() << endl;
  for (int i : data) {
    file << i << " ";
  }
  file.close();
}

string getAlgorithmCapitalName(string algorithm) {
  if (algorithm == SELECTION_SORT) {
    return "Selection Sort";
  } else if (algorithm == INSERTION_SORT) {
    return "Insertion Sort";
  } else if (algorithm == BINARY_INSERTION_SORT) {
    return "Binary Insertion Sort";
  } else if (algorithm == BUBBLE_SORT) {
    return "Bubble Sort";
  } else if (algorithm == SHAKER_SORT) {
    return "Shaker Sort";
  } else if (algorithm == SHELL_SORT) {
    return "Shell Sort";
  } else if (algorithm == HEAP_SORT) {
    return "Heap Sort";
  } else if (algorithm == MERGE_SORT) {
    return "Merge Sort";
  } else if (algorithm == QUICK_SORT) {
    return "Quick Sort";
  } else if (algorithm == COUNTING_SORT) {
    return "Counting Sort";
  } else if (algorithm == RADIX_SORT) {
    return "Radix Sort";
  } else if (algorithm == FLASH_SORT) {
    return "Flash Sort";
  }
  return "";
}

string getInputOrderCapitalName(string inputOrder) {
  if (inputOrder == RANDOM) {
    return "Randomize";
  } else if (inputOrder == NEARLY_SORTED) {
    return "Nearly Sorted";
  } else if (inputOrder == SORTED) {
    return "Sorted";
  } else if (inputOrder == REVERSE_SORTED) {
    return "Reversed";
  }
  return "";
}