#pragma once
#ifndef SECTION_HPP
#define SECTION_HPP
#include "Record.h"
#include <vector>
class Section
{
public:
	Section();
	void addRecord(Record& r);
	void performance();
	void clear();
	int size();
	std::vector<std::string>& getVectorResultPerformance();
	~Section();
private:
	std::vector<Record> vRecord;
	std::vector<std::string> vResultPerformance;

};

#endif // !SECTION_HPP



