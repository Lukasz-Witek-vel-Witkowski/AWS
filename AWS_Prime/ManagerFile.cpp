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

void ManagerFile::generation(std::string folder, std::string name) { //do przerobienia
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
		while(!file.eof()){
			temp_next = temp;
			std::getline(file, temp);
			std::cout << temp<<"\n";
				if (temp.find("\\")>temp.size()) {
					M_file[name]->push_back(temp);
					M_position[name]++;
				}
		}
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
void ManagerFile::resetvalue() {
	for (auto& x : M_iterator) {
		x.second = 0;
	}
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
					active = true;
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
	std::string line;
	std::string temp = "";
	std::string path;
	std::string name;
	int iterator;
	bool what;
	bool ctr = false;
	int iter;
	system("mkdir Result");
	system("mkdir Result\\Energy");
	system("mkdir Result\\Amgle");
	system("mkdir Result\\Starting_Point");
	bool program = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < V_Attribute[i].V_attribute.size(); j++) {
			what = false;
			//std::cout << "i =" << i << "j = " << j << "\n";
			switch (i) {
			case PosAmgle:
				path = "Result\\Amgle\\" + V_Attribute[i].V_attribute[j];
				break;
			case PosEngyne:
				if (active) {
					path = "Result\\Energy\\" + V_Attribute[i].V_attribute[0] + "-" + V_Attribute[i].V_attribute[1];
					what = true;
					j++;
				}
				else {
					path = "Result\\Energy\\" + V_Attribute[i].V_attribute[j];
				}
				break;
			case PosStartingPoint:
				path = "Result\\Starting_Point\\" + V_Attribute[i].V_attribute[j];
				break;
			}
			//std::cout << path<<std::endl;
			std::ifstream file(data);
			std::ofstream fEnergy(path);
			if (file.good() && fEnergy.good()) {
				while (!file.eof()) {
					std::getline(file, line);
					if (line.size() > 0) {
						//std::cout << line << std::endl;
						if (line.find('#') < line.size()) {
							name = line;
							ctr = false;
							program = false;
							line.erase(line.begin(), line.begin() + 1);
							iterator = 0;
							temp = "";
							for (auto x : line) {
								if (x == '_') { iterator++; iter = iterator; }
								if (iterator > 1) {
									switch (iter) {
									case 3: //energia
									case 4:
									case 5:
										//	std::cout << temp << "\n";
										if (!what) {
											if (V_Attribute[i].V_attribute[j] == temp) {
												//		std::cout << line << "\n";
												//			std::cout << "tempAmgle = " << temp << "\n";
												program = true;
											}
										}
										else {
											if (comparator(temp, V_Attribute[PosEngyne].V_attribute[0]) && comparator(V_Attribute[PosEngyne].V_attribute[1], temp)) {
												//					std::cout << line << "\n";
												//					std::cout << "tempEngine = " << temp << "\n";
												program = true;
											}
										}
										iter = 0;
										temp.clear();
										break;
									default:
										if (x != '_')
											temp += x;
									}
								}
							}
						}
						else if (program) {
							line.erase(line.begin(), line.begin() + 1);
							if (ctr == false) {
								name.erase(name.begin(), name.begin() + 1);
								ctr = true;
							}
							//			std::cout << line << " " << name << "\n";
							fEnergy << writeconversion(line) << "\t" << name << "\n";
						}
					}
				}
				file.close();
				fEnergy.close();
			}
		}
	}
}
bool ManagerFile::comparator(std::string left, std::string reight) {
	
	if (left.size() == reight.size()) {
		for (int i = 0; i < left.size(); i++) {
			if (left[i] > reight[i]) {
				if(left.find('E')<left.size()&&reight.find('E')<reight.size())
				return true;
			}
			if (left[i] < reight[i]) return false;
		}
	}
	return false;
}
std::string ManagerFile::writeconversion(std::string data) {
	std::string temp="";
	int iter = 0;
	int start;
	int stop;
	//bool positive;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == ' '||i==(data.size()-1)) {
			iter++;
			switch(iter) {
			case 1:
				start = i + 1;
				break;
			case 2:
			case 3:
				stop = i-start;
				temp += data.substr(start, stop);
				//std::cout << temp << "\n";
				temp += '\t';
				start = i;
				break;
			default: break;
			}
		}		
	}

/*	for(auto x:temp){
		if(x==' ')
		std::cout << temp<< "\n";
	}*/
	return temp;
}