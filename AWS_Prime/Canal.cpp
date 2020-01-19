#include "Canal.h"



Canal::Canal()
{

}

void Canal::setValue(Position& p) {
	V_position.push_back(p);
}

Canal::Canal(const Canal& c) {
	if (this != &c) *this = c;
}
Canal&  Canal::operator=(const Canal& c) {
	if (this == &c) return *this;
	if (*this == c) return *this;
	V_position = c.V_position;
	return *this;
}
bool Canal::operator==(const Canal& c) {
	if (V_position.size() == c.V_position.size()) {
		int i = 0;
		for (auto x : V_position) {
			if (x != c.V_position[0]) return false;
		}
		return true;
	}
	return false;
}
std::vector<Position>& Canal::getVector() {
	return V_position;
}

Canal::~Canal()
{
}
