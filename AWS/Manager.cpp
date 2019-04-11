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
std::string& Manager::nextFile() {
	if(iterator<vFile.size())	return vFile[iterator++];
	return data;
}
void Manager::resetIterator() {
	iterator = 0;
	iteratorFocus = 0;
}
int Manager::sizeProduction() {
	return (int)((int)vFile.size()-(int)iterator);
}
void Manager::setNameFolder(std::string name) {
	nameFolder = name;
	active = false;
}
int Manager::sizeFocus() {
	return (int)vFileFocus.size();
}
int Manager::size() {
	return (int)vFile.size();
}
void Manager::countSegments() {
	std::cout << "Loading data...\n";
	std::ifstream in;
	std::ofstream out;
	std::string temp;
	iterator = 0;
	int seg = 0;
	int control = 4;
	out.open(fileFocus);
	if (out.good()) {
		for (int i = 0; i < (int)vFile.size(); i++) {
			in.open(nameFolder + "\\" + vFile[iterator].c_str());
			if (in.good()) {
				while (!in.eof()) {
					std::getline(in, temp);
					if (temp == "") {
						control--;
						if (control == 0)
						{
							seg++;
							control = 4;
						}
					}
				}
				in.close();
			}
			out << vFile[iterator] << "\t" << seg << "\n";
			iterator++;
			seg = 0;
			control = 4;
		}
		out.close();
	}
	loadFileIn();
}
int Manager::sizeProductionFocus() {
	return (int)((int)vFileFocus.size() - (int)iteratorFocus);
}
void Manager::fileSearch(bool what) {
	std::string temp;
	std::string temp_next;
	std::ifstream file;
	if (!active) {
		temp_next = "(cd && dir /b " + nameFolder + ") >> " + fileList;
		active = true;
	}
	temp = "del ";
	temp += fileList;
	system(temp.c_str());
	_sleep(100);
	system(temp_next.c_str());
	_sleep(1000);
	file.open(fileList);
	if (file.good()) {
		file >> path;
		do {
			temp_next = temp;
			std::getline(file, temp);
			if (temp.size() > 5) {
				if (temp[temp.size() - 4] == '.'&&temp[temp.size() - 3] == 't'&&temp[temp.size() - 2] == 'x'&&temp[temp.size() - 1] == 't' && !alterbative) {
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
	if (what)
		countSegments();
}
void Manager::onAlternative() {
	alterbative = true;
}
void Manager::offAlternative() {
	alterbative = false;
}
Focus& Manager::nextFocus() {
	if (iteratorFocus < vFileFocus.size())	return vFileFocus[iteratorFocus++];
	return f_temp;;
}
void Manager::loadFileIn() {
	std::ifstream in(fileFocus);
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
void Manager::setVector(std::vector<std::string>& v) {
	vFile.clear();
	for (auto& x : v) {
		vFile.push_back(x);
	}
}
Manager::~Manager() {}