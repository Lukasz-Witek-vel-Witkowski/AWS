#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Manager.h"
constexpr auto config = "file.cnf";
constexpr auto sizeFiles = 2;
#include <thread>
#include "File.h"
class Engine
{
public:
	Engine();
	void loadFileConfig();
	void run();
	~Engine();
private:
	void analisesListFile();
	Manager manager;
	char program;
	bool activeLoadFile;
	bool activePerformance;
	bool activeSave;
	bool empty;
	bool fullProduction;
	short iteratorLoadFile;
	short iteratorPerformance;
	short iteratorSave;
	File* filePointer;
	std::string nameFolder;
	std::string outputFolder;
	std::string outPutFile;
};
void fLoadFile(File* file, short id, std::string name, std::string output, std::string outputFile);
//void fPerformance(File* file,short id);
void fSaveFile(File* file,short id);
#endif // !ENGINE_HPP



