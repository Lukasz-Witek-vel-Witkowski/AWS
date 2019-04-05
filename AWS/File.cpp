#include "File.h"
File::File()
{
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
void File::saveFile() {
	std::ofstream file;
	int iterator = 0;
	std::string data = outputFolder + "\\" + nameFile.substr(0,nameFile.size()-4) + ".bin";
	std::cout << data << "\n";
	file.open(data.c_str(), std::ios_base::binary);
	if (file.good()) {
			file.write(reinterpret_cast <char *>(&temp), sizeof(_SegmentF)); //rzutowanie na zapis binarny
			iteratorSegments++;
		file.close();
	}
}
File::~File(){}
std::istream& operator>>(std::istream& file, File& f) {
	f.getTemp().loadData(file);
	return file;
}
void File::clear() {
	nameFile.clear();
}
void File::setOutputFolder(std::string name) {
	outputFolder = name;
}
_SegmentF& File::getTemp() {
	return temp;
}
void File::setOutPutFiles(std::string name) {
	outPutFiles = name;
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
	std::cout << "przetwarzanie pliku :" << NameFile << "\n";
		dataIn = outputFolder + "\\" + NameFile.substr(0, NameFile.size() - 4) + ".bin";
		dataOutAfter0 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_After0.txt";
		dataOutAfter1 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_After1.txt";
		dataOutAfter2 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_After2.txt";
		dataOutBefore0 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Before0.txt";
		dataOutBefore1 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Before1.txt";
		dataOutBefore2 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Before2.txt";
		dataOutdigital0 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Digital0.txt";
		dataOutdigital1 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Digital1.txt";
		dataOutdigital2 = outPutFiles + "\\" + NameFile.substr(0, NameFile.size() - 4) + "_Digital2.txt";
		in.open(dataIn.c_str() , std::ios_base::binary);
		std::cout <<"plik do analizy: "<< dataIn << "\n";
		if (in.good()) {
			in.read(reinterpret_cast <char *>(&temp), sizeof(_SegmentF));
			in.close(); //dal wielu blikow .bin!
		}
		temp;
		out.open(dataOutAfter0.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrCh0; j++) {
				out << (long long)temp.getChAfter(0, j) <<" ";
			}
			out.close();
		}
		out.open(dataOutAfter1.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrCh1; j++) {
				out << (long long)temp.getChAfter(1, j) << " ";
			}
			out.close();
		}
		out.open(dataOutAfter2.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrCh2; j++) {
				out << (long long)temp.getChAfter(2, j) << " ";
			}
			out.close();
		}
		out.open(dataOutBefore0.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrCh0; j++) {
				out << (long long)temp.getChBefore(0, j) << " ";
			}
			out.close();
		}
		out.open(dataOutBefore1.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrCh1; j++) {
				out << (long long)temp.getChBefore(1, j) << " ";
			}
			out.close();
		}
		out.open(dataOutBefore2.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrCh2; j++) {
				out << (long long)temp.getChBefore(2, j) << " ";
			}
			out.close();
		}
		out.open(dataOutdigital0.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrDigital; j++) {
				out << (long long)temp.getChDigital(0, j) << " ";
			}
			out.close();
		}
		out.open(dataOutdigital1.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrDigital; j++) {
				out << (long long)temp.getChDigital(1, j) << " ";
			}
			out.close();
		}
		out.open(dataOutdigital2.c_str());
		if (out.good()) {
			for (j = 0; j < temp.itrDigital; j++) {
				out << (long long)temp.getChDigital(2, j) << " ";
			}
			out.close();
		}

}
void File::setPath(std::string data) {
	path = data;
}