#include "algorithms.h"

pair<long long, int> selectionSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
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
