#pragma once
#include "Segment.h"
#include "Focus.h"
#include <vector>
#pragma warning(suppress : 4996)
#pragma warning(disable : 4996)
class FileFocus
{
	std::string fileIN; //nazwa pliku wejsciowego
	std::vector<_SegmentF> V_Segment;
	long iterator;
	std::string path; //zmienna przechowujaca nawe scierzki
	std::string outPutFiles; //zmienna przechowujaca nazwe folderu typu output
	std::string outputFolder; //zmienna przechowujaca nazwe folderu typu result
public:
	FileFocus();
	void loadFile();
	void saveFile();
	void setOutPutFiles(std::string name);
	void setOutPutFolder(std::string name);
	void setFocus(Focus& f);
	void setFileIn(std::string name);
	~FileFocus();
};

