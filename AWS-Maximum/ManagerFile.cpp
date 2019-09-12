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
	std::cout << temp_next<<"\n";
	system(temp_next.c_str());
	_sleep(1000);
	File = folder + name + ".cnf";
	std::cout << File << "\n";
	file.open(File.c_str());
	if (file.good()) {
		do {
			temp_next = temp;
			std::getline(file, temp);
			std::cout << temp<<"\n";
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

ManagerFile::~ManagerFile()
{
	for (auto& x : M_file) {
		delete x.second;
	}
}
