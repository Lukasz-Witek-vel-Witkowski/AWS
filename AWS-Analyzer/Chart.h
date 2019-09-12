#pragma once
#ifndef CHART_HPP
#define CHART_HPP
#include <string>
#include <iostream>
class Chart
{
public:
	double MaxPrime;
	double MaxOrgin;
	double MaxOne;
	double MaxSecend;
	double Value6;
	double Value2;
	std::string nameFile;
	std::string namePrimary;
	std::string typeNumber;
	std::string typeKat;
	std::string typePower;
	std::string typeInit_point;
	void productionTypesName();
	Chart();
	Chart(const Chart& c);
	void setMax(int value, double max);
	void setFileName(std::string data);
	Chart& operator=(const Chart& c);
	bool operator==(const Chart& c);
	std::string getFile();
	double& getMax(int value);
	void calcValue();
	std::string getIdName();
	void setPrimeryName(std::string data);
	friend std::ostream& operator<<(std::ostream& is, Chart& c);
	friend std::istream& operator>>(std::istream& is, Chart& c);
	std::string getType(int number);
	~Chart();
};

#endif // !CHART_HPP