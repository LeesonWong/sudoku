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
      this->OverProcess();
      break;
    default:
      break;
  }
}


void Game::Start() {
  std::cout << "\t" << "Game Start" << std::endl;
  std::cout << "\t" << "Exit" << std::endl;

  std::string str;
  std::cin >> str;
  while (true) {
    if(str == "1") {
      this->MenuProcess();
      return;
    } else if (str == "2") {
      this->OverProcess();
      return;
    }
  }
}

void Game::MenuProcess() {
  this->State = MENU;
  Util::LOG("请输入矩阵大小：3 * X");
  std::string str;
  std::cin >> str;
  sudoku = std::make_unique<Sudoku>(std::stoi(str));
}

void Game::PlayingProcess() {
  if(!sudoku) {
    Util::LOG("Playing illegal state");
  }
  Util::LOG("Playing sudoku");
}

void Game::ComputedProcess() {
  this->MenuProcess();
}

void Game::OverProcess() {
  // 释放资源
}
