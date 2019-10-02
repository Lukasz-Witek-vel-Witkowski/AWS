#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
class BaseFileConfig
{
private:
	std::string skip;
	char C;
	std::string end;
	std::size_t position;
protected:
	std::map<std::string, std::string> Parameter;
public:
	BaseFileConfig();
	void setCharsSkip(std::string Skip);
	void setPosition(int pos);
	void setEnd(std::string End);
	virtual void run(std::string path);
	void setCharWall(char c);
	virtual std::string interpreter(std::string)=0;
	virtual ~BaseFileConfig();
};



