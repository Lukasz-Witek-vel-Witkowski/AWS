#include "Parameter.h"



Parameter::Parameter(int id)
{
	this->id;
	what = false;
	P60MHz = 0.0;
	P80MHz = 0.0;
	NameFile = "";
}
Parameter::Parameter(bool what, int id) {
	this->id;
	this->what = what;
	P60MHz = 0.0;
	P80MHz = 0.0;
	NameFile = "";
}

Parameter::~Parameter()
{
}
std::istream& operator>>(std::istream &is, Parameter &P) {
	is >> P.P60MHz;
	is >> P.P80MHz;
	is >> P.NameFile;
	return is;
}
std::ostream& operator<<(std::ostream &is, Parameter &P) {
	is << P.P60MHz;
	is << "\t";
	is << P.P80MHz;
	is << "\t";
	is << P.NameFile;
	return is;
}
bool operator<(const Parameter &t, const Parameter &P) {
	if (t.what) {
		if (t.P80MHz < P.P80MHz) return true;
		return false;
	}
	if (t.P60MHz < P.P60MHz) return true;
	return false;
}
Parameter& Parameter::operator=(Parameter &P) {
	if (this == &P) return *this;
	if (*this == P) return *this;
	this->P60MHz = P.P60MHz;
	this->P80MHz = P.P80MHz;
	this->NameFile = P.NameFile;
	this->what = P.what;
	return *this;
}
bool Parameter::operator==(Parameter &P) {
	if (this->what == P.what) {
		if (this->P60MHz == P.P60MHz&&this->P80MHz == P.P80MHz&&this->NameFile == P.NameFile&&this->id == P.id) {
			return true;
		}
	}
	return false;
}
double Parameter::getValue() {
	if (what) {
		return P80MHz;
	}
	return P60MHz;
}
void Parameter::shift() {
	if (what) what = false;
	what = true;
}