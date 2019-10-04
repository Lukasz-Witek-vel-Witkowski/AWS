#pragma once
#include <list>
#include <vector>
#include "Parameter.h"
#include "FileConfig.h"
#include "Compartment.h"
#include "Support.h"
#include "Pack.h"
#define TimeSleep 1000
#define NameFileConfig "file.cnf"
class Manager
{
	Pack *pack;
	Support suport;
	std::string Path;
	FileConfig fileConfig;
	std::vector<std::string> V_nameFile;
	std::list<Parameter> L_parameter;
	std::vector<double> V_atribute;
	std::vector<Compartment*> V_compartment;
	std::string NameFile;
	void loadFileConfig();
	void config();
	void loadfile();
	void SumParameter();
	void ConfigAtribiute();
	void SaveParameters(std::string data);
	void LoadPaths();
	void generationNamefile();
	const void shiftParameter();
public:
	Manager(std::string NameConfig);
	void run();
	~Manager();
};

