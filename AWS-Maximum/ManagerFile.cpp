#include "ManagerFile.h"



ManagerFile::ManagerFile()
{
}
void ManagerFile::setNameFolder(std::string data) {
	M_file[data] = new std::vector<std::string>;
	M_iterator[data] = 0;
	M_position[data] = 0;
	active = false;
}

void ManagerFile::setPathFolder(std::string folder,std::string path) {
	V_pathFile[folder] = path;
}

void ManagerFile::generation(std::string folder, std::string name) {
	std::string temp;
	std::string path;
	std::string File;
	std::string temp_next;
	std::ifstream file;
	resetFolder(folder+name);
	temp_next = "(cd && dir /b " + folder + name + ") >> " + folder +name + ".cnf";
	//std::cout << temp_next<<"\n";
	system(temp_next.c_str());
	_sleep(1000);
	File = folder + name + ".cnf";
	//std::cout << File << "\n";
	file.open(File.c_str());
	if (file.good()) {
		do {
			temp_next = temp;
			std::getline(file, temp);
		//	std::cout << temp<<"\n";
				if (temp.find(".txt.")<temp.size()) {
					M_file[name]->push_back(temp);
					M_position[name]++;
				}
		} while (temp_next != temp);
		file.close();
	}
}
int ManagerFile::getSize(std::string data) {
	return M_position.at(data);
}
std::string ManagerFile::nextNameFile(std::string folder) {
	//if (active) active = false;
	if (isNext(folder)) {
		return M_file[folder]->operator[](M_iterator.at(folder)++);
	}
	return "";
}


bool ManagerFile::isNext(std::string data) {
	return (M_position[data] > M_iterator[data]);
}

void ManagerFile::resetFolder(std::string data) {
	std::string path = "del " + data + ".cnf";
	system(path.c_str());
}

void ManagerFile::creatingAttributes() {

}

ManagerFile::~ManagerFile()
{
	for (auto& x : M_file) {
		delete x.second;
	}
}

void ManagerFile::setAtribite(std::string data) {
	Attribute attribute;
	attribute.value = data;
	V_Attribute.push_back(attribute);
}
void ManagerFile::madeAttribute() {
	std::string temp = "";
	for (auto& x : V_Attribute) {
		if (x.value.find(',') < x.value.size()) {
			temp = "";
			for (auto c : x.value) {
				if (c == ',') {
					x.compartment = false;
					x.V_attribute.push_back(temp);
					temp = "";
					continue;
				}
				temp += c;
			}
			x.V_attribute.push_back(temp);
		}
		else if (x.value.find(" - ") < x.value.size()) {
			temp = "";
			for (auto c : x.value) {
				if (c == '-') {
					x.compartment = true;
					x.V_attribute.push_back(temp);
					temp = "";
					continue;
				}
				temp += c;
			}
			x.V_attribute.push_back(temp);
		}
		if (x.V_attribute.size() > 0) {
			x.clearWhiteChars();
			//x.value = "":
		}
	}
}
void ManagerFile::deleteFile(std::string data) {
	resetFolder(data);
}
void ManagerFile::config() {
	 madeAttribute();
}
void ManagerFile::divisionIntoAttributes(std::string data) {
	std::ifstream file(data);
	std::string line;
	std::string temp = "";
	std::string path;
	int iterator;
	int iter;
	system("mkdir Result");
	system("mkdir Result\\Energy");
	system("mkdir Result\\Amgle");
	system("mkdir Result\\Starting_Point");
	path = "Result\\Energy\\ResultEnergy.txt";
	std::ofstream fEnergy(path);
	path = "Result\\Amgle\\ResultAmgle.txt";
	std::ofstream fAmge(path);
	path = "Result\\Starting_Point\\ResultStarting_Point.txt";
	std::ofstream fStartingPointer(path);
	int* program = new int[3];
	if (file.good()&&fEnergy.good()&&fAmge.good()&&fStartingPointer.good()) {
		while (!file.eof()) {
			std::getline(file, line);
			if (line.find('#') < line.size()) {
				program[0] = 0;
				program[1] = 0;
				program[2] = 0;
				line.erase(line.begin(), line.begin() + 1);
				iterator = 0;
				temp = "";
				for (auto x : line) {
					if (x == '_') { iterator++; iter = iterator;}
					if (iterator > 1) {
						switch (iter) {
						case 3: //energia
							if (V_Attribute[PosAmgle].In_terms_of(temp)) {
								//std::cout << line << "\n";
								//std::cout << "tempAmgle = " << temp << "\n";
								program[1] = 3;
								temp.clear();
								iter = 0;
							}
							break;
						case 4: //kat
							if (V_Attribute[PosEngyne].In_terms_of(temp)) {
								//std::cout << line << "\n";
								//std::cout << "tempEnergy = " << temp << "\n";
								program[0] = 2;
								temp.clear();
								iter = 0;
							}
							break;
						case 5: //punkt pocz¹tkowy
							if (V_Attribute[PosStartingPoint].In_terms_of(temp)) {
							//	std::cout << line << "\n";
							//	std::cout << "tempSP = " << temp << "\n";
								program[2] = 4;
								temp.clear();
								iter = 0;
							}
							break;
						default:
							if(x!='_')
							temp += x;
						}
					}
				}
				//continue;
			}
			for (int i = 0; i < 3; i++) {
				switch (program[i]) {
				case 2:
					fEnergy << line;
					break;
				case 3:
					fAmge << line;
					break;
				case 4:
					fStartingPointer << line;
					break;
				}
			}
		
		}
		file.close();
		fEnergy.close();
		fAmge.close();
		fStartingPointer.close();
	}
	delete []program;
}