#pragma once
#include "ManagerFile.h"
#include "ManagerFolder.h"
#include "FileConfig.h"
#include "Pack.h"
#include "Cell.hpp"
#include <set>
#include "Chart.h"
class Manager
{
private:
	std::string fileThis;
	std::string* value = nullptr;
	std::string fileNameConfig;
	ManagerFile* managerFile = nullptr;
	double percent;
	std::vector<Chart> V_chart;
//	ManagerFolder* managerFolder = nullptr;
	FileConfig fileConfig;
	std::string Path;
	std::vector<std::string> V_Folder;
	std::string cutPath(std::string path);
	std::vector<Cell> V_Cell;
	std::string valuePath();
	Pack getFolder();
	void Config();
public:
	Manager();
	Manager(std::string config);
	void deleteFile(std::string data);
	void runProcessing();
	void LoadData();
	int getSize();
	bool getProgramMethod();
	int getDynamicLimit(int i);
	void resetIterator();
	std::string getNameResultFile();
	long getLimit();
	void maxWithFile();
	void divisionIntoAttributes(std::string data);
	std::vector<Cell> getPerformanceData(int i);
	std::string getThisFile();
	void setConfig(std::string data);
	Pack next();
	~Manager();
};

