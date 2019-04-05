#pragma once
#ifndef FILE_HPP
#define FILLE_HPP
//#include "Section.h"
#include "Segment.h"
class File
{
public:
	File();
	void setNameFile(std::string name);
	void setOutputFolder(std::string name);
	void setOutPutFile(std::string name);
	void setPath(std::string path);
	//void addSegment(_SegmentF& s);
	//_SegmentF& getSegment(unsigned int value);
	void loadFile();
	_SegmentF& getTemp();
	//bool eof(std::istream& file);
	//unsigned int getiterator();
	void saveFile();
	void SetOutPutFileCanal(std::string data);
	void setIterator(int Canal);
	//void updateCanal();
	int getCanal();
	void clear();
	~File();
private:
	_SegmentF temp;
	int canal;
	int iteratorSegments;
	int iteratorChanel;
	//std::vector<_SegmentF> vSegment; //tablica dynamiczna
	std::string nameFile;
	std::string path;
	std::string outPutFile;
	std::string outputFolder;
};
std::istream& operator>>(std::istream& file, File& f);
#endif // !FILE_HPP



