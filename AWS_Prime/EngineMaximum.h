#pragma once
#include "Manager.h"
#include "Filtr.h"
#define config "file.cnf"
class EngineMaximum
{
private:
	long long Limit;
	bool b_program;
	Manager manager;
	ManagerFile* managerFile;
	std::string fileResult;
public:
	EngineMaximum();
	void setLimit(long limit);
	void run();
	~EngineMaximum();
};

