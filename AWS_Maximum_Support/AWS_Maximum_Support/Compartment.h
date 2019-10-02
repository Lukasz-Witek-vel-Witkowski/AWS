#pragma once
#include<iostream>
#include <string>
class Compartment
{
	double start;
	double stop;
	unsigned int value;
public:
	Compartment(double Start, double Stop);
	bool operator==(Compartment &C);
	Compartment& operator=(Compartment &C);
	friend std::ostream& operator<<(std::ostream &is, Compartment &P);
	void addValue();
	bool comparison(double parameter);
	int getValue();
	std::string view();
	~Compartment();
};

