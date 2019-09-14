#pragma once
#include <String>
#include <vector>


class ManagerFolder
{
	std::string Path;
	std::vector<std::string> V_Folder;
	std::string cutPath(std::string path);
	//void resetFolder(std::string data);
public:
	ManagerFolder(std::string data);
	void setFolder(std::string data);
	std::string getFolderPath(int i);
	std::string getNameFolder(int i);
	
	~ManagerFolder();
};

