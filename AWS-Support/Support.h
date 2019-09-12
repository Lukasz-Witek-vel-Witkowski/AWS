#pragma once
constexpr auto config = "file.cnf";
#include <vector>
#include <iostream>
#include <fstream>
#include "Element.h"
class Support
{
std::vector<Element> v;
std::string nameFile;
Element element;
bool action;
std::string path;
public:
	Support(std::string name);
	void loadData();
	void setPath(std::string name);
	void loadFileConfig(); //metoda wczytujaca dane z pliku konfiguracyjnego
	void cutValueFocus(std::string& name, int& size, std::string& line);
	void run();
	void fileDelete();
	bool& getAction();
	void save();
	~Support();
};

