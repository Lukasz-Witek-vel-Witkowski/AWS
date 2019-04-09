#include "File.h"
File::File()
{
	iteratorSegments = 0;
	iteratorChanel = 0;
	canal = 0;
}
void File::setNameFile(std::string& name) {
	nameFile = name;
}
void File::setIterator(int iterator) {
	iteratorSegments = iterator;
}
int File::getCanal() { return canal; }
void File::loadFile() {
	std::ifstream file(path.c_str());
	int i = 1;
	std::cout <<"odczyt: "<< path << "\n";
	if (file.is_open()) {
		while (!file.eof()&&!getTemp().isEof()) { 
			file >> *this;
		}
		file.close();
	}
}
void File::saveFile() {
	std::ofstream file;
	int iterator = 0;
	std::string data = outputFolder + "\\" + nameFile.substr(0,nameFile.size()-4) + ".bin";
//	std::cout << data << "\n";
	file.open(data.c_str(), std::ios_base::binary);
//	std::cout << data << "\n";
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
	std::string* tab = new std::string[11];
	std::string name = NameFile.substr(0, NameFile.size() - 4);
	int i;
	int j;
	char c = '0';
	temp.clear();
	tab[10] = "mkdir "+ outPutFiles + "\\" + name;
	system(tab[10].c_str());
	_sleep(500);
	tab[10] = "mkdir " + outPutFiles + "\\" + name + "\\" + "AFTER";
	system(tab[10].c_str());
	_sleep(500);
	tab[10] = "mkdir " + outPutFiles + "\\" + name + "\\" + "BEFORE";
	system(tab[10].c_str());
	_sleep(500);
	tab[0] = outputFolder + "\\" + name + ".bin";
	std::cout << "plik do analizy: " << tab[0] << "\n";
	in.open(tab[0].c_str(), std::ios_base::binary);
	if (in.good()) {
		in.read(reinterpret_cast <char *>(&temp), sizeof(_SegmentF));
		in.close();
	for (i = 1; i < 9; i += 3) {
		tab[i] = outPutFiles + "\\" + name +"\\" +"AFTER" +"\\"+name +"_After" + c +".txt";
		tab[i+1] = outPutFiles + "\\" + name +"\\"+"BEFORE"+"\\"+name +"_Before" + c + ".txt";
		tab[i+2] = outPutFiles + "\\" + name +"\\" +name+"_Digital"+ c +".txt";
		c++;
	}
	for (i = 1; i < 10; i++) {
		out.open(tab[i].c_str());
		if (out.good()) {
			switch (i) {
			case 1: {
				for (j = 0; j < temp.itrCh0; j++) {
					out << (long long)temp.getChAfter(0, j) << " ";
				}
			} break;
			case 2: {
				for (j = 0; j < temp.itrCh0; j++) {
					out << (long long)temp.getChBefore(0, j) << " ";
				}
			} break;
			case 3: {
				for (j = 0; j < temp.itrDigital; j++) {
					out << (long long)temp.getChDigital(0, j) << " ";
				}
			} break;
			case 4: {
				for (j = 0; j < temp.itrCh1; j++) {
					out << (long long)temp.getChAfter(1, j) << " ";
				}
			} break;
			case 5: {
				for (j = 0; j < temp.itrCh1; j++) {
					out << (long long)temp.getChBefore(1, j) << " ";
				}
			}break;
			case 6: {
				for (j = 0; j < temp.itrDigital; j++) {
					out << (long long)temp.getChDigital(1, j) << " ";
				}
			} break;
			case 7: {
				for (j = 0; j < temp.itrCh2; j++) {
					out << (long long)temp.getChAfter(2, j) << " ";
				}
			} break;
			case 8: {
				for (j = 0; j < temp.itrCh2; j++) {
					out << (long long)temp.getChBefore(2, j) << " ";
				}
			} break;
			case 9: {
				for (j = 0; j < temp.itrDigital; j++) {
					out << (long long)temp.getChDigital(2, j) << " ";
				}
			} break;

			}
			out.close();
		}
	}
	delete[] tab;
	}
	
}
void File::setPath(std::string data) {
	path = data;
}
void File::segmentclear() {
	temp.clear();
}