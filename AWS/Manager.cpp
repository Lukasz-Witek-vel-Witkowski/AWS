#include "Manager.h"

Manager::Manager() {
	iterator = 0;
	iteratorFocus = 0;
	active = false;
	alterbative = false;
	data = "";
}
Manager::Manager(std::string data) {
	nameFolder = data;
	active = false;
}
void Manager::setNameFolder(std::string name) {
	nameFolder = name;
	active = false;
}
void Manager::fileSearch() {
	std::string temp;
	std::string temp_next;
	std::ifstream file;
	if (!active) {
		nameFolder = "(cd && dir /b " + nameFolder + ") >> " + fileList;
		active = true;
	}
	temp = "del ";
	temp += fileList;
	system(temp.c_str());
	_sleep(100);
	system(nameFolder.c_str());
	std::cout << nameFolder;
	_sleep(1000);
	file.open(fileList);
	if (file.good()) {
		file >> path;
		do {
			temp_next = temp;
			std::getline(file, temp);
			if (temp.size() > 5) {
				if (temp[temp.size()-4]=='.'&&temp[temp.size()-3]=='t'&&temp[temp.size()-2]=='x'&&temp[temp.size()-1]=='t'&&!alterbative) {
					vFile.push_back(temp);
				}
				else {
					if (temp[temp.size() - 4] == '.'&&temp[temp.size() - 3] == 'b'&&temp[temp.size() - 2] == 'i'&&temp[temp.size() - 1] == 'n' && alterbative) {
						vFile.push_back(temp);
					}
				}
			}
		} while (temp_next != temp);
		file.close();
	}
}
std::string& Manager::nextFile() {
	if(iterator<vFile.size())	return vFile[iterator++];
	return data;
}
Focus& Manager::nextFocus() {
	if (iteratorFocus < vFileFocus.size())	return vFileFocus[iteratorFocus++];
	return f_temp;;
}
void Manager::resetIterator() {
	iterator = 0;
	iteratorFocus = 0;
}
int Manager::sizeProduction() {
	return (int)((int)vFile.size()-(int)iterator);
}
int Manager::size() {
	return (int)vFile.size();
}
Manager::~Manager() {}
void Manager::onAlternative() {
	alterbative = true;
}
void Manager::offAlternative() {
	alterbative = false;
}
void Manager::loadFileIn() {
	std::ifstream in(nameFocus.c_str());
	std::string temp;
	std::string name;
	Focus f;
	int size;
	if (in.good()) {
		while (!in.eof()) {
			std::getline(in, temp);
			cutValueFocus(name, size, temp);
			f.setName(name);
			f.setSize(size);
			vFileFocus.push_back(f);
		}
	}

}
void Manager::cutValueFocus(std::string& name, int& size, std::string& line) {
	size_t ptr;
	ptr = line.find('\t');
	name = line.substr(0, ptr);
	line.replace(0, ptr + 1, "");
	ptr = line.find('\t');
	size = atoi(line.substr(0, ptr).c_str());
}
void Manager::setNameFocus(std::string name) {
	nameFocus = name;
}
int Manager::sizeFocus() {
	return (int)vFileFocus.size();
}
int Manager::sizeProductionFocus() {
	return (int)((int)vFileFocus.size() - (int)iteratorFocus);
}