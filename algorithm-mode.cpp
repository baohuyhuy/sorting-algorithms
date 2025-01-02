#include "algorithm-mode.h"
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include "algorithms.h"
#include "utils.h"

using namespace std;

void sortDataByAlgorithm(string algorithm,
                         vector<int>& input,
                         string outputParam) {
  // pair<long long, int> result;
  long long time;
  int comparisons;
  if (algorithm == SELECTION_SORT) {
    tie(time, comparisons) = selectionSort(input);
  } else if (algorithm == INSERTION_SORT) {
    tie(time, comparisons) = insertionSort(input);
  } else if (algorithm == BINARY_INSERTION_SORT) {
    tie(time, comparisons) = binaryInsertionSort(input);
  } else if (algorithm == BUBBLE_SORT) {
    tie(time, comparisons) = bubbleSort(input);
  } else if (algorithm == SHAKER_SORT) {
    tie(time, comparisons) = shakerSort(input);
  } else if (algorithm == SHELL_SORT) {
    tie(time, comparisons) = shellSort(input);
  } else if (algorithm == HEAP_SORT) {
    tie(time, comparisons) = heapSort(input);
  } else if (algorithm == MERGE_SORT) {
    tie(time, comparisons) = mergeSort(input);
  } else if (algorithm == QUICK_SORT) {
    tie(time, comparisons) = quickSort(input);
  } else if (algorithm == COUNTING_SORT) {
    tie(time, comparisons) = countingSort(input);
  } else if (algorithm == RADIX_SORT) {
    tie(time, comparisons) = radixSort(input);
  } else if (algorithm == FLASH_SORT) {
    tie(time, comparisons) = flashSort(input);
  }
  cout << "---------------------------------" << endl;
  if (outputParam == TIME) {
    cout << "Running time: " << time << " ms" << endl;
  } else if (outputParam == COMPARISONS) {
    cout << "Comparisons: " << comparisons << endl;
  } else if (outputParam == BOTH) {
    cout << "Running time: " << time << " ms" << endl;
    cout << "Comparisons: " << comparisons << endl;
  }
}

void runAlgorithmMode(int argc, char* argv[]) {
  string algorithm = argv[2];
  // check if the algorithm is valid
  if (!isValidAlgorithm(algorithm)) {
    cout << "Invalid argument 2" << endl;
    exit(1);
  }

  // check if the input is given or randomly generated
  string inputFilename = "";
  int inputSize = 0;
  try {
    inputSize = stoi(argv[3]);
  } catch (...) {
    inputFilename = argv[3];
  }

  // create the input
  vector<vector<int>> input;
  string inputOrder = "";
  if (inputSize) {
    // input is randomly generated

    // check if the input size is valid
    if (!isValidInputSize(inputSize)) {
      cout << "Invalid argument 3" << endl;
      exit(1);
    }

    // check if the input order is valid
    inputOrder = argv[4];
    if (!isValidInputOrder(inputOrder)) {
      inputOrder = ALL_ORDERS;
    }

    input = generateInput(inputSize, inputOrder);
  } else {
    // input is given

    ifstream file(inputFilename);

    // check if the input file is valid
    if (!file) {
      cout << "Invalid argument 3" << endl;
      exit(1);
    }

    input = readInput(file);
    file.close();
  }

  // check if the output parameter is valid
  string outputParam = "";
  if (inputSize && inputOrder != ALL_ORDERS) {
    outputParam = argv[5];
    if (!isValidOutputParam(outputParam)) {
      cout << "Invalid argument 5" << endl;
      exit(1);
    }
  } else {
    outputParam = argv[4];
    if (!isValidOutputParam(outputParam)) {
      cout << "Invalid argument 4" << endl;
      exit(1);
    }
  }

  // run the algorithm
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << getAlgorithmCapitalName(algorithm) << endl;
  if (inputSize) {
    cout << "Input size: " << inputSize << endl;
    if (inputOrder != ALL_ORDERS) {
      cout << "Input order: " << getInputOrderCapitalName(inputOrder) << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << "Input file: " << inputFilename << endl;
    cout << "Input size: " << input[0].size() << endl;
  }
  if (input.size() == 1) {
    sortDataByAlgorithm(algorithm, input[0], outputParam);
    writeDataToFile(input[0], "output.txt");
  } else {
    for (int i = 0; i < input.size(); i++) {
      cout << "Input order: " << INPUT_ORDER_CAPITAL_NAME[i] << endl;
      sortDataByAlgorithm(algorithm, input[i], outputParam);
      cout << endl;
    }
  }
}