#pragma once
#ifndef MANAGERNAME_HPP
#define MANAGERNAME_HPP
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
class ManagerName
{
	std::vector<std::string> v_Name;
	std::vector<std::string> V_Data;
	std::string nameFile;
	bool good;
public:
	ManagerName();
	void setNameFile(std::string name);
	std::string findName(std::string data);
	void loadData();
	~ManagerName();
};
#endif // !MANAGERNAME_HPP