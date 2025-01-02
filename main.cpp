#include <iostream>
#include <string>
#include "algorithm-mode.h"

using namespace std;

int main(int argc, char* argv[]) {
  // check if enough arguments are provided
  if (argc < 5) {
    cout << "Not enough arguments" << endl;
    exit(1);
  }

  // check if the mode is valid
  string mode = argv[1];
  if (mode == "-a") {
    runAlgorithmMode(argc, argv);
  } else if (mode == "-c") {
    // runComparisonMode();
  } else {
    cout << "Invalid argument 1" << endl;
    exit(1);
  }

  // return 0;
}