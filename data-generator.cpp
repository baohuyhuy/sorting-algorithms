#include <time.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> generateRandomData(int size) {
  srand((unsigned int)time(NULL));

  vector<int> data(size);
  for (int i = 0; i < size; i++) {
    data[i] = rand() % size;
  }
  return data;
}

vector<int> generateNearlySortedData(int size) {
  vector<int> data(size);
  for (int i = 0; i < size; i++) {
    data[i] = i;
  }
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    int r1 = rand() % size;
    int r2 = rand() % size;
    swap(data[r1], data[r2]);
  }
  return data;
}

vector<int> generateSortedData(int size) {
  vector<int> data(size);
  for (int i = 0; i < size; i++) {
    data[i] = i;
  }
  return data;
}

vector<int> generateReverseData(int size) {
  vector<int> data(size);
  for (int i = 0; i < size; i++) {
    data[i] = size - 1 - i;
  }
  return data;
}

vector<int> generateData(int size, int dataType) {
  switch (dataType) {
    case 0:  // random
      generateRandomData(size);
      break;
    case 1:  // sorted
      generateSortedData(size);
      break;
    case 2:  // reverse sorted
      generateReverseData(size);
      break;
    case 3:  // nearly sorted
      generateNearlySortedData(size);
      break;
    default:
      cout << "Error: unknown data type!" << endl;
  }
}