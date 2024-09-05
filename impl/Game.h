#ifndef GAME_H
#define GAME_H
#include "Sudoku.h"
#include <string>

enum GameState {
  INIT,
  MENU,
  PLAYING,
  COMPUTED,
  OVER,
};
extern const int SLEEP_SLOT;

/**
* Game本质上是一个有限状态机 对外只需要关心game是否结束，
*/
class Game {
public:
  Game();
  ~Game();

  // 游戏是否已结束 结束后不能再重启 菜单界面可选择新游戏
  bool IsOver();

  void Process();
private:
  // 是否已结束游戏对象生命周期
  GameState State;
  std::unique_ptr<Sudoku> sudoku;

  // 必须显示声明启动游戏
  void Start();
  // 到menu状态
  void MenuProcess();

  void PlayingProcess();

  void ComputedProcess();

  void OverProcess();
};
#endif //GAME_H
