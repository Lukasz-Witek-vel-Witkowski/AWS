#pragma once
#pragma warning(disable : 4996)
#include <String>
#include <vector>
#include <map>
#include  <fstream>
#include <iostream>
#include "Attribute.h"
#define PosEngyne 2
#define PosAmgle 0
#define PosStartingPoint 1
class ManagerFile
{
	int poaition;
	bool active;
	std::map<std::string, std::string> V_pathFile;
	std::map<std::string,int> M_iterator;
	std::map<std::string, int> M_position;
	std::map<std::string, std::vector<std::string>*> M_file;
	std::vector<Attribute> V_Attribute;
	void madeAttribute();
	void resetFolder(std::string data);
public:
	ManagerFile();
	void config();
	void deleteFile(std::string data);
	void setNameFolder(std::string data);
	void setPathFolder(std::string folder, std::string path);
	void generation(std::string folder, std::string name);
	void setAtribite(std::string data);
	void divisionIntoAttributes(std::string data);
	std::string nextNameFile(std::string folder);
	//std::string getFile(int i);
	bool isNext(std::string data);
	void creatingAttributes();
	void resetvalue();
	int getSize(std::string data);
	~ManagerFile();
};

