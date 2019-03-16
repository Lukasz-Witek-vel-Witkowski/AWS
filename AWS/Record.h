#pragma once
#ifndef RECORD_HPP
#define RECORD_HPP
#include <fstream>
#include <string>
#include <iostream>
constexpr auto limit = 500;
constexpr auto sTime = 15;
constexpr auto sMeasurement = 25;
constexpr auto sValue = 10;
constexpr auto sPow = 1;
class Record
{
public:
	Record();
	void loadData(std::istream& file);
	void diagnostics(std::string& data);
	Record(const Record& r);
	Record& operator=(const Record& r);
	bool operator==(const Record& r);
	//dodac konstruktor kopujacy!!
	std::string performance();
	long getTime();
	float getAfter();
	float getBefore();
	int getCanal();
	int getValue(int iter);
	void setCanal(int Canal);
	bool newSection();
	~Record();
private:
	long *time = nullptr;
	float *firstMeasurement = nullptr;
	float *secendMeasurement = nullptr;
	bool measurement;
	bool diagnosis;
	bool section;
	int canal;
	bool good;
	int *firstValue = nullptr;
	int *secendValue = nullptr;
	int *thirdValue = nullptr;
};
#endif // !RECORD_HPP



