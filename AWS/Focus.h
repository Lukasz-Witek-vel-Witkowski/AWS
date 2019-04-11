#pragma once
#include <string>
class Focus
{
	std::string nameFile;
	int segment;
public:
	Focus();
	Focus(const Focus& f);
	Focus& operator=(const Focus& f);
	bool operator==(const Focus& f);
	void setName(std::string&  name);
	std::string& getName();
	int& getSize();
	void setSize(int& value);
	~Focus();
};

