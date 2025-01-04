#include "algorithms.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
#include "../utils.h"

using namespace std;

pair<long long, long long> sortDataByAlgorithm(string algorithm,
                                               vector<int>& input) {
  if (algorithm == SELECTION_SORT) {
    return selectionSort(input);
  } else if (algorithm == INSERTION_SORT) {
    return insertionSort(input);
  } else if (algorithm == BINARY_INSERTION_SORT) {
    return binaryInsertionSort(input);
  } else if (algorithm == BUBBLE_SORT) {
    return bubbleSort(input);
  } else if (algorithm == SHAKER_SORT) {
    return shakerSort(input);
  } else if (algorithm == SHELL_SORT) {
    return shellSort(input);
  } else if (algorithm == HEAP_SORT) {
    return heapSort(input);
  } else if (algorithm == MERGE_SORT) {
    return mergeSort(input);
  } else if (algorithm == QUICK_SORT) {
    return quickSort(input);
  } else if (algorithm == COUNTING_SORT) {
    return countingSort(input);
  } else if (algorithm == RADIX_SORT) {
    return radixSort(input);
  } else if (algorithm == FLASH_SORT) {
    return flashSort(input);
  }
}
