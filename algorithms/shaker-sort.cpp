#include "algorithms.h"

pair<long long, int> shakerSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  bool swapped = false;
  int left = 0, right = n - 1;
  while (true) {
    if (left >= right) {
      break;
    }
    // forward pass
    swapped = false;
    for (int i = left; i < right; i++) {
      if (++comparisons && input[i] > input[i + 1]) {
        swap(input[i], input[i + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
    right--;

    // backward pass
    swapped = false;
    for (int i = right; i > left; i--) {
      if (++comparisons && input[i] < input[i - 1]) {
        swap(input[i], input[i - 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
    left++;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}