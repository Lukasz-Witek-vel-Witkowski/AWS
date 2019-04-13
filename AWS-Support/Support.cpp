#include "Support.h"



Support::Support(std::string name) {
	nameFile = name;
}
void Support::loadData() {
	std::cout << "Wczytywanie pliku " << nameFile << "\n";
	std::string temp;
	std::string name;
	int iterator;
	int i;
	std::ifstream in(nameFile.c_str());
	if (in.good()) {
		while (!in.eof()) {
			std::getline(in, temp);
			cutValueFocus(name, iterator, temp);
			i = 0;
			if (iterator == 1) {
				temp = name.substr(0, name.size() - 4) + "_Digital0.txt";
			}
			else {
				for (int j = 0; j < iterator; j++) {

					temp = name.substr(0, name.size() - 4) + "_" + std::to_string(++i) + "-" + std::to_string(iterator) + "_Digital0.txt";
					element.setName(temp);
					v.push_back(element);
				}
			}
		}
		in.close();
	}
}
void Support::run() {
	std::ifstream in;
	std::string temp;
	int i = 0;
	for (auto& x : v) {
		std::cout << "Przetwarzany " << ++i << " z " << v.size()<<"\n";
		temp = path + "\\" + x.getName().substr(0, x.getName().size()-13) + "\\"+ x.getName();
		in.open(temp.c_str());
		if (in.good()) {
			x.goodFile();
		}
		else {
			x.badFile();
		}
		in.close();
	}
}
void Support::save() {
std::cout << "zapisywanie wynikow!\n";
	std::ofstream outgood("goodFile.txt");
	std::ofstream outbad("badFile.txt");
	if (outgood.good()&&outbad.good()) {
		for (auto& x : v) {
			if (x.status())
			outgood << x;
			else
			outbad << x;
		}
	}
}
void Support::setPath(std::string name) {
	path = name;
}
void Support::cutValueFocus(std::string& name, int& size, std::string& line) {
	size_t ptr;
	ptr = line.find('\t');
	name = line.substr(0, ptr);
	line.replace(0, ptr + 1, "");
	ptr = line.find('\t');
	size = atoi(line.substr(0, ptr).c_str());
}
Support::~Support()
{
}
