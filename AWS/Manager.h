#pragma once
#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <string>
#include <vector>
#include <iostream>
constexpr auto fileList = "fileList.ini";
#pragma warning(disable : 4996) // aby nie wywalal bedu zwiazanego ze stosowaniem satrego sposobu programowania
#include <fstream>
class Manager {
public:
	Manager();
	Manager(std::string data);
	void setNameFolder(std::string name);
	int sizeProduction();
	int size();
	void fileSearch();
	std::string& nextFile();
	void resetIterator();
	void onAlternative();
	void offAlternative();
	~Manager();
private:
	std::vector<std::string> vFile;
	std::string nameFolder;
	std::string data;
	std::string path;
	bool active;
	bool newName;
	bool alterbative;
	unsigned int iterator;
};
#endif // !MANAGER_HPP
