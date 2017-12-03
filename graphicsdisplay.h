#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "info.h"
#include "observer.h"
#include "state.h"
#include "window.h"
#include "gameState.h"
class Cell;

class GraphicsDisplay: public Observer<Info, State> {
  const int winWidth, winHeight, cellSize;
  const int gridWidth = 11, gridHeight = 15;
  const int blankColour = Xwindow::White;
  Xwindow xw;
  int gridXShift, gridYShift;

  std::vector<std::vector<std::pair<bool,int>>> grid;
  std::vector<std::pair<std::pair<int, int>, int>> queue;
  bool needShift;
  int maxRowShift;

  int colourDefinition(BlockType type, DisplayFormat format) const;

 public:
  GraphicsDisplay(int gridSize, int winSize);

  void redraw(GameState gameState);
  void notify(std::shared_ptr<Subject<Info, State>> whoNotified) override;
};
#endif
