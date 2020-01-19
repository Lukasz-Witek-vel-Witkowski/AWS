#pragma once
#include <vector>
#include "Position.h"
class MaxValue
{
	Position Max;
	std::vector<Position> V_position;
public:
	MaxValue();
	MaxValue(const MaxValue& m);
	MaxValue& operator=(const MaxValue& m);
	void setValue(Position& p);
	void setMax(Position& p);
	Position& getMax();
	std::vector<Position>& getVector();
	bool operator==(const MaxValue& m);
	~MaxValue();
};

