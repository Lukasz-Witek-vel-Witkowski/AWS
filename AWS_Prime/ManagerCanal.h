#pragma once
#include <vector>
#include "MaxValue.h"
#include <iostream>
class ManagerCanal
{
	std::vector<std::vector<MaxValue>> V_max;
public:
	enum Value
	{
		C_Orgin,
		C_2_80,
		C_6_60
	};
	ManagerCanal();
	void veryfication();
	void position();
	void reset();
	void setMax(std::vector<MaxValue> m, Value c);
	long double getcoefficient2_80(int value);
	long double getcoefficient6_60(int value);
	void cout();
	int getSize(int j);
	~ManagerCanal();
};

