#pragma warning(disable : 4996)
#include "Manager.h"

Manager::~Manager()
{
	for (auto x : V_compartment) {
		delete x;
	}
}
Manager::Manager(std::string NameConfig) {
	fileConfig.setCharsSkip("#");
	fileConfig.setCharWall(' ');
	fileConfig.setEnd("#end");
	fileConfig.run(NameConfig);
	config();
}
void Manager::run() {
	loadfile();
}
void Manager::loadFileConfig() {
	int value = atoi(fileConfig.interpreter(suport.nextValue()).c_str());
	Path = fileConfig.interpreter(suport.nextValue());
	for (int i = 0; i < value; i++) {
		V_nameFile.push_back(fileConfig.interpreter(suport.nextValue()));
	}
}
void Manager::config() {
	loadFileConfig();
	ConfigAtribiute();
	LoadPaths();
	generationNamefile();
}
void Manager::loadfile() {
	std::string data;
	std::string temp;
	for (int i = 0; i < 3; i++) {
		for (auto x : V_nameFile) {
			L_parameter.clear();
			std::cout << "aktualny plik: " + x << "\n";
			switch (i) {
			case 0:
				data = Path + "\\" + pack->fileCH1 + "\\" + x; break;
			case 1:
				data = Path + "\\" + pack->fileCH2 + "\\" + x; break;
			case 2:
				data = Path + "\\" + pack->fileCH3 + "\\" + x; break;
			}
			int size;
			int iterator = 0;
			std::ifstream file(data);
			if (file.good()) {
				file >> size;
				while (iterator < size) {
					Parameter parameter;
					file >> parameter;
					L_parameter.push_back(parameter);
					iterator++;
				}
				L_parameter.sort();
				std::cout << "wczytanie dancyh z pliku " << x <<"\n";
				file.close();
				temp = data;
				data += "_60_MHz.csv";
				SumParameter();
				std::cout << "przeworzenie dancyh w pliku " << x << "\n";
				SaveParameters(data); 
				std::cout << "zapisanie dancyh pliku " << x << "\n";
				shiftParameter();
				data = temp;
				data += "_80_MHz.csv";
				SumParameter();
				std::cout << "przeworzenie dancyh w pliku " << x << "\n";
				SaveParameters(data);
			}
		}
	}
}
void Manager::SumParameter() {
	for (auto x : L_parameter) {
		for (auto& y : V_compartment) {
			y->comparison(x.getValue());
		}
	}
}
void Manager::ConfigAtribiute() {
	unsigned int iter_start;
	unsigned int iter_stop;
	int program;
	std::string start;
	std::string stop;
	for (auto Line : V_nameFile) {
		iter_start = 0;
		iter_stop = 0;
		program = 0;
		for (unsigned int i = 0; i < Line.size(); i++) {
			if (Line[i] == ' '||i == (Line.size()-1)) {
				switch (program) {
				case 0: {
					iter_stop = i;
					start = Line.substr(iter_start, iter_stop);
					iter_start = i+1;
					program++; }
					break;
				case 1: {
					iter_stop = i - iter_start;
					stop = Line.substr(iter_start, iter_stop);
					V_compartment.push_back(new Compartment(std::stod(start), std::stod(stop)));
				}
				}
			}
		}
	}
	for (auto x : V_compartment) {
		std::cout << x->view();
	}
}
void Manager::SaveParameters(std::string data) {
	std::ofstream file(data);
	if (file.good()) {
		for (auto& x : V_compartment) {
			//std::cout<<x->view();
			file << x->view();
		}
		file.close();
	}
}
void Manager::LoadPaths() {
	std::string temp;
	std::string one;
	std::string two;
	std::string tree;
	int position = -1;
	std::ifstream file;
	temp = "(cd && dir /b " + Path + ") > " + NameFileConfig;
	system(temp.c_str());
	_sleep(TimeSleep);
	file.open(NameFileConfig);
	if (file.good()) {
			file >> temp;
			do {
				while (!file.eof()) {
					std::getline(file, temp);
					if (temp.size()>1&&temp.find('.')>temp.size()) {
						position++;
						switch (position) {
						case 0:
							one = temp; break;
						case 1:
							two = temp; break;
						case 2:
							tree = temp; break;
						}
					}
				}
			} while (position < 2);
		file.close();
	}
	pack = new Pack(one, two, tree);
}
void Manager::generationNamefile() {
	V_nameFile.clear();
	std::string temp;
	std::string path;
	std::string temp_next;
	std::ifstream file;
	for (int i = 0; i < 3; i++) {
		switch (i) {
		case 0:
			path = Path + "\\" + pack->fileCH1; break;
		case 1:
			path = Path + "\\" + pack->fileCH2; break;
		case 2:
			path = Path + "\\" + pack->fileCH3; break;
		}
		temp_next = "(cd && dir /b " + path + ") > " + path + ".cnf";
		system(temp_next.c_str());
		_sleep(TimeSleep);
		path += ".cnf";
		std::cout << "Otworzono plik " + path +"\n";
		file.open(path.c_str());
		if(file.good()){
			while (!file.eof()) {
				std::getline(file, temp);
				if (temp.size()>1&&temp.find("\\") > temp.size()&&temp.find('.')>temp.size()) {
					V_nameFile.push_back(temp);
				}
			}
			file.close();
		}
	}
}
const void Manager::shiftParameter() {
	for (auto& x : L_parameter) {
		x.shift();
	}
}