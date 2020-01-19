#pragma once
#include <string>
class Result
{
	double MHZ_2_80;
	double MHZ_6_60;
	std::string file;
public:
	Result();
	void set_2_80(double value);
	void set_6_60(double value);
	void setFile(std::string data);
	std::string getFile();
	double get_2_80();
	double get_6_60();
	~Result();
};

