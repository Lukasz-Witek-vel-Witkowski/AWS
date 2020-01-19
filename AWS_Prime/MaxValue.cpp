#include "MaxValue.h"



MaxValue::MaxValue()
{
	Max.setValue(0, 0.0);
	V_position.reserve(0);
}
MaxValue::MaxValue(const MaxValue& m) {
	if (this != &m) *this = m;
}
MaxValue& MaxValue::operator=(const MaxValue& m) {
	if (this == &m) return *this;
	if (*this == m)	return *this;
	Max = m.Max;
	V_position = m.V_position;
	return *this;
}
bool MaxValue::operator==(const MaxValue& m) {
	if (V_position.size() == m.V_position.size()&&Max==m.Max) {
		int i = 0;
		for (auto x : V_position) {
			if (x != m.V_position[i]) return false;
		}
		return true;
	}
	return false;
}
std::vector<Position>& MaxValue::getVector() {
	return V_position;
}
void MaxValue::setValue(Position& p) {
	V_position.push_back(p);
}
void MaxValue::setMax(Position& p) {
	Max = p;
}
Position& MaxValue::getMax() {
	return Max;
}
MaxValue::~MaxValue()
{
}
