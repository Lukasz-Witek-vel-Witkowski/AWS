#pragma once
class Position
{
	long iterator;
	long double value;
public:
	Position();
	void setValue(long iterator, long double value);
	Position(const Position& p);
	Position& operator = (const Position& p);
	bool operator==(const Position& p);
	bool operator!=(const Position& p);
	bool operator<(const Position& p);
	bool operator<=(const Position& p);
	bool operator>(const Position& p);
	long getIterator();
	long double getValue();
	~Position();
};