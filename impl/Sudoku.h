#ifndef SUDOKU_H
#define SUDOKU_H
#include <cstdint>
#include <vector>
#include <set>

class Sudoku {
public:
  Sudoku(uint8_t);
  ~Sudoku();
  bool Place(int, int, int);
  bool Check();
  void Show();
private:
  uint8_t partLen;
  std::vector<std::vector<int>> data;
  std::set<std::pair<int, int>> pos;
};
#endif // SUDOKU_H
