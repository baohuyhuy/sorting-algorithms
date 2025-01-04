#include "algorithms.h"

pair<long long, int> countingSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  vector<int> count(n, 0);
  vector<int> temp(n);
  for (int i = 0; i < n; i++) {
    count[input[i]]++;
  }
  for (int i = 1; i < n; i++) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    temp[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }
  for (int i = 0; i < n; i++) {
    input[i] = temp[i];
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
