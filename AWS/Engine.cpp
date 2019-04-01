#include "Engine.h"

Engine::Engine()
{
	loadFileConfig(); //wczytywanie pliku konfiguracyjnego
	manager.setNameFolder(nameFolder);
	manager.fileSearch();
	program = '1';
	//activeLoadFile = false;
	//activePerformance = false;
	//activeSave = false;
	//empty = true;
	//fullProduction = false;
	iteratorLoadFile = 0;
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
					{nameFolder = temp.substr(4, temp.size() - 1);
					break; }
					case 2: {
						outputFolder = temp.substr(4, temp.size() - 1);
						std::string TempName = "mkdir " + outputFolder;
						system(TempName.c_str());
						_sleep(100);
						break; }
					case 3:
					{outPutFile = temp.substr(4, temp.size() - 1);
					break; }
					}
				}
			}
		}
		file.close();
	}
}
void Engine::run() {
	std::cout << "\n"; 
	while (manager.sizeProduction() > 0) {
		filePointer = new File;
		//system("cls");
		std::cout << "Przetwarzanie "<<iteratorLoadFile+1<<" z "<<manager.size()<<"\n";
		//analisesListFile();
		filePointer->setNameFile(nameFolder + "\\" + manager.nextFile());
		filePointer->setOutputFolder(outputFolder);
		filePointer->setOutPutFile(outPutFile);
		filePointer->loadFile();
		filePointer->saveFile();
		iteratorLoadFile++;
		delete filePointer;
	}
}
/*void Engine::analisesListFile() {
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
}*/
Engine::~Engine()
{
	delete filePointer;
}
/*void fLoadFile(File* file,short id ,std::string name, std::string output,std::string outPutFile) {
	file[id].clear();
	file[id].setNameFile(name);
	file[id].setOutputFolder(output);
	file[id].setOutPutFile(outPutFile);
	file[id].loadFile();
}*/
/*void fSaveFile(File* file, short id) {
	file[id].saveFile();
}*/