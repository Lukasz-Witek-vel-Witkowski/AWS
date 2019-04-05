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
	void saveDataChanel();
	~Engine();
private:
	Manager manager;
	char program;
	bool canal;
	short iteratorLoadFile;
	short iteratorPerformance;
	short iteratorSave;
	File filePointer;
	std::string nameFolder;
	std::string outputFolder;
	std::string outPutFiles;
};
#endif // !ENGINE_HPP



