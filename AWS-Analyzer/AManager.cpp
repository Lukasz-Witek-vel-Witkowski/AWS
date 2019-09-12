#include "AManager.h"

Manager::Manager() {
	iterator = -1;
	active = false;
	alterbative = false;
	data = "";
}
Manager::Manager(std::string data) {
	nameFolderOne = data;
	active = false;
}
std::string& Manager::nextFile() {
	if (iterator < 0) iterator = (int)vFile.size()-1;
	if(iterator>0)	return vFile[--iterator];
	return data;
}
void Manager::resetIterator() {
	iterator = -1;
	//iteratorFocus = -1;
}
int Manager::sizeProduction() {
	return (int)((int)vFile.size()*(int)iterator);
}
void Manager::setNameFolder(std::string name, std::string nametwo) {
	nameFolderOne = name;
	nameFolderSecend = nametwo;
	active = false;
}
/*int Manager::sizeFocus() {
	return (int)vFileFocus.size();
}*/
int Manager::size() {
	return (int)vFile.size();
}
void Manager::countSegments(int value) {
	std::cout << "Loading data...\n";
	std::ifstream in;
	std::ofstream out;
	std::string temp;
	std::string liczba="";
	std::string nameFile;
	double valueTemp;
	double valueMax;
	Chart chart;
	int program = 0;
	iterator = 0;
	int seg = 0;
	int control = 4;
	out.open(fileFocus);
	if (value == 1) 
		nameFile = nameFolderOne;
	else if (value == 2)
		nameFile = nameFolderSecend;
	if (out.good()) {
		for (int i = 0; i < (int)vFile.size(); i++) {
			in.open(nameFile + "\\" + vFile[iterator].c_str());
			if (in.good()) {
				while (!in.eof()) {
					std::getline(in, temp);
					temp.push_back('g');
					for (auto x : temp){ 
						if ( x == '\t') {
							valueTemp = atof(liczba.c_str());
							if (valueMax<valueTemp) {
								std::cout << "min = " << valueTemp << "\t" << "max = " << valueMax;
								switch (program) {
								case 0:
									std::cout << "\tMaxPrimary\n"; break;
								case 1:
									std::cout << "\tMaxOrgin\n"; break;
								case 2:
									std::cout << "\tMaxOne\n"; break;
								case 3:
									std::cout << "\tMaxSecend\n"; break;
								}
								valueMax = valueTemp;
							}
							liczba = "";
						}
						else if (x == 'g') {
							 chart.setMax(program, valueMax); valueMax = 0.0; valueTemp = 0.0;
							 program++;
							 if (program == 4) {
								 chart.setFileName(vFile[iterator]);
								 vChart.push_back(chart);
								 program = 0;
							 }
						}
						liczba += x;
					}
				}
				in.close();
			}
			out << chart.getMax(0) << "\t" << chart.getMax(1) << "\t" << chart.getMax(2) << "\t" << chart.getMax(3) << "\t" << chart.getFile() << "\n";
			iterator++;
			seg = 0;
			control = 4;
		}
		out.close();
	}
	//loadFileIn();
}
void Manager::fileSearch(bool what, int modul) {
	std::string temp;
	std::string temp_next;
	std::ifstream file;
	switch (modul) {
	case 1:
		if (!active) {
			temp = "del ";
			temp += fileList;
			system(temp.c_str());
			temp_next = "(cd && dir /b " + nameFolderOne + ") >> " + fileList;
			//active = true;
		}break;
	case 2:
		if (!active) {
			temp_next = "(cd && dir /b " + nameFolderSecend + ") >> " + fileList;
			//active = true;
		}break;
	}
	system(temp_next.c_str());
	_sleep(1000);
	file.open(fileList);
	if (file.good()) {
		file >> path;
		do {
			temp_next = temp;
			std::getline(file, temp);
			if (temp.size() > 5) {
				if (temp[temp.size() - 3] == 'M'&&temp[temp.size() - 2] == 'H'&&temp[temp.size() - 1] == 'z' && !alterbative) {
					vFile.push_back(temp);
				}
			}
		} while (temp_next != temp);
		file.close();
	}
	if (what) {
		countSegments(1);
		countSegments(2);
	}
}
void Manager::onAlternative() {
	alterbative = true;
}
void Manager::offAlternative() {
	alterbative = false;
}
void Manager::setVector(std::vector<std::string>& v) {
	vFile.clear();
	for (auto& x : v) {
		vFile.push_back(x);
	}
}
void Manager::run() {
		for (auto& x : vChart) {
			x.setPrimeryName(managerName.findName(x.getIdName()));
		}
}
void Manager::analization() {
	for(auto& x: vChart)	managerChart.setValueChart(&x);
	managerChart.analization();

}
void Manager::saveData() {
	std::ofstream file;
	file.open(nameFileData.c_str(), std::ios_base::binary);
	if (file.good()) {
		std::cout << "plik";
		for (auto& x : vChart) {
			file << x<<"\n";
		}
		file.close();
	}
}
void Manager::nsetNameFile(std::string name) {
	managerName.setNameFile(name);
}
std::string Manager::nfindName(std::string data) {
	managerName.findName(data);
}
void Manager::nloadData() {
	managerName.loadData();
}
void Manager::loadData() {
	std::ifstream file;
	Chart x;
	Chart Temp;
	vChart.clear();
	file.open(nameFileData.c_str());
	if (file.good()) {
		do {
			Temp = x;
			file >> x;
			vChart.push_back(x);
		} while (!(Temp == x));
		file.close();
	}
}
void Manager::setNameFileData(std::string data) {
	nameFileData = data;
}
Manager::~Manager() {}