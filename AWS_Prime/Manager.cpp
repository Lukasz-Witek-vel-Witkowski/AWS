#include "Manager.h"
#pragma warning(disable : 4996)

Manager::Manager(std::string config) {
	fileNameConfig = config;
	Config();
	m_Name.setNameFile("oryginalne_nazwy.txt");
	m_Name.loadData(); // ladowanie nazw
}
Manager::Manager(){
	m_Name.setNameFile("oryginalne_nazwy.txt");
	m_Name.loadData(); // ladowanie nazw
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
	percent = atoi(fileConfig.interpreter("9").c_str())/100.0;
	managerFile->config(); //tworzenie attribute
	Path = valuePath();
}
bool Manager::getProgramMethod() {
	return (bool)atoi(fileConfig.interpreter("7").c_str());
}

void Manager::runProcessing() {
	system("cls");
	std::cout << "Wczytywanie listy plikow\n";
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
			//std::cout << temp << "\n";
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
long long Manager::getDynamicLimit(int i){
	if ((bool)atoi(fileConfig.interpreter("8").c_str())) {
		return V_chart[i].getLimit();
	}
	else {
		return atoi(fileConfig.interpreter("5").c_str());
	}
}
void Manager::resetIterator() {
	managerFile->resetvalue();
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
void Manager::divisionIntoAttributes(std::string file_data) {
	managerFile->divisionIntoAttributes(file_data);
}
void Manager::maxWithFile() { //tu przerobic
	Result result;
	std::string name_file_operation;
	if ((bool)atoi(fileConfig.interpreter("8").c_str())) {
		V_chart.resize(managerFile->getSize(V_Folder[0]) + 1000);
		long double temp;
		int iter = 1;
		for (int j = 0; j < V_Folder.size(); j++) {
			int size = managerFile->getSize(V_Folder[j])-1;
			for (int i = 0; i < size; i++) {
				system("cls");
				std::cout << "postep w znajdywaniu maximow = " << (iter * 100) / (size*V_Folder.size()) << "[%] plik = " << iter++ << "/" << size * V_Folder.size() << "\n";
				name_file_operation = managerFile->nextNameFile(V_Folder[j]);
				std::string test = Path + V_Folder[j] + "\\" + name_file_operation;
				//std::cout << test << "\n";
				int Size[3] = { 0,1,2 };
				std::ifstream data;
				data.open(test.c_str());
				if (data.good()) {
					std::string Data;
					std::getline(data, Data);
					for (int i = 0; i < 3; i++) {
						Data.clear();
						std::getline(data, Data);
						Size[i] = FindParameter(Data);
					}
					data.close();
				}
				data.open(test.c_str());
				if (data.good()) {
					std::string Data;
					std::getline(data, Data);
					for (int j = 0; j < 3; j++) {
						Position p;
						Canal c;
						for (int i = 0; i < Size[j]; i++) {
							data >> temp;
							p.setValue(i, temp);
							c.setValue(p);
						}
						V_canal.push_back(c);
					}
					data.close();
				}
				int iter = 0;
				for (auto x : V_canal) {
					Filtr f(&x);
					f.setPrecent(20);
					f.setType(true);
					Mcanal.setMax(f.filtration(), (ManagerCanal::Value)iter++);
				}
				Mcanal.veryfication();
				position();
			//	Mcanal.cout();
				std::cout << name_file_operation << "\n";
				for (int ii = 0; ii < Mcanal.getSize(0); ii++) {
					result.setFile(m_Name.findName(name_file_operation));
					result.set_2_80(Mcanal.getcoefficient2_80(ii));
					result.set_6_60(Mcanal.getcoefficient6_60(ii));
					V_result.push_back(result);
				}
				V_canal.clear();
				Mcanal.reset();
				V_chart[i].precent = percent;
			}
			managerFile->resetvalue();
		}
	}
}
ManagerFile* Manager::getManagerFile() {
	return managerFile;
}
Pack Manager::getPack() {
	return getFolder();
}
std::string Manager::getPath() {
	return Path;
}
int Manager::FindParameter(std::string& Data) {
	int i = 0;
	for (auto x : Data) {
		if (x == '\t') {
			i++;
		}
	}
	return i;
}
std::vector<Canal>& Manager::getVCanal() {
	return V_canal;
}
void Manager::position() {
	Mcanal.position();
	Mcanal.cout();
}
void Manager::Finish(std::string data) {
	std::ofstream file(data, std::ios::app);
	int i = 1;
	if (file.good()) {
		for (auto& x : V_result) {
			if (data == "") {
				data = x.getFile();
				file << "# " << data << "\n";
				file << i << ' ' << x.get_6_60() << " " << x.get_2_80() << "\n";
			}
			else {
				if (data == x.getFile()) {
					file << i << ' ' << x.get_6_60() << " " << x.get_2_80() << "\n";
				}
				else {
					data = x.getFile();
					file << "# " << data << "\n";
					file << i << ' ' << x.get_6_60() << " " << x.get_2_80() << "\n";
				}
			}
			i++;
		}
		file.close();
	}
}