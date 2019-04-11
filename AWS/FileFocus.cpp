#include "FileFocus.h"



FileFocus::FileFocus()
{
}

void FileFocus::setFileIn(std::string name) {
	fileIN = name;
}
void FileFocus::setFocus(Focus& f) {
	fileIN = f.getName();
	V_Segment.clear();
	V_Segment.resize(f.getSize());
}
void FileFocus::loadFile() {
	std::ifstream file(fileIN.c_str());
	int i = 1;
	std::cout << "odczyt: " << fileIN << "\n";
	if (file.is_open()) {
		while (!file.eof()) {
			V_Segment[iterator++].loadData(file);
		}
		file.close();
	}
}
void FileFocus::saveFile() {
	std::ofstream file;
	std::string data;
	for (int i = 0; i < (int)V_Segment.size(); i++) {
		data = outputFolder + "\\" + fileIN.substr(0, fileIN.size() - 4) +"_"+std::to_string(i).c_str()+"-"+std::to_string(V_Segment.size()-1).c_str()+".bin";
		file.open(data.c_str(), std::ios_base::binary);
		if (file.good()) {
			file.write(reinterpret_cast <char *>(&V_Segment[i]), sizeof(_SegmentF)); //rzutowanie na zapis binarny
			file.close();
		}
	}
}
void FileFocus::setOutPutFiles(std::string name) {
	outPutFiles = name;
}
void FileFocus::setOutPutFolder(std::string name) {
	outputFolder = name;
}
FileFocus::~FileFocus()
{
}
