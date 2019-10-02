#include "Compartment.h"



Compartment::Compartment(double Start, double Stop)
{
	start = Start;
	stop = Stop;
	value = 0;
}
void Compartment::addValue() {
	value++;
}
bool Compartment::operator==(Compartment &C) {
	if (this->start == C.start && this->stop == C.stop) {
		if (this->value == C.value) return true;
	}
	return false;
}
Compartment& Compartment::operator=(Compartment &C) {
	if (this == &C) return *this;
	if (*this == C) return *this;
	this->start = C.start;
	this->stop = C.stop;
	this->value = C.value;
	return *this;
}
int Compartment::getValue() {
	return value;
}
std::string Compartment::view() {
	return std::to_string(start) + "\t" + std::to_string(stop) + "\t" + std::to_string(value) + "\n";
}
bool Compartment::comparison(double parameter) {
	if (start <= parameter && parameter < stop) {
		addValue();
		return true;
	}
	return false;
}
Compartment::~Compartment()
{
}
std::ostream& operator<<(std::ostream &is, Compartment &P) {
	is << P.start << "\t" << P.stop << "\t" << P.value << "\n";
}
