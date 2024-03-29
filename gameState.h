#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include "info.h"

struct GameState{
 bool gameOver;
 LevelType level;
 int playScore;
 int highScore;
 BlockType nextBlock;
 std::vector<std::pair<int, int>> nextBlockCoords;
 bool twoPlayer;
 int player2Score;
 bool isMainPlayer;
};

#endif

