#include "Focus.h"
Focus::Focus()
{
}
void Focus::setName(std::string&  name) {
	nameFile = name;
}
Focus::Focus(const Focus& f) {
	if (this != &f) *this = f;
}
std::string& Focus::getName() {
	return nameFile;
}
int& Focus::getSize() {
	return segment;
}
void Focus::setSize(int& value) {
	segment = value;
}
Focus& Focus::operator=(const Focus& f) {
	if (this == &f) return *this; 
	if (*this == f) return *this;
	nameFile = f.nameFile;
	segment = f.segment;
	return *this;
}
bool Focus::operator==(const Focus& f) {
	if (nameFile == f.nameFile&&segment == f.segment) return this;
	return false;
}
Focus::~Focus()
{
}
