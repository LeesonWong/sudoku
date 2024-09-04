#include <iostream>

#include <Sudoku.h>
#include <GlobalConfig.h>

using namespace std;

int main() {
  // Sudoku sudoku;
  auto config = GlobalConfig::GetInstance();
  config.Print();

  cout << "Hello World!" << endl;
}