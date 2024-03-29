#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock : public Block, public std::enable_shared_from_this<JBlock>{
  std::vector<std::pair<int, int>> baseGetCoordinates(int rotState, std::pair<int, int> leftBottom) const override;
  std::shared_ptr<Block> getThisPtr() override;

  public:
  JBlock(LevelType level, DisplayFormat format);
  virtual ~JBlock();
};

#endif

