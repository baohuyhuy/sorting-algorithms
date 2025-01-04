#include "algorithms.h"

pair<long long, int> insertionSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 1; i < n; i++) {
    int key = input[i];
    int j = i - 1;
    while (j >= 0 && ++comparisons && input[j] > key) {
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

  for (int i = 1; i < n; i++) {
    int key = input[i];
    int left = 0, right = i - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (++comparisons && key < input[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    for (int j = i - 1; j >= left; j--) {
      input[j + 1] = input[j];
    }
    input[left] = key;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
