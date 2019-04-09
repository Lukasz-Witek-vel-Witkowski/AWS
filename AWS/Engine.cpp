#include "Engine.h"

Engine::Engine()
{
	canal = false;
	loadFileConfig(); //wczytywanie pliku konfiguracyjnego
	//program = '1';
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
					case 3:{
						outPutFiles = temp.substr(4, temp.size() - 1);
					break; }
					case 4: {
						switch (temp[4])
						{
						case '0':
							canal = false; break;
						case '1':
							canal = true; break;
						default:
							std::cout << "Nie poprawne dane w pliku konfiguracyjnym!\n";
							break;
						}
						break;   }
					}
				}
			}
		}
		file.close();
	}
}
void Engine::run() {
	std::string file;
	std::cout << "\n"; 
	file = "mkdir" + outPutFiles;
	std::cout << file << "\n";
	system(file.c_str());
	_sleep(1000);
	filePointer.setOutputFolder(outputFolder);
	filePointer.setOutPutFiles(outPutFiles);
	if (!canal) {
		manager.offAlternative();
		manager.setNameFolder(nameFolder);
		manager.fileSearch();
		while (manager.sizeProduction() > 0) {
			std::cout << "Przetwarzanie " << iteratorLoadFile + 1 << " z " << manager.size() << "\n";
			file = manager.nextFile();
			filePointer.segmentclear();
			filePointer.setPath(nameFolder + "\\" + file);
			filePointer.setNameFile(file);
			filePointer.loadFile();
			filePointer.saveFile();
			iteratorLoadFile++;
		}
		//saveDataChanel();
	}
	else {
		manager.onAlternative();
		manager.setNameFolder(outputFolder);
		manager.fileSearch();
		iteratorLoadFile = manager.size(); 
		filePointer.setNameFile(file);
	//	saveDataChanel();
	}
	saveDataChanel();
}
Engine::~Engine(){}
void Engine::saveDataChanel() {
	int iter = 0;
	manager.resetIterator();
	filePointer.setIterator(iteratorLoadFile);
	//filePointer.setOutputFolder(nameFolder);
	while (manager.sizeProduction()) {
		std::cout << "Przetwarzanie " << ++iter << " z " << manager.size() << "\n";
		filePointer.SetOutPutFileCanal(manager.nextFile());
	}
}