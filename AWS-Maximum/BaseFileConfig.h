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
	BaseFileConfig() { position = 0; }
	void setCharsSkip(std::string Skip) {
		skip = Skip;
	}
	void setPosition(int pos) {
		position = pos;
	}
	void setEnd(std::string End) {
		end = End;
	}
	virtual void run(std::string path) {
		std::ifstream file(path);
		std::string data = "";
		while (file.good()) {
			std::getline(file, data);
			std::cout << data<<" - "<<data.find(end)<<" - "<<end<<"\n";
			if (data.find(skip) != position) {
				Parameter[data.substr(0, data.find(C))] = data.substr(data.find(C)+1);
				std::cout <<data<<" - "<< data.substr(0, data.find(C)) <<" - "<< data.substr(data.find(C) + 1) << "-"<<data.find(C) << "\n";
				continue;
			}
			if (data.find(end) == position) break;
		}
	}
	void setCharWall(char c) {
		C = c;
	}
	virtual std::string interpreter(std::string)=0;
	virtual ~BaseFileConfig() {};
};



