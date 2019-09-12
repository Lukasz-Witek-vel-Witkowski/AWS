#include "AEngine.h"

Engine::Engine()
{
	canal = false;
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
						nameFolderOne = temp.substr(4, temp.size() - 1);
						break; 
					case 2:
						nameFolderSecend = temp.substr(4, temp.size() - 1);
						break;
					}
				}
			}
		}
		file.close();
	}
}
bool Engine::isData() {
	bool b;
	std::ifstream file("Chart.bin");
	if (file.good()) {
		b = true;
		file.close();
	}
	else
		b = false;
	return b;
}
void Engine::run() {
	manager.setNameFolder(nameFolderOne, nameFolderSecend);
	manager.setNameFileData("Chart.bin");
	manager.nsetNameFile("oryginalne_nazwy.txt"); //dodanie nazwy pliku z nazwami pikow!
	if (isData()) {
		manager.loadData();
	}
	else {
		manager.nloadData();
		manager.fileSearch(false, 1);
		manager.fileSearch(true, 2);
		//	manager.setMangerName(&managerName);
		manager.run();
		manager.saveData();
	}

}
Engine::~Engine(){}
void Engine::saveDataChanel() {
	int iter = 0;
	manager.resetIterator();
	while (manager.sizeProduction()!=0) {
		std::cout << "Przetwarzanie " << ++iter << " z " << manager.size()-1 << "\n";
	}
}