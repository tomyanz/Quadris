#ifndef LEVEL1_H
#define LEVEL1_H
#include <memory>
#include "level.h"
class Block;

class Level1 : public Level {
	public:
	Level1(int seed);
	void setIsRandom(bool isRandom, std::string fileName = "") override;
	std::shared_ptr<Block> generateBlock(BlockType type = BlockType::None) override;
	std::shared_ptr<Block> obstacle(std::pair<int,int> &) override;
};

#endif
