#include "Sudoku.h"
#include <iostream>

std::set<std::pair<int, int>> CreateBoard(std::vector<std::vector<int>>& data) {

}

Sudoku::Sudoku(const uint8_t len) {
  this->partLen = len;
  this->data = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
  };
  pos = CreateBoard(this->data);
}

Sudoku::~Sudoku() {}

bool Sudoku::Place(int x, int y, int num) {
  if(this->pos.find(std::pair(x, y)) != this->pos.end()) {
    return false;
  }
  data[x][y] = num;
  return true;
}

bool Sudoku::Check() {
  bool res = true;

  return res;
}

void Sudoku::Show() {
  for (const auto& row : data) {
    for (auto item : row) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
}
