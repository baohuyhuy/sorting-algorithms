#include "algorithms.h"

pair<long long, long long> insertionSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 1; ++comparisons && i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (++comparisons && j >= 0 && ++comparisons && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}

pair<long long, long long> binaryInsertionSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 1; ++comparisons && i < n; i++) {
    int key = arr[i];
    int left = 0, right = i - 1;
    while (++comparisons && left <= right) {
      int mid = left + (right - left) / 2;
      if (++comparisons && key < arr[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    for (int j = i - 1; ++comparisons && j >= left; j--) {
      arr[j + 1] = arr[j];
    }
    arr[left] = key;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
