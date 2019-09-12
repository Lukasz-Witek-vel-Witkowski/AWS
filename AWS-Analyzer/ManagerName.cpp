#include "ManagerName.h"
ManagerName::ManagerName()
{
	good = false;
}
void ManagerName::setNameFile(std::string name) {
	nameFile = name;
	good = true;
}
std::string ManagerName::findName(std::string data) {
	std::string temp="";
	for (auto x:v_Name) {
		if (x.substr(0, 4) == data)
			return x;
	}
	return " ";
}
void ManagerName::loadData() {
	if (good) {
		std::string temp;
		std::ifstream file(nameFile);
		if (file.good()) {
			while (!file.eof())
			{
				file >> temp;
				if (temp.size() > 5) {
					v_Name.push_back(temp);
					temp = "";
				}
			}
			file.close();
		}
	}
}
ManagerName::~ManagerName()
{
}
