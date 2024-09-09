#ifndef SUDOKU_H
#define SUDOKU_H
#include <cstdint>
#include <map>
#include <set>
#include <vector>

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
  std::set<int> checkSet;

  std::set<std::pair<int, int>> CreateBoard(std::vector<std::vector<int>>& data);
};
#endif // SUDOKU_H
