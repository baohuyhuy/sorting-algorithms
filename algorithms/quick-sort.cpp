#include "algorithms.h"

int partition(vector<int>& arr, int left, int right, long long& comparisons) {
  int pivotIndex = left + rand() % (right - left + 1);  // random pivot
  swap(arr[left], arr[pivotIndex]);
  pivotIndex = left;
  int storeIndex = left + 1;

  for (int i = left + 1; ++comparisons && i <= right; i++) {
    if (++comparisons && arr[i] < arr[pivotIndex]) {
      swap(arr[i], arr[storeIndex++]);
    }
  }
  swap(arr[left], arr[--storeIndex]);
  return storeIndex;
}

void quickSortHelper(vector<int>& arr,
                     int left,
                     int right,
                     long long& comparisons) {
  if (++comparisons && left >= right) {
    return;
  }
  int p = partition(arr, left, right, comparisons);
  quickSortHelper(arr, left, p - 1, comparisons);
  quickSortHelper(arr, p + 1, right, comparisons);
}

pair<long long, long long> quickSort(vector<int>& arr) {
  srand(time(0));
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  quickSortHelper(arr, 0, arr.size() - 1, comparisons);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
