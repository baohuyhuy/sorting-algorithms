#pragma once

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

pair<long long, long long> selectionSort(vector<int>&);

pair<long long, long long> insertionSort(vector<int>&);

pair<long long, long long> binaryInsertionSort(vector<int>&);

pair<long long, long long> bubbleSort(vector<int>&);

pair<long long, long long> shakerSort(vector<int>&);

pair<long long, long long> shellSort(vector<int>&);

pair<long long, long long> heapSort(vector<int>&);

pair<long long, long long> mergeSort(vector<int>&);

pair<long long, long long> quickSort(vector<int>&);

pair<long long, long long> countingSort(vector<int>&);

pair<long long, long long> radixSort(vector<int>&);

pair<long long, long long> flashSort(vector<int>&);

pair<long long, long long> sortDataByAlgorithm(string, vector<int>&);
