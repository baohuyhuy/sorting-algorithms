#include "algorithms.h"

pair<long long, long long> bubbleSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; ++comparisons && i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; ++comparisons && j < n - i - 1; j++) {
      if (++comparisons && arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
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
