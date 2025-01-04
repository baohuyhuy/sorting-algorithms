#include "algorithms.h"

void heapify(vector<int>& arr, int n, int i, long long& comparisons) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (++comparisons && left < n && ++comparisons &&
      arr[left] > arr[largest]) {
    largest = left;
  }

  if (++comparisons && right < n && ++comparisons &&
      arr[right] > arr[largest]) {
    largest = right;
  }

  if (++comparisons && largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest, comparisons);
  }
}

pair<long long, long long> heapSort(vector<int>& arr) {
  int n = arr.size();
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = n / 2 - 1; ++comparisons && i >= 0; i--) {
    heapify(arr, n, i, comparisons);
  }
  for (int i = n - 1; ++comparisons && i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0, comparisons);
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
