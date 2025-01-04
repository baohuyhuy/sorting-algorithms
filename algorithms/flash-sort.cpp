#include "algorithms.h"

pair<long long, long long> flashSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  // step 1: classification
  int minElement = arr[0];
  int maxIdx = 0;
  int maxElement = arr[0];
  for (int i = 1; ++comparisons && i < n; i++) {
    if (arr[i] > arr[maxIdx]) {
      maxIdx = i;
      maxElement = arr[i];
    }
    if (arr[i] < minElement) {
      minElement = arr[i];
    }
  }
  if (++comparisons && minElement == arr[maxIdx]) {
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    return {duration.count(), comparisons};
  }
  int m = (int)((double)0.43 * n);
  vector<int> L(m, 0);
  double c1 = (double)(m - 1) / (maxElement - minElement);
  for (int i = 0; ++comparisons && i < n; i++) {
    int k = (int)(c1 * (arr[i] - minElement));
    L[k]++;
  }
  for (int k = 1; ++comparisons && k < m; k++) {
    L[k] += L[k - 1];
  }
  swap(arr[0], arr[maxIdx]);

  // step 2: permutation
  int nmove = 0;
  int j = 0;
  int k = m - 1;
  while (++comparisons && nmove < n - 1) {
    while (++comparisons && j > L[k] - 1) {
      j++;
      k = (int)(c1 * (arr[j] - minElement));
    }
    int flash = arr[j];
    while (++comparisons && j != L[k]) {
      k = (int)(c1 * (flash - minElement));
      swap(arr[L[k] - 1], flash);
      L[k]--;
      nmove++;
    }
  }

  // step 3: straight insertion
  for (int i = 1; ++comparisons && i < n; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (++comparisons && j >= 0 && ++comparisons && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
