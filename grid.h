#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <utility>

#include "block.h"
#include "cell.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "observer.h"
#include "info.h"
#include "state.h"
#include "gameState.h"

class Grid {
  std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
  std::unique_ptr<Level> theLevel;
  std::shared_ptr<Block> currentBlock;
  std::shared_ptr<Block> nextBlock;
  std::shared_ptr<Block> hintBlock;
  std::vector<std::shared_ptr<Observer<Info, State>>> ob;
  std::pair<int, int> currentLeftBottom;
  std::pair<int, int> hintLeftBottom;

  const int width = 11;
  const int height = 15;

  int score = 0;
  int player2Score = 0;
  int highScore = 100;
  bool gameOver = false;
  bool twoPlayer = false;
  bool isMainPlayer = true;

  void checkHint();
  void setLevel(LevelType level, int seed = 1, std::string fileName = "");
  void checkRows();
  void placeLowest();
  bool checkValid(std::vector<std::pair<int, int>> coordinates);
  void attach(std::vector<std::pair<int, int>> &v, bool initial = false);
  void detach(std::vector<std::pair<int, int>> &v);
  void addScore(bool isLine, LevelType level, int numLines);

  public:
  ~Grid();

  GameState getGameState() const;
  void left(int);
  void right(int);
  void down(int n, bool heavy = false);
  void clockwise(int);
  void counterClockwise(int);
  void drop(int);
  void levelUp(int);
  void levelDown(int, std::string fileName = "sequence.txt");
  void random(bool isRandom, std::string fileName = "");
  void setBlock(BlockType type);
  void init(LevelType level, int seed, std::string fileName = "", bool twoPlayer = false);
  void hint();
  void attachObserver(std::shared_ptr<Observer<Info, State>> ob);
  void detachObserver(std::shared_ptr<Observer<Info, State>> ob);

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
