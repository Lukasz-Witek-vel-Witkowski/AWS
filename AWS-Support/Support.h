#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Element.h"
class Support
{
std::vector<Element> v;
std::string nameFile;
Element element;
std::string path;
public:
	Support(std::string name);
	void loadData();
	void setPath(std::string name);
	void cutValueFocus(std::string& name, int& size, std::string& line);
	void run();
	void save();
	~Support();
};

