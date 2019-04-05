#include "Manager.h"

Manager::Manager() {
	iterator = 0;
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
	std::ifstream file;
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
void Manager::resetIterator() {
	iterator = 0;
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