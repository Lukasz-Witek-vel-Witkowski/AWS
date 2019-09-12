#pragma once
#pragma warning(disable : 4996)
#include <String>
#include <vector>
#include <map>
#include  <fstream>
#include <iostream>
class ManagerFile
{
	int poaition;
	bool active;
	std::map<std::string, std::string> V_pathFile;
	std::map<std::string,int> M_iterator;
	std::map<std::string, int> M_position;
	std::map<std::string, std::vector<std::string>*> M_file;
	void resetFolder(std::string data);
public:
	ManagerFile();
	void setNameFolder(std::string data);
	void setPathFolder(std::string folder, std::string path);
	void generation(std::string folder, std::string name);
	std::string nextNameFile(std::string folder);
	//std::string getFile(int i);
	bool isNext(std::string data);
	int getSize(std::string data);
	~ManagerFile();
};

