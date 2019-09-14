#pragma once
#include "Manager.h"
#include "Block.h"
#include "Cell.hpp"
#define config "file.cnf"
class EngineMaximum
{
private:
	long Limit;
	bool b_program;
	Manager manager;
	std::string fileResult;
	std::vector<Cell> V_Cell;
	bool comBefore = false;
	bool comSix60MHz = false;
	bool comTwo80MHz = false;
	std::vector<Block> V_block;
	std::map<int, double> M_Before;
	std::map<int, double> M_60MHz;
	std::map<int, double> M_80MHz;
	std::map<int, double> M_maximumBefore;
	std::map<int, double> M_maximum60MHz;
	std::map<int, double> M_maximum80MHz;
	double maxBefore = -1;
	double max60MHz = -1;
	double max80MHz = -1;
	std::map<int, int> M_index;
	int numOfCompartment = 0;
public:
	EngineMaximum();
	void setLimit(long limit);
	void run();
	int getNumber(std::map<int, int> index, int number);
	std::pair<int, double> getMaximum(std::map<int, int> index, std::map<int, double> & max, int com);
	void saveToResultFile(std::vector<Block> V_blok);
	std::vector<Block> AnalizerFiles(std::vector<Cell> V_segment, std::string data);
	std::pair<int, double> getMaximumMap(std::map<int, double> values);
	~EngineMaximum();
};

