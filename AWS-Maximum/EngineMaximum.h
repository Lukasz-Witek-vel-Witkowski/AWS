#pragma once
#include "Manager.h"
#include "Block.h"
#include "Cell.hpp"
#define config "file.cnf"
class EngineMaximum
{
private:
	long Limit;
	Manager manager;
	std::string fileResult;
	std::vector<Cell> V_Cell;
	bool compartmentBefore = false;
	bool compartmentSix60MHz = false;
	bool compartmentTwo80MHz = false;
	std::vector<Block> V_block;
	std::map<int, double> tempBefore;
	std::map<int, double> tempSix60MHz;
	std::map<int, double> tempTwo80MHz;
	std::map<int, double> maximumBefore;
	std::map<int, double> maximumSix60MHz;
	std::map<int, double> maximumTwo80MHz;
	double maxBefore = -1;
	double maxSix60MHz = -1;
	double maxTwo80MHz = -1;
	std::map<int, int> indexes;
	int numOfCompartment = 0;
public:
	EngineMaximum();
	void setLimit(long limit);
	void run();
	std::vector<Block> AnalizerFiles(std::vector<Cell> V_segment, std::string data);
	std::pair<int, double> getMaximumFromMap(std::map<int, double> values);
	int getNumberOfCompartment(std::map<int, int> indexes, int numOfIndex);
	std::pair<int, double> getMaximumFromCompartment(std::map<int, int> indexes, std::map<int, double> & maximums, int compartment);
	void saveToResultFile(std::vector<Block> V_blok);
	~EngineMaximum();
};

