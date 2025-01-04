#include "algorithms.h"

void merge(vector<int>& input,
           int left,
           int mid,
           int right,
           int& comparisons,
           vector<int>& temp) {
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right) {
    if (++comparisons && input[i] <= input[j]) {
      temp[k++] = input[i++];
    } else {
      temp[k++] = input[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = input[i++];
  }

  while (j <= right) {
    temp[k++] = input[j++];
  }

  for (int l = left; l <= right; l++) {
    input[l] = temp[l];
  }
}

void mergeSortHelper(vector<int>& input,
                     int left,
                     int right,
                     int& comparisons,
                     vector<int>& temp) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  mergeSortHelper(input, left, mid, comparisons, temp);
  mergeSortHelper(input, mid + 1, right, comparisons, temp);
  merge(input, left, mid, right, comparisons, temp);
}

pair<long long, int> mergeSort(vector<int>& input) {
  int comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  vector<int> temp(input.size());
  mergeSortHelper(input, 0, input.size() - 1, comparisons, temp);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
