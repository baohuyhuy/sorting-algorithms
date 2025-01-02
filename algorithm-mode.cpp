#include "algorithm-mode.h"
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include "algorithms.h"
#include "utils.h"

using namespace std;

void printMeasuredData(pair<long long, int> data, string outputParam) {
  long long time;
  int comparisons;
  tie(time, comparisons) = data;
  cout << "---------------------------------" << endl;
  if (outputParam == TIME) {
    cout << "Running time: " << time << " ms" << endl;
  } else if (outputParam == COMPARISONS) {
    cout << "Comparisons: " << comparisons << endl;
  } else if (outputParam == BOTH) {
    cout << "Running time: " << time << " ms" << endl;
    cout << "Comparisons: " << comparisons << endl;
  }
}

void runAlgorithmMode(int argc, char* argv[]) {
  string algorithm = argv[2];
  // check if the algorithm is valid
  if (!isValidAlgorithm(algorithm)) {
    cout << "Invalid argument 2" << endl;
    exit(1);
  }

  // check if the input is given or automatically generated
  string inputFilename = "";
  int inputSize = 0;
  try {
    inputSize = stoi(argv[3]);
  } catch (...) {
    inputFilename = argv[3];
  }

  // create the input
  vector<vector<int>> input;
  string inputOrder = "";
  if (inputSize) {
    // input is automatically generated

    // check if the input size is valid
    if (!isValidInputSize(inputSize)) {
      cout << "Invalid argument 3" << endl;
      exit(1);
    }

    // check if the input order is valid
    inputOrder = argv[4];
    if (!isValidInputOrder(inputOrder)) {
      inputOrder = ALL_ORDERS;
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

  // check if the output parameter is valid
  string outputParam = "";
  if (inputSize && inputOrder != ALL_ORDERS) {
    if (argc < 6) {
      cout << "Not enough arguments" << endl;
      exit(1);
    }
    outputParam = argv[5];
    if (!isValidOutputParam(outputParam)) {
      cout << "Invalid argument 5" << endl;
      exit(1);
    }
  } else {
    outputParam = argv[4];
    if (!isValidOutputParam(outputParam)) {
      cout << "Invalid argument 4" << endl;
      exit(1);
    }
  }

  // run the algorithm
  cout << "ALGORITHM MODE" << endl;
  cout << "Algorithm: " << getAlgorithmCapitalName(algorithm) << endl;
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
    printMeasuredData(sortDataByAlgorithm(algorithm, input[0]), outputParam);
    writeDataToFile(input[0], "output.txt");
  } else {
    for (int i = 0; i < input.size(); i++) {
      cout << "Input order: " << INPUT_ORDER_CAPITAL_NAME[i] << endl;
      printMeasuredData(sortDataByAlgorithm(algorithm, input[i]), outputParam);
      cout << endl;
    }
  }
}