#include "experiment-mode.h"
#include <fstream>
#include "./algorithms/algorithms.h"
#include "utils.h"

typedef pair<long long, long long> (*sortPtr)(vector<int>&);
const vector<sortPtr> SORT_METHODS = {
    selectionSort, insertionSort, binaryInsertionSort, bubbleSort, shakerSort,
    shellSort,     heapSort,      mergeSort,           quickSort,  countingSort,
    radixSort,     flashSort};

void writeResultToFile(pair<long long, long long> result,
                       int inputSize,
                       string inputOrder,
                       int sortMethod) {
  ofstream file(getInputOrderCapitalName(inputOrder) + ".txt", ios::app);
  file << "---------------------------------" << endl;
  file << "Input size: " << inputSize << endl;
  file << "Sort method: " << SORT_ALGORITHMS[sortMethod] << endl;
  file << "Running time: " << result.first << " ms" << endl;
  file << "Comparisons: " << result.second << endl;
  file.close();
}

void clearDataFiles(string inputOrder) {
  ofstream file(getInputOrderCapitalName(inputOrder) + ".txt");
  file.close();
}

void runExperimentMode() {
  for (const string& inputOrder : INPUT_ORDERS) {
    clearDataFiles(inputOrder);
    for (const int& inputSize : INPUT_SIZES) {
      vector<int> data = generateInput(inputSize, inputOrder)[0];
      writeDataToFile(data,
                      "input" + inputOrder + to_string(inputSize) + ".txt");
      for (int i = 0; i < (int)SORT_METHODS.size(); i++) {
        vector<int> input = data;
        pair<long long, long long> result = SORT_METHODS[i](input);
        writeResultToFile(result, inputSize, inputOrder, i);
      }
    }
  }
}