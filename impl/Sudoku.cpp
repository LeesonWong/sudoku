#include "Sudoku.h"
#include <iostream>
#include <random>

std::set<std::pair<int, int>> Sudoku::CreateBoard(std::vector<std::vector<int>>& data) {
  std::random_device rd;
  std::mt19937 gen(rd()); // 使用 Mersenne Twister 算法生成随机数
  std::uniform_int_distribution<> dis(1, 9); // 设定范围为 1 到 100

  std::set<int> numSet1; // 行
  std::set<int> numSet2; // 列
  std::set<int> numSet3; // 块

  std::vector<std::pair<int, int>> rangeList = {
    {3,3},
    {0, 3},
    {3, 6},
    {6, 3},
    {3, 0},
    {0, 0},
    {0, 6},
    {6, 0},
    {6, 6},
  };


  for (auto rangePair : rangeList) {
    std::set<int> tryNumSet;
    BuildPart:
    numSet3.clear();
    for (int i = rangePair.first; i < rangePair.first + 3; ++i) {
      for (int j = rangePair.second; j < rangePair.second + 3; ++j) {
        this->data[i][j] = 0;
      }
    }
    for (int i = rangePair.first; i < rangePair.first + 3; ++i) {
      for (int j = rangePair.second; j < rangePair.second + 3; ++j) {
        numSet1.clear();
        numSet2.clear();
        for (int k = 0; k < this->partLen * 3; ++k) {
          if(this->data[i][k] != 0) {
            numSet1.insert(this->data[i][k]);
          }
          if(this->data[k][j] != 0) {
            numSet2.insert(this->data[k][j]);
          }
        }
        bool finished = false;
        int num = dis(gen);
        tryNumSet.clear();
        while (!finished) {
          tryNumSet.insert(num);
          if((numSet1.find(num) == numSet1.end()) && (numSet2.find(num) == numSet2.end()) && (numSet3.find(num) == numSet3.end())) {
            numSet3.insert(num);
            this->data[i][j] = num;
            finished = true;
          }
          if(tryNumSet.size() >= 9) {
            goto BuildPart;
          }
          num = (num == 9) ? 1 : (num + 1);
        }
      }
    }
  }
  return std::set<std::pair<int, int>>();
}

Sudoku::Sudoku(const uint8_t len) {
  this->partLen = len;
  for (int i = 0; i < this->partLen * 3; i++) {
    this->checkSet.insert(i + 1);
  }
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
  std::set<int> set1;
  std::set<int> set2;
  std::set<int> set3;

  for (int i = 0; i < this->partLen * 3; i++) {
    set1.clear();
    for (int j = 0; j < this->partLen * 3; j++) {
      auto num = this->data[i][j];
      if(checkSet.find(num) == checkSet.end() || set1.find(num) != set1.end()) {
        return false;
      }
      set1.insert(num);
    }
  }
  for (int i = 0; i < this->partLen * 3; i++) {
    set2.clear();
    for (int j = 0; j < this->partLen * 3; j++) {
      auto num = this->data[j][i];
      if(checkSet.find(num) == checkSet.end() || set2.find(num) != set2.end()) {
        return false;
      }
      set2.insert(num);
    }
  }
  for (int i = 0; i < this->partLen; i++) {
    for (int j = 0; j < this->partLen; j++) {
      set3.clear();
      for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
          auto num = this->data[i * 3 + x][j * 3 + y];
          if(checkSet.find(num) == checkSet.end() || set3.find(num) != set3.end()) {
            return false;
          }
          set3.insert(num);
        }
      }
    }
  }

  return true;
}

void Sudoku::Show() {
  for (const auto& row : data) {
    for (auto item : row) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
}
