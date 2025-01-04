#include "algorithms.h"

int partition(vector<int>& input, int left, int right, int& comparisons) {
  int pivotIndex = left + rand() % (right - left + 1);  // random pivot
  swap(input[left], input[pivotIndex]);
  pivotIndex = left;
  int storeIndex = left + 1;

  for (int i = left + 1; i <= right; i++) {
    if (++comparisons && input[i] < input[pivotIndex]) {
      swap(input[i], input[storeIndex++]);
    }
  }
  swap(input[left], input[--storeIndex]);
  return storeIndex;
}

void quickSortHelper(vector<int>& input,
                     int left,
                     int right,
                     int& comparisons) {
  if (left >= right) {
    return;
  }
  int p = partition(input, left, right, comparisons);
  quickSortHelper(input, left, p - 1, comparisons);
  quickSortHelper(input, p + 1, right, comparisons);
}

pair<long long, int> quickSort(vector<int>& input) {
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  srand(time(0));
  quickSortHelper(input, 0, input.size() - 1, comparisons);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
