#ifndef SUDOKU_H
#define SUDOKU_H
#include <cstdint>
#include <vector>
class Sudoku {
public:
  Sudoku(uint8_t);
  ~Sudoku();
  void Place(uint16_t, uint16_t, uint8_t);
  bool Check();
  int temp;

private:
  uint8_t partLen;
  std::vector<std::vector<uint8_t>> data;
};
#endif // SUDOKU_H
