#pragma once
#include <string>
class Element
{
	std::string name;
	bool what;
public:
	Element();
	Element(const Element& e);
	Element& operator=(const Element& e);
	bool operator==(const Element& e);
	void setName(std::string Name);
	friend std::ostream& operator<<(std::ostream& is, const Element& e);
	std::string& getName();
	void goodFile();
	void badFile();
	bool& status();
	~Element();
};

