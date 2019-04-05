#pragma once
#ifndef FILE_HPP
#define FILLE_HPP
#include "Segment.h"
class File
{
public:
	File();
	void setNameFile(std::string name);
	void setOutputFolder(std::string name);
	void setOutPutFiles(std::string name);
	void setPath(std::string path);
	void loadFile();
	_SegmentF& getTemp();
	void saveFile();
	void SetOutPutFileCanal(std::string data);
	void setIterator(int Canal);
	int getCanal();
	void clear();
	~File();
private:
	_SegmentF temp;
	int canal;
	int iteratorSegments;
	int iteratorChanel;
	std::string nameFile;
	std::string path;
	std::string outPutFiles;
	std::string outputFolder;
};
std::istream& operator>>(std::istream& file, File& f);
#endif // !FILE_HPP



