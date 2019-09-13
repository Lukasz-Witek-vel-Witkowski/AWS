#include "BaseFileConfig.h"

BaseFileConfig::BaseFileConfig() { position = 0; }
void BaseFileConfig::setCharsSkip(std::string Skip) {
	skip = Skip;
}
void BaseFileConfig::setPosition(int pos) {
	position = pos;
}
void BaseFileConfig::setEnd(std::string End) {
	end = End;
}
void BaseFileConfig::run(std::string path) {
	std::ifstream file(path);
	std::string data = "";
	while (file.good()) {
		std::getline(file, data);
		std::cout << data << " - " << data.find(end) << " - " << end << "\n";
		if (data.find(skip) != position) {
			Parameter[data.substr(0, data.find(C))] = data.substr(data.find(C) + 1);
			std::cout << data << " - " << data.substr(0, data.find(C)) << " - " << data.substr(data.find(C) + 1) << "-" << data.find(C) << "\n";
			continue;
		}
		if (data.find(end) == position) break;
	}
}
void BaseFileConfig::setCharWall(char c) {
	C = c;
}
BaseFileConfig::~BaseFileConfig() {};