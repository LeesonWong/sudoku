#include <thread>
#include <iostream>
#include <chrono>

#include "Util.h"
#include "Game.h"

// 500ms
const int SLEEP_SLOT = 100;

Game::Game() : State(INIT) {}

Game::~Game() {}

bool Game::IsOver() {
  // sleep for SLEEP_SLOT
  std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_SLOT));
  auto res = this->State == OVER;
  if(res) {

  }
  return res;
}

void Game::Process() {
  switch (this->State) {
    case INIT:
      this->Start();
      break;
    case MENU:
      this->MenuProcess();
      break;
    case PLAYING:
      this->PlayingProcess();
      break;
    case COMPUTED:
      this->ComputedProcess();
      break;
    case OVER:
      // here is impossible in principle
      this->OverProcess();
      break;
    default:
      break;
  }
}


void Game::Start() {
  std::cout << "\t" << "Game Start" << std::endl;
  std::cout << "\t" << "Exit" << std::endl;

  std::cin >> this->operation;
  while (true) {
    if(this->operation == "1") {
      this->MenuProcess();
      return;
    } else if (this->operation == "2") {
      this->OverProcess();
      return;
    }
  }
}

void Game::MenuProcess() {
  this->State = MENU;
  std::cout << "请输入矩阵大小：3 * X" << std::endl;
  std::cin >> this->operation;
  sudoku = std::make_unique<Sudoku>(std::stoi(this->operation));
}

void Game::PlayingProcess() {
  if(!sudoku) {
    std::cout << "Playing illegal state" << std::endl;
  }
  std::cout << "Playing sudoku" << std::endl;
}

void Game::ComputedProcess() {
  this->MenuProcess();
}

void Game::OverProcess() {
  // 释放资源
  this->State = OVER;
}
