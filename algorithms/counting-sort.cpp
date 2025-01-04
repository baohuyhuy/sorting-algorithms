#include "algorithms.h"

pair<long long, long long> countingSort(vector<int>& arr) {
  int n = arr.size();
  vector<int> count(n, 0);
  vector<int> temp(n);
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; ++comparisons && i < n; i++) {
    count[arr[i]]++;
  }
  for (int i = 1; ++comparisons && i < n; i++) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; ++comparisons && i >= 0; i--) {
    temp[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }
  for (int i = 0; ++comparisons && i < n; i++) {
    arr[i] = temp[i];
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
