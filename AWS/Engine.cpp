#include "Engine.h"



Engine::Engine()
{
	loadFileConfig(); //wczytywanie pliku konfiguracyjnego
	manager.setNameFolder(nameFolder);
	manager.fileSearch();
	filePointer = new File[sizeFiles];
	program = '1';
	activeLoadFile = false;
	activePerformance = false;
	activeSave = false;
	empty = true;
	fullProduction = false;
}
void Engine::loadFileConfig() {
	std::string temp;
	std::ifstream file;
	file.open(config);
	if (file.good()) {
		while (!file.eof()) {
			std::getline(file, temp);
			if (temp.size() > 0) {
				if (temp[0] != '#') {		
					switch ((temp[0] - '0') + (temp[1] - '0') + (temp[2]-'0')) {
					case 1: //nazwa katalogu
						nameFolder = temp.substr(4, temp.size() - 1);
						break;
					case 2:
						outputFolder = temp.substr(4, temp.size() - 1);
						std::string temp = "mkdir " + outputFolder;
						system(temp.c_str());
						_sleep(100);
						break;
					}
				}
			}
		}
		file.close();
	}
}
void Engine::run() {
	std::cout << "\n";
	//int activeProgram;
	while (manager.sizeProduction() > 0) {
		analisesListFile();
		std::cout << program << "\n";
		switch (program) {
			case '1': {
					activeLoadFile = true;
					activePerformance = false;
					activeSave = false;
					configurationIterator();
					filePointer[iteratorLoadFile].setNameFile(nameFolder + "\\" + manager.nextFile());
					filePointer[iteratorLoadFile].setOutputFolder(outputFolder);
					filePointer[iteratorLoadFile].loadFile();
					std::cout << "koniec wczytania!\n";
					if (fullProduction) {
						program = '2';
						activeLoadFile = true;
						activePerformance = true;
						activeSave = false;
						configurationIterator();
						break;
					}
					fPerformance(filePointer, iteratorPerformance);
					fSaveFile(filePointer, iteratorSave);
			}break;
			case '2': {
				std::thread threadLoadFile(fLoadFile, filePointer, iteratorLoadFile, manager.nextFile(), outputFolder);
				std::thread threadPreparation(fPerformance, filePointer, iteratorPerformance);
				if (fullProduction) {
					program = '3';
					activeLoadFile = true;
					activePerformance = true;
					activeSave = true;
					configurationIterator();
					threadLoadFile.join();
					threadPreparation.join();
					break;
				}
				else {
					program = '4';
					configurationIterator();
					threadLoadFile.join();
					threadPreparation.join();
					activeLoadFile = false;
					activePerformance = true;
					activeSave = true;
				}
			}break;
			case '3': {
				std::thread threadLoadFile(fLoadFile, filePointer, iteratorLoadFile, manager.nextFile(), outputFolder);
				std::thread threadPreparation(fPerformance, filePointer, iteratorPerformance);
				std::thread threadSaveFile(fSaveFile, filePointer, iteratorSave);
				if (!fullProduction) {
					program = '4';
					activeLoadFile = false;
					activePerformance = true;
					activeSave = true;
				}
				configurationIterator();
				threadLoadFile.join();
				threadPreparation.join();
				threadSaveFile.join();
			}break;
			case '4': {
				std::thread threadPreparation(fPerformance, filePointer, iteratorPerformance);
				std::thread threadSaveFile(fSaveFile, filePointer, iteratorSave);
				program = '5';
				activeLoadFile = false;
				activePerformance = false;
				activeSave = true;
				configurationIterator();
				threadPreparation.join();
				threadSaveFile.join();
			}break;
			case '5': {
				fSaveFile(filePointer, iteratorSave);
				program = '6';
				activeLoadFile = false;
				activePerformance = false;
				activeSave = false;
				configurationIterator();
			}break;
		}
	}
}
void Engine::configurationIterator() {
	switch (program) {
		case '2': {
			iteratorPerformance = iteratorLoadFile;
			iteratorLoadFile = 1;
			iteratorSave = 2;
		}break;
		case '3': {
			int temp = iteratorSave;
			iteratorSave = iteratorPerformance;
			iteratorPerformance = iteratorLoadFile;
			iteratorLoadFile = temp;
		}break;
		case '4': {
			iteratorSave = iteratorPerformance;
			iteratorPerformance = iteratorLoadFile;
		}break;
		case '5': {
			iteratorSave = iteratorPerformance;
		}break;
		default: {
			iteratorLoadFile = 0;
			iteratorPerformance = 0;
			iteratorSave = 0;
		}break;
	}
}

void Engine::analisesListFile() {
	switch (manager.sizeProduction()) {
		case 1:
			if (!empty) {
				program = '5';
			}
			else {
				program = '1';
			}
			fullProduction = false;
			break;
		case 2:
			if (!empty) {
				program = '4';
			}
			else {
				program = '2';
			}
			fullProduction = false;
			break;
		default:
			if (!empty) {
				program = '3';
			}
			fullProduction = true;
			break;
		}
}

Engine::~Engine()
{
	delete[] filePointer;
}
void fLoadFile(File* file,short id ,std::string name, std::string output) {
	file[id].clear();
	file[id].setNameFile(name);
	file[id].setOutputFolder(output);
	file[id].loadFile();
}
void fPerformance(File* file, short id) {
	file[id].preparationFile();
}
void fSaveFile(File* file, short id) {
	file[id].saveFile();
}