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

class Grid {
  std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
  std::unique_ptr<Level> theLevel;
  std::shared_ptr<Block> currentBlock;
  std::shared_ptr<Block> nextBlock;
  std::vector<std::shared_ptr<Observer<Info, State>>> ob;
  std::pair<int, int> currentLeftBottom;

  const int width = 11;
  const int height = 15;

  int score;
  int highScore;
  
  void setLevel();
  void checkRows();
  void placeLowest();
  bool checkValid(std::vector<std::pair<int, int>> coordinates);
  void attachDetach(std::vector<std::pair<int, int>> &o, std::vector<std::pair<int, int>> &c);

  public:
  ~Grid();

  void addScore(bool isLine, LevelType level, int numLines);
  void left(int);
  void right(int);
  void down(int);
  void clockwise(int);
  void counterClockwise(int);
  void drop(int);
  void levelUp(int);
  void levelDown(int);
  void random(bool isRandom, std::string fileName = "");
  void setBlock(BlockType type);
  void init(LevelType level, bool isRandom = true, std::string fileName = "");
  void hint();
  void attachObserver(std::shared_ptr<Observer<Info, State>> ob);
  void detachObserver(std::shared_ptr<Observer<Info, State>> ob);

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
