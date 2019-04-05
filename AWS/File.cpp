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
void File::setIterator(int iterator) {
	iteratorSegments = iterator;
}
int File::getCanal() { return canal; }
void File::loadFile() {
	std::ifstream file(path.c_str());
	int i = 1;
	if (file.is_open()) {
		while (!file.eof()) { //warunek petli!!!
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
/*bool File::eof(std::istream& file) {
	if (!file.eof()) {
		if (temp.getIterator() == (maxIterator - 1)) return false;
		return true;
	}
	else
		return false;
}*/
void File::saveFile() {
	std::ofstream file;
	int iterator = 0;
	std::string data = outputFolder + "\\" + nameFile.substr(8,nameFile.size()-4) + ".bin";
	std::cout << data << "\n";
	file.open(data.c_str());
	if (file.good()) {
			file.write(reinterpret_cast <char *>(&temp), sizeof(_SegmentF)); //rzutowanie na zapis binarny
			iteratorSegments++;
		file.close();
	}
}
/*void  File::addSegment(_SegmentF& s) {
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
	return (unsigned)vSegment.size();
}*/
File::~File()
{
	//delete[] segments;
}
std::istream& operator>>(std::istream& file, File& f) {
	f.getTemp().loadData(file);
	/*if (f.getTemp().isFull()) {
		f.addSegment(f.getTemp());
		f.getTemp().reset();
	}*/
	return file;
}
/*void File::updateCanal() {
	iteratorChanel = 0;
	canal++;
	if (canal > 4) {
		canal = 0;
		iteratorSegments++;
	}
}*/
void File::clear() {
	nameFile.clear();
}
void File::setOutputFolder(std::string name) {
	outputFolder = name;
}
_SegmentF& File::getTemp() {
	return temp;
}
void File::setOutPutFile(std::string name) {
	outPutFile = name;
}
void File::SetOutPutFileCanal(std::string NameFile) {
	std::ifstream in;
	std::ofstream out;
	std::string dataIn;
	std::string dataOutAfter0;
	std::string dataOutAfter1;
	std::string dataOutAfter2;
	std::string dataOutBefore0;
	std::string dataOutBefore1;
	std::string dataOutBefore2;
	std::string dataOutdigital0;
	std::string dataOutdigital1;
	std::string dataOutdigital2;
	int j;
	for (int i = 0; i < iteratorSegments; i++) {
		dataIn = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + ".bin";
		dataOutAfter0 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_After0.txt";
		dataOutAfter1 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_After1.txt";
		dataOutAfter2 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_After2.txt";
		dataOutBefore0 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Before0.txt";
		dataOutBefore1 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Before1.txt";
		dataOutBefore2 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Before2.txt";
		dataOutdigital0 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Digital0.txt";
		dataOutdigital1 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Digital1.txt";
		dataOutdigital2 = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Digital2.txt";
		std::cout << dataIn << "\n";
		in.open(dataIn.c_str());
		if (in.good()) {
			in.read(reinterpret_cast <char *>(&temp), sizeof(_SegmentF));
			in.close(); //dal wielu blikow .bin!
		}
		temp;
		out.open(dataOutAfter0.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChAfter(0, j) << " ";
			}
			out.close();
		}
		out.open(dataOutAfter1.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChAfter(1, j) << " ";
			}
			out.close();
		}
		out.open(dataOutAfter2.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChAfter(2, j) << " ";
			}
			out.close();
		}
		out.open(dataOutBefore0.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChBefore(0, j) << " ";
			}
			out.close();
		}
		out.open(dataOutBefore1.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChBefore(1, j) << " ";
			}
			out.close();
		}
		out.open(dataOutBefore2.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChBefore(2, j) << " ";
			}
			out.close();
		}
		out.open(dataOutdigital0.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChDigital(0, j) << " ";
			}
			out.close();
		}
		out.open(dataOutdigital1.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChDigital(1, j) << " ";
			}
			out.close();
		}
		out.open(dataOutdigital2.c_str());
		if (out.good()) {
			for (j = 0; j < 1024; j++) {
				out << (long)temp.getChDigital(2, j) << " ";
			}
			out.close();
		}
	}

}
void File::setPath(std::string data) {
	path = data;
}