#pragma once
#include <string>
class Parameter
{
	int id;
	bool what;
	double P60MHz;
	double P80MHz;
	std::string NameFile;
public:
	Parameter(int id);
	Parameter(bool what, int id);
	double getValue();
	void shift();
	friend bool operator<(const Parameter &t, const Parameter &P);
	bool operator==(Parameter &P);
	Parameter& operator=(Parameter &P);
	friend std::istream& operator>>(std::istream &is, Parameter &P);
	friend std::ostream& operator<<(std::ostream &is, Parameter &P);
	~Parameter();
};
