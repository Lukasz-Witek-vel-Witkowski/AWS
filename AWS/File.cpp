#include "File.h"



File::File()
{
	segments = new _SegmentF[maxIterator];
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
		while (eof()) { //warunek petli!!!
			std::cout << i++;
			file >> *this;
		}
		file.close();
	}
}
void File::preparationFile() {
	for (auto& x : vSection) {
		x.performance();
	}
}
bool File::eof() {
	int i = vSection.size();
	if (i > 4) {
		if (vSection[i - 1].size() == 0 && vSection[i - 2].size() == 0 && vSection[i-3].size()==0&& vSection[i-4].size() == 0 ) return false;
		else
			return true;
	}
	return true;
}
void File::saveFile() {
	std::ofstream file;
	int iterator = 0;
	std::string data = outputFolder + "\\" + nameFile.substr(11, nameFile.size()-1);
	file.open(data.c_str());
	if (file.good()) {
		for (auto& x : vSection) {
			for (auto& t : x.getVectorResultPerformance()) {
				file << t << ' ';
			}
			if (iterator++ % 3) file << "\n\n";
			else file << '\n';
		}
		file.close();
	}
}
void  File::addSection(Section& s) {
	vSection.push_back(s);
}
Section& File::getSection(unsigned int value) {
	if (vSection.empty()) {
		vSection.resize(1);
	}
	if (value < vSection.size())
		return vSection[value];
	else
		return vSection[vSection.size() - 1];
}
unsigned int File::getiterator() {
	return vSection.size();
}
File::~File()
{
	delete[] segments;
}
std::istream& operator>>(std::istream& file, File& f) {
	Record r;
	r.loadData(file);
	r.setCanal(f.getCanal());
	if (r.newSection()) {
		f.updateCanal();
	}
	else {
		f.settoSektorF(r);
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
	for (auto x : vSection) {
		x.clear();
	}
	vSection.clear();
	nameFile.clear();
}
void File::setOutputFolder(std::string name) {
	outputFolder = name;
}
void File::settoSektorF(Record& r) {
	switch (r.getCanal()) {
	case 0:
		segments[iteratorSegments].timer0[iteratorChanel] = r.getTime();
		segments[iteratorSegments].ch0After[iteratorChanel] = r.getAfter();
		segments[iteratorSegments].ch0Before[iteratorChanel] = r.getBefore();
		break;
	case 1:
		segments[iteratorSegments].timer1[iteratorChanel] = r.getTime();
		segments[iteratorSegments].ch1After[iteratorChanel] = r.getAfter();
		segments[iteratorSegments].ch1Before[iteratorChanel] = r.getBefore();
		break;
	case 2:
		segments[iteratorSegments].timer2[iteratorChanel] = r.getTime();
		segments[iteratorSegments].ch2After[iteratorChanel] = r.getAfter();
		segments[iteratorSegments].ch2Before[iteratorChanel] = r.getBefore();
		break;
	case 3:
		segments[iteratorSegments].ch0degetal[iteratorChanel] = r.getValue(0);
		segments[iteratorSegments].ch1degetal[iteratorChanel] = r.getValue(1);
		segments[iteratorSegments].ch2degetal[iteratorChanel] = r.getValue(2);
		break;
	}
}