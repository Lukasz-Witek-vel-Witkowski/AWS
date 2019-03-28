#include "File.h"



File::File()
{
	//segments = new _SegmentF[maxIterator];
	iteratorSegments = 0;
	iteratorChanel = 0;
	canal = 0;
}
void File::setNameFile(std::string name) {
	nameFile = name;
}
void File::setCanal(int Canal) {
	canal = Canal;
}
int File::getCanal() { return canal; }
void File::loadFile() {
	std::ifstream file(nameFile.c_str());
	int i = 1;
	if (file.is_open()) {
		while (eof(file)) { //warunek petli!!!
			std::cout << i++;
			file >> *this;
		}
		file.close();
	}
}
/*void File::preparationFile() {
	for (auto& x : vSection) {
		x.performance();
	}
}*/
bool File::eof(std::istream& file) {
	if (!file.eof()) {
		if (temp.getIterator() == (maxIterator - 1)) return false;
		return true;
	}
	else
		return false;
}
void File::saveFile() {
	std::ofstream file;
	int iterator = 0;
	std::string data = outputFolder + "\\" + nameFile.substr(11, nameFile.size()-1);
	file.open(data.c_str());
	if (file.good()) {
		for (auto& x : vSegment) {
			file.write(reinterpret_cast <char *>(&x), sizeof(x)); //rzutowanie na zapis binarny
		}
		file.close();
	}
}
void  File::addSegment(_SegmentF& s) {
	vSegment.push_back(s);
}
_SegmentF& File::getSegment(unsigned int value) {
	if (vSegment.empty()) {
		vSegment.resize(1);
	}
	if (value < vSegment.size())
		return vSegment[value];
	else
		return vSegment[vSegment.size() - 1];
}
unsigned int File::getiterator() {
	return vSegment.size();
}
File::~File()
{
	//delete[] segments;
}
std::istream& operator>>(std::istream& file, File& f) {
	f.getTemp().loadData(file);
	//r.setCanal(f.getCanal());
	if (f.getTemp().isFull()) {
		f.addSegment(f.getTemp());
		f.getTemp().reset();
	}
	return file;
}
void File::updateCanal() {
	iteratorChanel = 0;
	canal++;
	if (canal > 4) {
		canal = 0;
		iteratorSegments++;
	}
}
void File::clear() {
	//for (auto x : vSegment) {
	//	x.clear();
	//}
	vSegment.clear();
	nameFile.clear();
}
void File::setOutputFolder(std::string name) {
	outputFolder = name;
}
_SegmentF& File::getTemp() {
	return temp;
}
/*void File::settoSektorF(Record& r) {
	switch (r.getCanal()) {
	case 0:
	case 1:
	case 2:
		segments[iteratorSegments].setTimer(r.getCanal(), iteratorChanel, r.getTime());
		segments[iteratorSegments].setChAfter(r.getCanal(), iteratorChanel, r.getAfter());
		segments[iteratorSegments].setChBefore(r.getCanal(), iteratorChanel, r.getBefore());
		break;
	case 3:
		segments[iteratorSegments].setChDegetal(0, iteratorChanel, r.getValue(0));
		segments[iteratorSegments].setChDegetal(1, iteratorChanel, r.getValue(1));
		segments[iteratorSegments].setChDegetal(2, iteratorChanel, r.getValue(2));
		break;
	}
}*/