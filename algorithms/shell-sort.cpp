#include <algorithm>
#include "algorithms.h"

pair<long long, int> shellSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  // Knuth's gap sequence
  // vector<int> gaps;
  // for (int h = 1; h < n; h = 3 * h + 1) {
  //   gaps.push_back(h);
  // }
  // reverse(gaps.begin(), gaps.end());

  // Marcin Ciura's gap sequence
  vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};

  for (int gap : gaps) {
    for (int i = gap; i < n; i++) {
      int temp = input[i];
      int j;
      for (j = i; j >= gap && ++comparisons && input[j - gap] > temp;
           j -= gap) {
        input[j] = input[j - gap];
      }
      input[j] = temp;
    }
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
