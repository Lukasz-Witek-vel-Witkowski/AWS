#pragma once
#include "ManagerFile.h"
#include "ManagerFolder.h"
#include "FileConfig.h"
#include "Pack.h"
#include "Cell.hpp"
class Manager
{
private:
	std::string fileThis;
	std::string* value = nullptr;
	std::string fileNameConfig;
	ManagerFile* managerFile = nullptr;
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
	std::string getNameResultFile();
	long getLimit();
	std::vector<Cell> getPerformanceData(int i);
	std::string getThisFile();
	void setConfig(std::string data);
	Pack next();
	~Manager();
};

