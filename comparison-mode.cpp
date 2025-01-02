#include "comparison-mode.h"
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "algorithms.h"
#include "utils.h"

using namespace std;

void printMeasuredData(pair<long long, int> data1, pair<long long, int> data2) {
  long long time1, time2;
  int comparisons1, comparisons2;
  tie(time1, comparisons1) = data1;
  tie(time2, comparisons2) = data2;
  cout << "---------------------------------" << endl;
  cout << "Running time: " << time1 << " ms | " << time2 << " ms" << endl;
  cout << "Comparisons: " << comparisons1 << " | " << comparisons2 << endl;
}

void runComparisonMode(int argc, char* argv[]) {
  // check if algorithm 1 is valid
  string algorithm1 = argv[2];
  if (!isValidAlgorithm(algorithm1)) {
    cout << "Invalid argument 2" << endl;
    exit(1);
  }

  // check if algorithm 2 is valid
  string algorithm2 = argv[3];
  if (!isValidAlgorithm(algorithm2)) {
    cout << "Invalid argument 3" << endl;
    exit(1);
  }

  // check if the input is given or automatically generated
  string inputFilename = "";
  int inputSize = 0;
  try {
    inputSize = stoi(argv[4]);
  } catch (...) {
    inputFilename = argv[4];
  }

  // create the input
  vector<vector<int>> input;
  string inputOrder = "";
  if (inputSize) {
    // input is automatically generated

    // check if the input size is valid
    if (!isValidInputSize(inputSize)) {
      cout << "Invalid argument 4" << endl;
      exit(1);
    }

    // check if the input order is valid
    if (argc < 6) {
      inputOrder = ALL_ORDERS;
    } else {
      inputOrder = argv[5];
      if (!isValidInputOrder(inputOrder)) {
        cout << "Invalid argument 5" << endl;
        exit(1);
      }
    }

    input = generateInput(inputSize, inputOrder);
  } else {
    // input is given

    ifstream file(inputFilename);

    // check if the input file is valid
    if (!file) {
      cout << "Invalid argument 3" << endl;
      exit(1);
    }

    input = readInput(file);
    file.close();
  }

  cout << "COMPARE MODE" << endl;
  cout << "Algorithm: " << getAlgorithmCapitalName(algorithm1) << " | "
       << getAlgorithmCapitalName(algorithm2) << endl;
  if (inputSize) {
    cout << "Input size: " << inputSize << endl;
    if (inputOrder != ALL_ORDERS) {
      cout << "Input order: " << getInputOrderCapitalName(inputOrder) << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << "Input file: " << inputFilename << endl;
    cout << "Input size: " << input[0].size() << endl;
  }
  if (input.size() == 1) {
    vector<int> input1 = input[0];
    vector<int> input2 = input[0];
    printMeasuredData(sortDataByAlgorithm(algorithm1, input1),
                      sortDataByAlgorithm(algorithm2, input2));
    writeDataToFile(input1, "output.txt");
  } else {
    for (int i = 0; i < input.size(); i++) {
      vector<int> input1 = input[i];
      vector<int> input2 = input[i];
      cout << "Input order: " << INPUT_ORDER_CAPITAL_NAME[i] << endl;
      printMeasuredData(sortDataByAlgorithm(algorithm1, input1),
                        sortDataByAlgorithm(algorithm2, input2));
      cout << endl;
    }
  }
}