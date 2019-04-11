#include "File.h"
File::File()
{
}
void File::setFileIn(std::string name) {
	fileIN = name;
}
void File::setFocus(Focus& f) {
	fileIN = f.getName();
	V_Segment.clear();
	V_Segment.resize(f.getSize());
}
void File::loadFile() {
	nameFile = path + "\\" + fileIN;
	std::ifstream file(nameFile.c_str());
	int i = 1;
	iterator = 0;
	std::cout << "odczyt: " << fileIN << "\n";
	if (file.is_open()) {
		while (iterator < V_Segment.size()) {
			V_Segment[iterator].loadData(file);
			if (V_Segment[iterator].isFull()) {
				V_Segment[iterator].isFull() = false;
				iterator++;
			}
		}
		file.close();
	}
}
void File::saveFile() {
	std::ofstream file;
	std::string data;
	int i = 0;
	for (auto& x:V_Segment) {
		if (V_Segment.size() == 1) 
			data = fileIN.substr(0, fileIN.size() - 4) + ".bin";
		else
		data = fileIN.substr(0, fileIN.size() - 4) + "_" + std::to_string(++i).c_str() + "-" + std::to_string(V_Segment.size()).c_str() + ".bin";
		vNameFileBinary.push_back(data);
		data = outputFolder + "\\" + data;
		file.open(data.c_str(), std::ios_base::binary);
		if (file.good()) {
			file.write(reinterpret_cast <char *>(&x), sizeof(_SegmentF)); //rzutowanie na zapis binarny
			file.close();
		}
	}
}
void File::setOutPutFiles(std::string name) {
	outPutFiles = name;
}
void File::setOutPutFolder(std::string name) {
	outputFolder = name;
}
std::vector<std::string>& File::getVector() {
	return vNameFileBinary;
}
void File::setPath(std::string name) {
	path = name;
}
void File::SetOutPutFileCanal(std::string NameFile) {
	std::ifstream in;
	std::ofstream out;
	std::string* tab = new std::string[11];
	std::string name = NameFile.substr(0, NameFile.size() - 4);
	int i;
	int j;
	char c = '0';
	V_Segment.clear();
	V_Segment.resize(1);
	tab[10] = "mkdir " + outPutFiles + "\\" + name;
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
		in.read(reinterpret_cast <char *>(&V_Segment[0]), sizeof(_SegmentF));
		in.close();
		for (i = 1; i < 9; i += 3) {
			tab[i] = outPutFiles + "\\" + name + "\\" + "AFTER" + "\\" + name + "_After" + c + ".txt";
			tab[i + 1] = outPutFiles + "\\" + name + "\\" + "BEFORE" + "\\" + name + "_Before" + c + ".txt";
			tab[i + 2] = outPutFiles + "\\" + name + "\\" + name + "_Digital" + c + ".txt";
			c++;
		}
		for (i = 1; i < 10; i++) {
			out.open(tab[i].c_str());
			if (out.good()) {
				switch (i) {
				case 1: {
					for (j = 0; j < V_Segment[0].itrCh0; j++) {
						out << (long long)V_Segment[0].getChAfter(0, j) << " ";
					}
				} break;
				case 2: {
					for (j = 0; j < V_Segment[0].itrCh0; j++) {
						out << (long long)V_Segment[0].getChBefore(0, j) << " ";
					}
				} break;
				case 3: {
					for (j = 0; j < V_Segment[0].itrDigital; j++) {
						out << (long long)V_Segment[0].getChDigital(0, j) << " ";
					}
				} break;
				case 4: {
					for (j = 0; j < V_Segment[0].itrCh1; j++) {
						out << (long long)V_Segment[0].getChAfter(1, j) << " ";
					}
				} break;
				case 5: {
					for (j = 0; j < V_Segment[0].itrCh1; j++) {
						out << (long long)V_Segment[0].getChBefore(1, j) << " ";
					}
				}break;
				case 6: {
					for (j = 0; j < V_Segment[0].itrDigital; j++) {
						out << (long long)V_Segment[0].getChDigital(1, j) << " ";
					}
				} break;
				case 7: {
					for (j = 0; j < V_Segment[0].itrCh2; j++) {
						out << (long long)V_Segment[0].getChAfter(2, j) << " ";
					}
				} break;
				case 8: {
					for (j = 0; j < V_Segment[0].itrCh2; j++) {
						out << (long long)V_Segment[0].getChBefore(2, j) << " ";
					}
				} break;
				case 9: {
					for (j = 0; j < V_Segment[0].itrDigital; j++) {
						out << (long long)V_Segment[0].getChDigital(2, j) << " ";
					}
				} break;

				}
				out.close();
			}
		}
		delete[] tab;
	}

}
File::~File()
{
}
