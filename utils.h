#pragma once
#include <string>
#include <vector>

using namespace std;

// sort algorithms
const string SELECTION_SORT = "selection-sort";
const string INSERTION_SORT = "insertion-sort";
const string BINARY_INSERTION_SORT = "binary-insertion-sort";
const string BUBBLE_SORT = "bubble-sort";
const string SHAKER_SORT = "shaker-sort";
const string SHELL_SORT = "shell-sort";
const string HEAP_SORT = "heap-sort";
const string MERGE_SORT = "merge-sort";
const string QUICK_SORT = "quick-sort";
const string COUNTING_SORT = "counting-sort";
const string RADIX_SORT = "radix-sort";
const string FLASH_SORT = "flash-sort";
const string SORT_ALGORITHMS[] = {
    SELECTION_SORT, INSERTION_SORT, BINARY_INSERTION_SORT,
    BUBBLE_SORT,    SHAKER_SORT,    SHELL_SORT,
    HEAP_SORT,      MERGE_SORT,     QUICK_SORT,
    COUNTING_SORT,  RADIX_SORT,     FLASH_SORT};

// input orders
const string RANDOM = "-rand";
const string NEARLY_SORTED = "-nsorted";
const string SORTED = "-sorted";
const string REVERSE_SORTED = "-rev";
const string ALL_ORDERS = "-all";
const string INPUT_ORDER_CAPITAL_NAME[] = {"Randomize", "Nearly Sorted",
                                           "Sorted", "Reversed"};
const vector<string> INPUT_ORDERS = {RANDOM, NEARLY_SORTED, SORTED,
                                     REVERSE_SORTED};

// input sizes
const vector<int> INPUT_SIZES = {10000, 30000, 50000, 100000, 300000, 500000};

// output parameters
const string TIME = "-time";
const string COMPARISONS = "-comp";
const string BOTH = "-both";

bool isValidAlgorithm(string);
string getAlgorithm(string);

bool isValidInputSize(int);

bool isValidInputOrder(string);

bool isValidOutputParam(string);

vector<vector<int>> generateInput(int, string);

vector<vector<int>> readInput(ifstream&);

void writeDataToFile(vector<int>&, string);

string getAlgorithmCapitalName(string);

string getInputOrderCapitalName(string);