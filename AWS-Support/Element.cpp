#include "Element.h"



Element::Element()
{
}
void Element::setName(std::string Name) {
	name = Name;
}
Element::Element(const Element& e) {
	if (this != &e) *this = e;
}
Element& Element::operator=(const Element& e) {
	if (this == &e) return *this;
	if (*this == e)	return *this;
	name = e.name;
	what = e.what;
	return *this;
}
bool Element::operator==(const Element& e) {
	if (name == e.name&&what == e.what) return true;
	return false;
}
std::string& Element::getName() {
	return name;
}
void Element::goodFile() {
	what = true;
}
void Element::badFile() {
	what = false;
}
bool& Element::status() {
	return what;
}
Element::~Element()
{
}
std::ostream& operator<<(std::ostream& is,const Element& e) {
	is << e.name.substr(0,e.name.size()-13) << "\n";
	return is;
}