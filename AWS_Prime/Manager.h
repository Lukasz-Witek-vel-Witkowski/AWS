#pragma once
#include "ManagerFile.h"
#include "ManagerFolder.h"
#include "FileConfig.h"
#include "Pack.h"
#include <set>
#include "Chart.h"
#include "Filtr.h"
#include "ManagerCanal.h"
#include "ManagerName.h"
#include "Result.h"
#define PosEngyne 2
#define PosAmgle 0
#define PosStartingPoint 1

class Manager
{
private:
	ManagerCanal Mcanal;
	std::string fileThis;
	std::string* value = nullptr;
	std::string fileNameConfig;
	ManagerFile* managerFile = nullptr;
	double percent;
	ManagerName m_Name;
	std::vector<Chart> V_chart;
	std::vector<Result> V_result;
	FileConfig fileConfig;
	std::string Path;
	std::vector<std::string> V_Folder;
	std::string cutPath(std::string path);
	std::vector<Canal> V_canal;
	std::string valuePath();
	Pack getFolder();
	int FindParameter(std::string& Data);
	void Config();
public:
	Manager();
	Manager(std::string config);
	void deleteFile(std::string data);
	void runProcessing();
	void LoadData();
	int getSize();
	std::vector<Canal>& getVCanal();
	ManagerFile* getManagerFile();
	bool getProgramMethod();
	long long getDynamicLimit(int i);
	void resetIterator();
	std::string getNameResultFile();
	long getLimit();
	void maxWithFile();
	void divisionIntoAttributes(std::string data);
	std::string getThisFile();
	void setConfig(std::string data);
	void position();
	void Finish(std::string data);
	Pack next();
	std::string getPath();
	~Manager();
	Pack getPack();
};

