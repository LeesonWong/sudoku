#include <Game.h>
#include <chrono>

#include <GlobalConfig.h>
#include <Util.h>
#include <iostream>

using namespace std;

int main() {
  Game game;
  std::string str;

  std::cout << "ѡ������ 1������ 2��Ӣ��" << std::endl;
  std::cin >> str;
  // Util::LOG(str);

  while (!game.IsOver()) {
    game.Process();
  }
  Util::LOG("Game Over");
}