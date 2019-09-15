#include "EngineMaximum.h"



EngineMaximum::EngineMaximum()
{
	system("cls");
	std::cout << "Ladowanie danych\n";
	manager.setConfig(config);
	fileResult = manager.getNameResultFile();
	b_program = manager.getProgramMethod();
	setLimit(manager.getLimit());
	//manager(config);
}


EngineMaximum::~EngineMaximum()
{
	//delete manage;
}
void EngineMaximum::run() {
	
	if (!b_program) {
		manager.runProcessing();
		int size = manager.getSize();
		std::string temp = "del " + fileResult;
		system(temp.c_str());
		for (int i = 0; i < size; i++) {
			system("cls");
			std::cout << "zrealizowano = " << (i * 100) / size << "[%] plik = "<<i<<"/"<<size <<"\n";
			Limit = manager.getDynamicLimit(i);
			saveToResultFile(AnalizerFiles(manager.getPerformanceData(i), manager.getThisFile()));
		}
	}
		system("cls");
		std::cout << "Weryfikacja danych \n";
		manager.divisionIntoAttributes(fileResult);
}
void EngineMaximum::setLimit(long limit) {
	Limit = limit;
}

std::vector<Block> EngineMaximum::AnalizerFiles(std::vector<Cell> V_Cell, std::string name) {
	comBefore = false;
	comSix60MHz = false;
	comTwo80MHz = false;
	V_block.clear();
	M_Before.clear();
	M_60MHz.clear();
	M_80MHz.clear();
	M_maximumBefore.clear();
	M_maximum60MHz.clear();
	M_maximum80MHz.clear();
	maxBefore = -1;
	max60MHz = -1;
	max80MHz = -1;
	M_index.clear();
	numOfCompartment = 0;
	for (int i = 0; i < V_Cell.size(); i++) {
		if (maxBefore == -1 && (V_Cell[i + 1].Before - V_Cell[i].Before > Limit)) {
			maxBefore = V_Cell[i].Before;
			comBefore = true;
		}
		if (maxBefore != -1 && V_Cell[i].Before < (maxBefore / 20)) {
			maxBefore = -1;
			comBefore = false;
		}
		if (max60MHz == -1 && (V_Cell[i + 1].CH60 - V_Cell[i].CH60) > Limit) {
			max60MHz = V_Cell[i].CH60;
			comSix60MHz = true;
		}
		if (max60MHz != -1 && V_Cell[i].CH60 < (max60MHz / 20)) {
			max60MHz = -1;
			comSix60MHz = false;
		}
		if (max80MHz == -1 && (V_Cell[i + 1].CH80 - V_Cell[i].CH80) > Limit) {
			max80MHz = V_Cell[i].CH80;
			comTwo80MHz = true;
		}
		if (max80MHz != -1 && V_Cell[i].CH80 < (max80MHz / 20)) {
			max80MHz = -1;
			comTwo80MHz = false;
		}
		if (comBefore) {
			M_Before[i] = V_Cell[i].Before;
			M_index[i] = numOfCompartment;
			if (maxBefore < V_Cell[i].Before) {
				maxBefore = V_Cell[i].Before;
			}
		}
		else{
			if (M_Before.size() > 0) {
				std::pair<int, double> tempMaxBefore = getMaximumMap(M_Before);
				M_maximumBefore[tempMaxBefore.first] = tempMaxBefore.second;
				numOfCompartment++;
				M_Before.clear();
			}
		}
		if (comSix60MHz) {
			M_60MHz[i] = V_Cell[i].CH60;
			if (max60MHz < V_Cell[i].CH60) {
				max60MHz = V_Cell[i].CH60;
			}
		}
		else {
			if (M_60MHz.size() > 0) {
				std::pair<int, double> tempMaxSix60MHz = getMaximumMap(M_60MHz);
				M_maximum60MHz[tempMaxSix60MHz.first] = tempMaxSix60MHz.second;
				M_60MHz.clear();
			}
		}
		if (comTwo80MHz) {
			M_80MHz[i] = V_Cell[i].CH80;

			if (max80MHz < V_Cell[i].CH80) {
				max80MHz = V_Cell[i].CH80;
			}
		}
		else {
			if (M_80MHz.size() > 0) {
				std::pair<int, double> tempMaxTwo80MHz = getMaximumMap(M_80MHz);
				M_maximum80MHz[tempMaxTwo80MHz.first] = tempMaxTwo80MHz.second;
				M_80MHz.clear();
			}
		}
	}
	for (auto x : M_maximumBefore) {
		double beforeMax = x.second;
		std::pair<int, double> max60 = getMaximum(M_index, M_maximum60MHz, getNumber(M_index, x.first));
		std::pair<int, double> max80 = getMaximum(M_index, M_maximum80MHz, getNumber(M_index, x.first));
		if (max60.first != -1 && max80.first != -1) {
			V_block.push_back(Block(name, max60.second / (double)beforeMax, max80.second / (double)beforeMax));
		//	std::cout << "size V_Block = " << V_block.size() << "\n";
		}
	}	
	//std::cout << "size V_Block = " << V_block.size() << "\n";
	return V_block;
}
std::pair<int, double> EngineMaximum::getMaximumMap(std::map<int, double> values) {
	double maximum = 0.0;
	int index = 0;

	for (auto it : values) {
		if (it.second > maximum) {
			index = it.first;


			maximum = it.second;
		}
	}

	return std::make_pair(index, maximum);
}

int EngineMaximum::getNumber(std::map<int, int> indexes, int numOfIndex) {
	for (auto it : indexes) {
		if (it.first == numOfIndex) {
			return it.second;
		}
	}
	return -1;
}

std::pair<int, double> EngineMaximum::getMaximum(std::map<int, int> indexes, std::map<int, double> & maximums, int compartment) {
	for (auto max : maximums) {
		for (auto index : indexes) {
			if (abs(index.first - max.first) < 20 && index.second == compartment) {
				std::pair<int, double> maximum = max;
				maximums.erase(max.first);
				return max;
			}
		}
	}

	return std::make_pair(-1, -1);
}
void EngineMaximum::saveToResultFile(std::vector<Block> V_block) {
	std::ofstream file(fileResult, std::ios::app);
	std::string data = "";
	int i = 1;
	if (file.good()) {
		for (auto x : V_block) {
			if (data == "") {
				data = x.NameFile;
				file <<"# "<<data << "\n";
				file <<i<<' '<< x.value60MHz << " " << x.value80MHz << "\n";
			}
			else {
				if (data == x.NameFile) {
					file << i << ' '<< x.value60MHz << " " << x.value80MHz << "\n";
				}
				else {
					data = x.NameFile;
					file <<"# "<< data << "\n";
					file << i << ' '<< x.value60MHz << " " << x.value80MHz << "\n";
				}
			}
			i++;
		}
		file.close();
	}
}
void maxWithFile() {

}