#include "algorithms.h"

void heapify(vector<int>& input, int n, int i, int& comparisons) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && ++comparisons && input[left] > input[largest]) {
    largest = left;
  }

  if (right < n && ++comparisons && input[right] > input[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(input[i], input[largest]);
    heapify(input, n, largest, comparisons);
  }
}

pair<long long, int> heapSort(vector<int>& input) {
  int n = input.size();
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(input, n, i, comparisons);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(input[0], input[i]);
    heapify(input, i, 0, comparisons);
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
