#include "algorithms.h"

pair<long long, int> radixSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  int maxElement = input[0];
  for (int i = 1; i < n; i++) {
    if (input[i] > maxElement) {
      maxElement = input[i];
    }
  }

  for (int exp = 1; maxElement / exp > 0; exp *= 10) {
    vector<int> count(10, 0);
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
      count[(input[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      temp[count[(input[i] / exp) % 10] - 1] = input[i];
      count[(input[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
      input[i] = temp[i];
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
