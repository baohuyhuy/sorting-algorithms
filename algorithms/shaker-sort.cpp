#include "algorithms.h"

pair<long long, long long> shakerSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  bool swapped = false;
  int left = 0, right = n - 1;
  while (true) {
    if (++comparisons && left >= right) {
      break;
    }
    // forward pass
    swapped = false;
    for (int i = left; ++comparisons && i < right; i++) {
      if (++comparisons && arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
    right--;

    // backward pass
    swapped = false;
    for (int i = right; ++comparisons && i > left; i--) {
      if (++comparisons && arr[i] < arr[i - 1]) {
        swap(arr[i], arr[i - 1]);
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