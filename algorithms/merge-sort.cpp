#include "algorithms.h"

void merge(vector<int>& arr,
           int left,
           int mid,
           int right,
           long long& comparisons,
           vector<int>& temp) {
  int i = left;
  int j = mid + 1;
  int k = left;

  while (++comparisons && i <= mid && ++comparisons && j <= right) {
    if (++comparisons && arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (++comparisons && i <= mid) {
    temp[k++] = arr[i++];
  }

  while (++comparisons && j <= right) {
    temp[k++] = arr[j++];
  }

  for (int l = left; ++comparisons && l <= right; l++) {
    arr[l] = temp[l];
  }
}

void mergeSortHelper(vector<int>& arr,
                     int left,
                     int right,
                     long long& comparisons,
                     vector<int>& temp) {
  if (++comparisons && left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  mergeSortHelper(arr, left, mid, comparisons, temp);
  mergeSortHelper(arr, mid + 1, right, comparisons, temp);
  merge(arr, left, mid, right, comparisons, temp);
}

pair<long long, long long> mergeSort(vector<int>& arr) {
  int n = arr.size();
  vector<int> temp(n);
  long long comparisons = 0;
  auto start = chrono::high_resolution_clock::now();

  mergeSortHelper(arr, 0, n - 1, comparisons, temp);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  return {duration.count(), comparisons};
}
