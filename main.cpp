#include <Game.h>
#include <chrono>

#include <GlobalConfig.h>
#include <Util.h>
#include <iostream>

using namespace std;

int main() {
  Game game;
  std::string str;

  Util::LOG("选择语言 1、中文 2、英文");
  std::cin >> str;
  Util::LOG(str);

  while (!game.IsOver()) {
    game.Process();
  }
  Util::LOG("Game Over");
}