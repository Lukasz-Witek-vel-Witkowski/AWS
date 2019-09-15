#include "Engine.h"

Engine::Engine()
{
	canal = false;
	digital = false;
	loadFileConfig(); //wczytywanie pliku konfiguracyjnego
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
						_sleep(5);
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
					case 5: {
						switch (temp[4])
						{
						case '0':
							digital = false; break;
						case '1':
							digital = true; break;
						default:
							std::cout << "Nie poprawne dane w pliku konfiguracyjnym!\n";
							break;
						}
						break;
					}
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
	system(file.c_str());
	_sleep(1000);
	focus.setOutPutFiles(outPutFiles);
	focus.setOutPutFolder(outputFolder);
	focus.setPath(nameFolder);
	if (!canal) {
		manager.offAlternative();
		iteratorLoadFile = 0;
		manager.setNameFolder(nameFolder);
		manager.fileSearch(true);
		while (manager.sizeProductionFocus() != 0) {
			std::cout << "Przetwarzanie " << iteratorLoadFile + 1 << " z " << manager.sizeFocus()-1 << "\n";
			focus.setFocus(manager.nextFocus());
			iteratorLoadFile++;
			focus.loadFile();
			focus.saveFile();
			manager.setVector(focus.getVector());
		}
	}
	else {
		manager.onAlternative();
		manager.setNameFolder(outputFolder);
		manager.fileSearch(false);
		iteratorLoadFile = manager.size(); 
	}

	saveDataChanel();
}
Engine::~Engine(){}
void Engine::saveDataChanel() {
	int iter = 0;
	manager.resetIterator();
	while (manager.sizeProduction()!=0) {
		std::cout << "Przetwarzanie " << ++iter << " z " << manager.size() << "\n";
		focus.SetOutPutFileCanal(manager.nextFile(), digital);
	}
}