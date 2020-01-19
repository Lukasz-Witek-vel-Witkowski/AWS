#pragma once
#include <vector>
#include "Position.h"
class Canal
{
	std::vector<Position> V_position;
public:
	Canal();
	Canal(const Canal& c);
	Canal& operator=(const Canal& c);
	std::vector<Position>& getVector();
	bool operator==(const Canal& c);
	void setValue(Position& p);
	~Canal();
};

