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
	void addSection(Section& s);
	Section& getSection(unsigned int value);
	void loadFile();
	bool eof();
	unsigned int getiterator();
	void preparationFile();
	void settoSektorF(Record& r);
	void saveFile();
	void setCanal(int Canal);
	void updateCanal();
	int getCanal();
	void clear();
	~File();
private:
	_SegmentF* segments;
	int canal;
	int iteratorSegments;
	int iteratorChanel;
	std::vector<Section> vSection; //tablica dynamiczna
	std::string nameFile;
	std::string outputFolder;
};
std::istream& operator>>(std::istream& file, File& f);
#endif // !FILE_HPP



