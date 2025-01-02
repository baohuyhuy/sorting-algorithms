#include "algorithms.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
#include "utils.h"

using namespace std;

pair<long long, int> selectionSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; ++comparisons && i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; ++comparisons && j < n; j++) {
      if (++comparisons && input[j] < input[minIndex]) {
        minIndex = j;
      }
    }
    swap(input[i], input[minIndex]);
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> insertionSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 1; ++comparisons && i < n; i++) {
    int key = input[i];
    int j = i - 1;
    while (++comparisons && j >= 0 && ++comparisons && input[j] > key) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = key;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> binaryInsertionSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 1; ++comparisons && i < n; i++) {
    int key = input[i];
    int left = 0, right = i - 1;
    while (++comparisons && left <= right) {
      int mid = left + (right - left) / 2;
      if (++comparisons && key < input[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    for (int j = i - 1; ++comparisons && j >= left; j--) {
      input[j + 1] = input[j];
    }
    input[left] = key;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> bubbleSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; ++comparisons && i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; ++comparisons && j < n - i - 1; j++) {
      if (++comparisons && input[j] > input[j + 1]) {
        swap(input[j], input[j + 1]);
        swapped = true;
      }
    }
    if (++comparisons && !swapped) {
      break;
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> shakerSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  bool swapped = false;
  do {
    swapped = false;
    for (int i = 0; ++comparisons && i < n - 1; i++) {
      if (++comparisons && input[i] > input[i + 1]) {
        swap(input[i], input[i + 1]);
        swapped = true;
      }
    }
    if (++comparisons && !swapped) {
      break;
    }
    swapped = false;
    for (int i = n - 1; ++comparisons && i > 0; i--) {
      if (++comparisons && input[i] < input[i - 1]) {
        swap(input[i], input[i - 1]);
        swapped = true;
      }
    }
  } while (++comparisons && swapped);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> shellSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int gap = n / 2; ++comparisons && gap > 0; gap /= 2) {
    for (int i = gap; ++comparisons && i < n; i++) {
      int temp = input[i];
      int j;
      for (j = i;
           ++comparisons && j >= gap && ++comparisons && input[j - gap] > temp;
           j -= gap) {
        input[j] = input[j - gap];
      }
      input[j] = temp;
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

void heapify(vector<int>& input, int n, int i, int& comparisons) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (++comparisons && left < n && input[left] > input[largest]) {
    largest = left;
  }

  if (++comparisons && right < n && input[right] > input[largest]) {
    largest = right;
  }

  if (++comparisons && largest != i) {
    swap(input[i], input[largest]);
    heapify(input, n, largest, comparisons);
  }
}

pair<long long, int> heapSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(input, n, i, comparisons);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(input[0], input[i]);
    heapify(input, i, 0, comparisons);
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

void merge(vector<int>& input,
           int left,
           int mid,
           int right,
           int& comparisons,
           vector<int>& temp) {
  int i = left;
  int j = mid + 1;
  int k = left;

  while (++comparisons && i <= mid && j <= right) {
    if (++comparisons && input[i] <= input[j]) {
      temp[k++] = input[i++];
    } else {
      temp[k++] = input[j++];
    }
  }

  while (++comparisons && i <= mid) {
    temp[k++] = input[i++];
  }

  while (++comparisons && j <= right) {
    temp[k++] = input[j++];
  }

  for (int l = left; ++comparisons && l <= right; l++) {
    input[l] = temp[l];
  }
}

void mergeSortHelper(vector<int>& input,
                     int left,
                     int right,
                     int& comparisons,
                     vector<int>& temp) {
  if (++comparisons && left < right) {
    int mid = left + (right - left) / 2;
    mergeSortHelper(input, left, mid, comparisons, temp);
    mergeSortHelper(input, mid + 1, right, comparisons, temp);
    merge(input, left, mid, right, comparisons, temp);
  }
}

pair<long long, int> mergeSort(vector<int>& input) {
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  vector<int> temp(input.size());
  mergeSortHelper(input, 0, input.size() - 1, comparisons, temp);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

int partition(vector<int>& input, int left, int right, int& comparisons) {
  int pivotIndex = left + rand() % (right - left + 1);
  swap(input[left], input[pivotIndex]);
  pivotIndex = left;
  int storeIndex = left + 1;

  for (int i = left + 1; ++comparisons && i <= right; i++) {
    if (++comparisons && (input[i] < input[pivotIndex])) {
      swap(input[i], input[storeIndex++]);
    }
  }
  swap(input[left], input[--storeIndex]);
  return storeIndex;
}

void quickSortHelper(vector<int>& input,
                     int left,
                     int right,
                     int& comparisons) {
  if (++comparisons && left < right) {
    int pivotIndex = partition(input, left, right, comparisons);
    quickSortHelper(input, left, pivotIndex - 1, comparisons);
    quickSortHelper(input, pivotIndex + 1, right, comparisons);
  }
}

pair<long long, int> quickSort(vector<int>& input) {
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  srand(time(0));
  quickSortHelper(input, 0, input.size() - 1, comparisons);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> countingSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  int maxElement = input[0];
  int minElement = input[0];
  for (int i = 1; ++comparisons && i < n; i++) {
    if (++comparisons && input[i] > maxElement) {
      maxElement = input[i];
    }
    if (++comparisons && input[i] < minElement) {
      minElement = input[i];
    }
  }
  int range = maxElement - minElement + 1;

  vector<int> count(range);
  vector<int> output(n);
  for (int i = 0; ++comparisons && i < n; i++) {
    count[input[i] - minElement]++;
  }
  for (int i = 1; ++comparisons && i < range; i++) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; ++comparisons && i >= 0; i--) {
    output[count[input[i] - minElement] - 1] = input[i];
    count[input[i] - minElement]--;
  }
  for (int i = 0; ++comparisons && i < n; i++) {
    input[i] = output[i];
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> radixSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  int maxElement = input[0];
  for (int i = 1; ++comparisons && i < n; i++) {
    if (++comparisons && input[i] > maxElement) {
      maxElement = input[i];
    }
  }

  for (int exp = 1; maxElement / exp > 0; exp *= 10) {
    vector<int> count(10, 0);
    vector<int> output(n);
    for (int i = 0; ++comparisons && i < n; i++) {
      count[(input[i] / exp) % 10]++;
    }
    for (int i = 1; ++comparisons && i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; ++comparisons && i >= 0; i--) {
      output[count[(input[i] / exp) % 10] - 1] = input[i];
      count[(input[i] / exp) % 10]--;
    }
    for (int i = 0; ++comparisons && i < n; i++) {
      input[i] = output[i];
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

int getK(int element, int minElement, int maxElement, int m) {
  return (int)((double)(m - 1) * (double)(element - minElement) /
               (maxElement - minElement));
}

pair<long long, int> flashSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  // step 1: classification
  int minElement = input[0];
  int maxIdx = 0;
  int maxElement = input[0];
  for (int i = 1; ++comparisons && i < n; i++) {
    if (++comparisons && input[i] > input[maxIdx]) {
      maxIdx = i;
      maxElement = input[i];
    }
    if (++comparisons && input[i] < minElement) {
      minElement = input[i];
    }
  }
  if (++comparisons && minElement == input[maxIdx]) {
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    return {duration.count(), comparisons};
  }
  int m = (int)((double)0.43 * n);
  vector<int> L(m, 0);
  for (int i = 0; ++comparisons && i < n; i++) {
    int k = getK(input[i], minElement, maxElement, m);
    L[k]++;
  }
  for (int k = 1; ++comparisons && k < m; k++) {
    L[k] += L[k - 1];
  }
  swap(input[0], input[maxIdx]);

  // step 2: permutation
  int nmove = 0;
  int j = 0;
  int k = m - 1;
  while (++comparisons && nmove < n - 1) {
    while (++comparisons && j > L[k] - 1) {
      j++;
      k = getK(input[j], minElement, maxElement, m);
    }
    int flash = input[j];
    while (++comparisons && j != L[k]) {
      k = getK(flash, minElement, maxElement, m);
      swap(input[L[k] - 1], flash);
      L[k]--;
      nmove++;
    }
  }

  // step 3: straight insertion
  for (int i = 1; ++comparisons && i < n; i++) {
    int temp = input[i];
    int j = i - 1;
    while (++comparisons && j >= 0 && ++comparisons && input[j] > temp) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = temp;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, int> sortDataByAlgorithm(string algorithm, vector<int>& input) {
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
