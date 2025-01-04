#include <algorithm>
#include "algorithms.h"

pair<long long, long long> shellSort(vector<int>& arr) {
  int n = arr.size();
  // Marcin Ciura's gap sequence
  vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};

  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  // Knuth's gap sequence
  // vector<int> gaps;
  // for (int h = 1; h < n; h = 3 * h + 1) {
  //   gaps.push_back(h);
  // }
  // reverse(gaps.begin(), gaps.end());

  for (int i = 0; ++comparisons && i < (int)gaps.size(); i++) {
    int gap = gaps[i];
    for (int i = gap; ++comparisons && i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i;
           ++comparisons && j >= gap && ++comparisons && arr[j - gap] > temp;
           j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
