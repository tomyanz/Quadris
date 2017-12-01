#include "level0.h"
#include <fstream>


Level0::Level0():
	Level{LevelType::Level0, false, true} {}


void setIsRandom(bool isRandom) {}


void setFileName(string fileName) {
	this->fileName = filename;
}


void setFileStream(ifstream &fileStream) {
	this->fileStream = fileStream;
}


// Block constructor
// Block(LevelType level, DisplayFormat format)
shared_ptr<Block> Level0::generateBlock() {
	string input;
	BlockType blockType;
	if (getFileStream() >> input) {
		if (input == "I") {
			return make_shared<IBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else if (input == "J") {
                        return make_shared<JBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else if (input == "L") {
                        return make_shared<LBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else if (input == "O") {
                        return make_shared<OBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else if (input == "S") {
                        return make_shared<SBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else if (input == "Z") {
                        return make_shared<ZBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else if (input == "T") {
                        return make_shared<TBlock>(LevelType::Level0, DisplayFormat::Standard);
		}
		else {
			//////// throw exception for invalid input?????
		}
	}
// no Current enumeration
}


shared_ptr<Block>obstacle(Pair<int,int> &) {
	return nullptr;
}