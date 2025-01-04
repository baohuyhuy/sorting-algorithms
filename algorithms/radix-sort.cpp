#include "algorithms.h"

pair<long long, long long> radixSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  int maxElement = arr[0];
  for (int i = 1; ++comparisons && i < n; i++) {
    if (++comparisons && arr[i] > maxElement) {
      maxElement = arr[i];
    }
  }

  for (int exp = 1; ++comparisons && maxElement / exp > 0; exp *= 10) {
    vector<int> count(10, 0);
    vector<int> temp(n);
    for (int i = 0; ++comparisons && i < n; i++) {
      count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; ++comparisons && i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; ++comparisons && i >= 0; i--) {
      temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; ++comparisons && i < n; i++) {
      arr[i] = temp[i];
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
