#include "algorithms.h"

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
  for (int i = 1; i < n; i++) {
    if (input[i] > input[maxIdx]) {
      maxIdx = i;
      maxElement = input[i];
    }
    if (input[i] < minElement) {
      minElement = input[i];
    }
  }
  if (minElement == input[maxIdx]) {
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    return {duration.count(), comparisons};
  }
  int m = (int)((double)0.43 * n);
  vector<int> L(m, 0);
  for (int i = 0; i < n; i++) {
    int k = getK(input[i], minElement, maxElement, m);
    L[k]++;
  }
  for (int k = 1; k < m; k++) {
    L[k] += L[k - 1];
  }
  swap(input[0], input[maxIdx]);

  // step 2: permutation
  int nmove = 0;
  int j = 0;
  int k = m - 1;
  while (nmove < n - 1) {
    while (j > L[k] - 1) {
      j++;
      k = getK(input[j], minElement, maxElement, m);
    }
    int flash = input[j];
    while (j != L[k]) {
      k = getK(flash, minElement, maxElement, m);
      swap(input[L[k] - 1], flash);
      L[k]--;
      nmove++;
    }
  }

  // step 3: straight insertion
  for (int i = 1; i < n; i++) {
    int temp = input[i];
    int j = i - 1;
    while (j >= 0 && ++comparisons && input[j] > temp) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = temp;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
