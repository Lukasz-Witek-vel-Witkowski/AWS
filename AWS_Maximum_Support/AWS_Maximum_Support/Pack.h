#pragma once
#include <string>
struct Pack
{
	std::string fileCH1;
	std::string fileCH2;
	std::string fileCH3;
	Pack() {
		fileCH1 = "";
		fileCH2 = "";
		fileCH3 = "";
	}
	Pack(std::string data1, std::string data2, std::string data3) {
		fileCH1 = data1;
		fileCH2 = data2;
		fileCH3 = data3;
	}
	~Pack() {};
};