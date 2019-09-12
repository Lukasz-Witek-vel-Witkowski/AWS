#pragma once
#include <string>
struct Block {
	std::string NameFile;
	double value60MHz;
	double value80MHz;
	Block(std::string data, double c60, double c80) {
		NameFile = data;
		value60MHz = c60;
		value80MHz = c80;
	}
	~Block(){}
};
