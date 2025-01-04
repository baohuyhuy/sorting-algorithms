#include "algorithms.h"

pair<long long, long long> selectionSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; ++comparisons && i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; ++comparisons && j < n; j++) {
      if (++comparisons && arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
