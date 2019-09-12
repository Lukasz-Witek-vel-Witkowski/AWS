#include "Chart.h"
Chart::Chart()
{
	typeInit_point = "";
	typeKat = "";
	typePower = "";
	typeNumber = "";
}
Chart::Chart(const Chart& c) {
	if (this != &c)  *this = c;
}
void Chart::setMax(int value, double max) {
	switch (value) {
	case 0: MaxPrime = max; break;
	case 1: MaxOrgin = max; break;
	case 2: MaxOne = max; break;
	case 3: MaxSecend = max; break;
	}
}
double& Chart::getMax(int value) {
	switch (value) {
	case 0: return MaxPrime;
	case 1: return MaxOrgin;
	case 2:	return MaxOne;
	case 3: return MaxSecend;
	}
}
void Chart::setFileName(std::string data) {
	nameFile = data;
}
Chart& Chart::operator=(const Chart& c) {
	if (this == &c) return *this;
	if (*this == c) return *this;
	MaxPrime = c.MaxPrime;
	MaxOrgin = c.MaxOrgin;
	MaxOne = c.MaxOne;
	MaxSecend = c.MaxSecend;
	nameFile = c.nameFile;
	typeInit_point = c.typeInit_point;
	typeKat = c.typeKat;
	typePower = c.typePower;
	typeNumber = c.typeNumber;
	return *this;
}
bool Chart::operator==(const Chart& c) {
	if (MaxPrime == c.MaxPrime&&MaxOrgin == c.MaxOrgin&&MaxOne == c.MaxOne&&MaxSecend == c.MaxSecend&&nameFile==c.nameFile) return true;
	return false;
}
std::string Chart::getFile() {
	return nameFile;
}
Chart::~Chart()
{
}
void Chart::calcValue() {
	if (MaxOrgin > 0) {
		Value2 = MaxSecend / MaxOrgin;
		Value6 = MaxOne / MaxOrgin;
	}
	else {
		Value2 = 0;
		Value6 = 0;
	}
}
std::string Chart::getIdName() {
	std::string temp = "";
	for (auto x : nameFile) {
		if (x == '_') break;
		temp += x;
	}
	return temp;
}
void Chart::setPrimeryName(std::string data) {
	namePrimary = data;
	productionTypesName();
}
void Chart::productionTypesName() {
	int program = 0;
	std::string temp="";
	std::cout << namePrimary;
	for (auto& x : namePrimary) {
		if (x == '_') {
			switch (program) {
			case 0:
				typeNumber = temp;
				temp = "";
				program++;
				break;
			case 1:
				typeKat = temp;
				temp = "";
				program++;
				break;
			case 2:
				typePower = temp;
				temp = "";
				program++;
				break;
			case 3:
				typeInit_point = temp;
				temp = "";
				program++;
				break;
			default:
				return;
			}
			continue;
		}
		temp += x;
	}
}
std::string Chart::getType(int number) {
	switch (number) {
	case 0:
		return typeNumber;
	case 1:
		return typeKat;
	case 2:
		return typePower;
	case 3:
		return typeInit_point;
	default:
		std::cout << "Wartosc poa zakresem!";
		return "";
	}
}
std::ostream& operator<<(std::ostream& is, Chart& c) {
	is << c.MaxOne << " " << c.MaxOrgin << " " << c.MaxPrime << " " << c.MaxSecend << " " << c.nameFile << " " << c.namePrimary << " " << c.typeInit_point << " " << c.typeKat << " " << c.typeNumber << " " << c.typePower;
	return is;
}
std::istream& operator>>(std::istream& is, Chart& c) {
	is >> c.MaxOne;
	is >> c.MaxOrgin;
	is >> c.MaxPrime;
	is >> c.MaxSecend;
	is >> c.nameFile;
	is >> c.namePrimary;
	is >> c.typeInit_point;
	is >> c.typeKat;
	is >> c.typeNumber;
	is >> c.typePower;
	return is;
}