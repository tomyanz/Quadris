#include "level.h"
#include "invalidfileexcept.h"
#include "invalidshapeexcept.h"
#include <string>
using namespace std;

Level::Level(LevelType level, bool isHeavy, bool isRandom, int seed, string fileName):
 level{level}, isHeavy{isHeavy}, isRandom{isRandom}, seed{seed}, fileName{fileName}{
  srand(seed);
}

Level::~Level() {}

LevelType Level::getLevel() {
	return level;
}

bool Level::getIsHeavy() {
	return isHeavy;
}

bool Level::getIsRandom() {
	return isRandom;
}

int Level::getSeed() {
	return seed;
}

shared_ptr<Block> Level::makeBlock(BlockType type, LevelType level, DisplayFormat format){
  shared_ptr<Block> block = nullptr;
  if (type == BlockType::IBlock) {
    block = make_shared<IBlock>(level, format);
  }
  else if (type == BlockType::JBlock) {
    block = make_shared<JBlock>(level, format);
  }
  else if (type == BlockType::LBlock) {
    block = make_shared<LBlock>(level, format);
  }
  else if (type == BlockType::OBlock) {
    block = make_shared<OBlock>(level, format);
  }
  else if (type == BlockType::SBlock) {
    block = make_shared<SBlock>(level, format);
  }
  else if (type == BlockType::ZBlock) {
    block = make_shared<ZBlock>(level, format);
  }
  else if (type == BlockType::TBlock) {
    block = make_shared<TBlock>(level, format);
  }
  else if (type == BlockType::OneCellBlock) {
    block = make_shared<OneCellBlock>(level, format);
  }
  //throw exception for an else??
  return block;
}

BlockType Level::inputInterpreter(string input){
  BlockType type;
  if (input == "I")  type = BlockType::IBlock;
  else if (input == "J") type = BlockType::JBlock;
  else if (input == "L") type = BlockType::LBlock;
  else if (input == "O") type = BlockType::OBlock;
  else if (input == "S") type = BlockType::SBlock;
  else if (input == "Z") type = BlockType::ZBlock;
  else if (input == "T") type = BlockType::TBlock;
  else type = BlockType::None;
  return type;
}

