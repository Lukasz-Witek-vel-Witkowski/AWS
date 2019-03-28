#pragma once
#ifndef FILE_HPP
#define FILLE_HPP
#include "Section.h"
#include "Segment.h"
class File
{
public:
	File();
	void setNameFile(std::string name);
	void setOutputFolder(std::string name);
	void addSegment(_SegmentF& s);
	_SegmentF& getSegment(unsigned int value);
	void loadFile();
	_SegmentF& getTemp();
	bool eof(std::istream& file);
	unsigned int getiterator();
	//void preparationFile();
	//void settoSektorF(Record& r);
	void saveFile();
	void setCanal(int Canal);
	void updateCanal();
	int getCanal();
	void clear();
	~File();
private:
	_SegmentF temp;
	int canal;
	int iteratorSegments;
	int iteratorChanel;
	std::vector<_SegmentF> vSegment; //tablica dynamiczna
	std::string nameFile;
	std::string outputFolder;
};
std::istream& operator>>(std::istream& file, File& f);
#endif // !FILE_HPP



