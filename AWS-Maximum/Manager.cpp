#include "Manager.h"
#pragma warning(disable : 4996)

Manager::Manager(std::string config) {
	fileNameConfig = config;
	Config();

}
Manager::Manager(){
}
void Manager::Config() {
	fileConfig.setCharsSkip("#");
	fileConfig.setPosition(8);
	fileConfig.setCharWall(' ');
	fileConfig.setEnd("#end");
	LoadData();
}
void Manager::setConfig(std::string data) {
	fileNameConfig = data;
	Config();
}
void Manager::LoadData() {
	fileConfig.run(fileNameConfig);
	value = new std::string(fileConfig.interpreter("1"));
	managerFile = new ManagerFile();
	managerFile->setAtribite(fileConfig.interpreter("2"));
	managerFile->setAtribite(fileConfig.interpreter("3"));
	managerFile->setAtribite(fileConfig.interpreter("4"));
	managerFile->config(); //tworzenie attribute
	Path = valuePath();
}

void Manager::runProcessing() {
	Pack pack = getFolder();
	V_Folder.push_back(pack.fileCH1);
	V_Folder.push_back(pack.fileCH2);
	V_Folder.push_back(pack.fileCH3);
	managerFile->setNameFolder(pack.fileCH1);
	managerFile->setNameFolder(pack.fileCH2);
	managerFile->setNameFolder(pack.fileCH3);
	managerFile->generation(Path, pack.fileCH1);
	managerFile->generation(Path, pack.fileCH2);
	managerFile->generation(Path, pack.fileCH3);
}

Pack Manager::next() {
	Pack p;
	return p;
}
std::string Manager::valuePath() {
	return *value; 
}
std::string Manager::cutPath(std::string path) {
	if (path.rfind("/") < path.size()) {
		return path.substr(path.rfind("/"));
	}
	return path;
}
Pack Manager::getFolder() {
	std::string temp;
	std::string one;
	std::string two;
	std::string tree;
	int position = -1;
	std::ifstream file;
	temp = "(cd && dir /b " + *value + ") >> " + "file.cnx";
	system(temp.c_str());
	_sleep(1000);
	file.open("file.cnx");
	if (file.good()) {
		file >> temp;
		do {
			std::getline(file, temp);
			std::cout << temp << "\n";
			if (temp.find('.')>temp.size()){
				position++;
				switch (position) {
				case 1:
					one = temp; break;
				case 2:
					two = temp; break;
				case 3:
					tree = temp; break;
				}
			}
		} while (position<3);
		file.close();
	}
	Pack pack(one, two, tree);
	return pack;
}
std::vector<Cell> Manager::getPerformanceData(int i) {
	V_Cell.clear();
	fileThis = managerFile->nextNameFile(V_Folder[0]);
	std::string fileOne = Path  + V_Folder[0] +"\\" + fileThis;
	std::string filesecend = Path  + V_Folder[1] +"\\" +managerFile->nextNameFile(V_Folder[1]);
	std::string filetree = Path  + V_Folder[2] + "\\"+managerFile->nextNameFile(V_Folder[2]);

	std::cout << "file1 = " + fileOne + "\n";
	std::cout << "file2 = " + filesecend + "\n";
	std::cout << "file3 = " + filetree + "\n";
	std::ifstream FileOne(fileOne);
	std::ifstream FileSecend(filesecend);
	std::ifstream FileTree(filetree);
	double before;
	double CH60;
	double CH80;
	if (FileOne.good(), FileSecend.good(), FileTree.good()) {
		while (!FileOne.eof() && !FileSecend.eof() && !FileTree.eof()) {
			FileOne >> before;
			FileSecend >> CH60;
			FileTree >> CH80;
			Cell cell(before, CH60, CH80);
			V_Cell.push_back(cell);
		}
		FileOne.close();
		FileSecend.close();
		FileTree.close();
	}
	else {
		std::cout << "nie udalo sie otworzyc pliku";
	}
	std::cout << V_Cell.size()<<"\n";
	return V_Cell;
}
std::string Manager::getThisFile() {
	return fileThis;
}
int Manager::getSize() {
	return managerFile->getSize(V_Folder[0]);
}
Manager::~Manager()
{
	delete managerFile;
	//delete managerFolder;
	delete value;
}
std::string Manager::getNameResultFile() {
	return fileConfig.interpreter("6");
}
long Manager::getLimit() {
	return atol(fileConfig.interpreter("5").c_str());
}
void Manager::deleteFile(std::string data) {
	managerFile->deleteFile(data);
}