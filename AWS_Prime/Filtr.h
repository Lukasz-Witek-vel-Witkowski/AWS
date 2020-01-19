#pragma once
#include "Position.h"
#include <vector>
#include <iostream>
#include "MaxValue.h"
#include "Canal.h"
#include <limits>
#include <iomanip>
#define parametr_graniczny 25
class Filtr
{
	bool type;
	int precent;
	int number;
	long double Noise;
	Canal* V_base;
	std::vector<MaxValue> V_area;
	std::vector<int> V_instance;
	Position P_makismum;
	Position pValueMax;
	Position pValueMin;
public:
	Filtr(Canal* V_pos);
	std::vector<MaxValue> filtration();
	void setPrecent(int p);
	void findingNoise();
	void setType(bool b); //value TRUE = maksimum / value FALSE = minimum
	int getNumber();
	~Filtr();
};

