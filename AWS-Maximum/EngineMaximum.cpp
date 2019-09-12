#include "EngineMaximum.h"



EngineMaximum::EngineMaximum()
{
	manager.setConfig(config);
	//manager(config);
}


EngineMaximum::~EngineMaximum()
{
	//delete manage;
}
void EngineMaximum::run() {
	manager.runProcessing();
	int size = manager.getSize();
	for (int i = 0; i < size; i++) {
		AnalizerFiles(manager.getPerformanceData(i),"");
	}
}

std::vector<Block> EngineMaximum::AnalizerFiles(std::vector<Cell> V_Cell, std::string name) {
	compartmentBefore = false;
	compartmentSix60MHz = false;
	compartmentTwo80MHz = false;
	V_block.clear();
	tempBefore.clear();
	tempSix60MHz.clear();
	tempTwo80MHz.clear();
	maximumBefore.clear();
	maximumSix60MHz.clear();
	maximumTwo80MHz.clear();
	maxBefore = -1;
	maxSix60MHz = -1;
	maxTwo80MHz = -1;
	indexes.clear();
	numOfCompartment = 0;
	for (int i = 0; i < V_Cell.size(); i++) {
		if (maxBefore == -1 && (V_Cell[i + 1].Before - V_Cell[i].Before > Limit)) {
			compartmentBefore = true;
			maxBefore = V_Cell[i].Before;
		}
		if (maxBefore != -1 && V_Cell[i].Before < (maxBefore / 20)) {
			compartmentBefore = false;
			maxBefore = -1;
		}
		if (maxSix60MHz == -1 && (V_Cell[i + 1].CH60 - V_Cell[i].CH60) > Limit) {
			compartmentSix60MHz = true;
			maxSix60MHz = V_Cell[i].CH60;
		}
		if (maxSix60MHz != -1 && V_Cell[i].CH60 < (maxSix60MHz / 20)) {
			compartmentSix60MHz = false;
			maxSix60MHz = -1;
		}
		if (maxTwo80MHz == -1 && (V_Cell[i + 1].CH80 - V_Cell[i].CH80) > Limit) {
			compartmentTwo80MHz = true;
			maxTwo80MHz = V_Cell[i].CH80;
		}
		if (maxTwo80MHz != -1 && V_Cell[i].CH80 < (maxTwo80MHz / 20)) {
			compartmentTwo80MHz = false;
			maxTwo80MHz = -1;
		}
		if (compartmentBefore) {


			tempBefore[i] = V_Cell[i].Before;
			indexes[i] = numOfCompartment;

			if (maxBefore < V_Cell[i].Before) {
				maxBefore = V_Cell[i].Before;
			}
		}
		if (!compartmentBefore) {
			if (tempBefore.size() > 0) {
				std::pair<int, double> tempMaxBefore = getMaximumFromMap(tempBefore);
				maximumBefore[tempMaxBefore.first] = tempMaxBefore.second;
				numOfCompartment++;
				tempBefore.clear();
			}
		}

		if (compartmentSix60MHz) {
			tempSix60MHz[i] = V_Cell[i].CH60;

			if (maxSix60MHz < V_Cell[i].CH60) {
				maxSix60MHz = V_Cell[i].CH60;
			}
		}
		if (!compartmentSix60MHz) {
			if (tempSix60MHz.size() > 0) {
				std::pair<int, double> tempMaxSix60MHz = getMaximumFromMap(tempSix60MHz);
				maximumSix60MHz[tempMaxSix60MHz.first] = tempMaxSix60MHz.second;
				tempSix60MHz.clear();
			}
		}

		if (compartmentTwo80MHz) {
			tempTwo80MHz[i] = V_Cell[i].CH80;

			if (maxTwo80MHz < V_Cell[i].CH80) {
				maxTwo80MHz = V_Cell[i].CH80;
			}
		}
		if (!compartmentTwo80MHz) {
			if (tempTwo80MHz.size() > 0) {
				std::pair<int, double> tempMaxTwo80MHz = getMaximumFromMap(tempTwo80MHz);
				maximumTwo80MHz[tempMaxTwo80MHz.first] = tempMaxTwo80MHz.second;
				tempTwo80MHz.clear();
			}
		}
	}
	for (auto it : maximumBefore) {
		double beforeMax = it.second;
		int numOfCompartment = getNumberOfCompartment(indexes, it.first);
		std::pair<int, double> maxSix60MHz = getMaximumFromCompartment(indexes, maximumSix60MHz, numOfCompartment);
		std::pair<int, double> maxTwo80MHz = getMaximumFromCompartment(indexes, maximumTwo80MHz, numOfCompartment);

		if (maxSix60MHz.first != -1 && maxTwo80MHz.first != -1) {
			V_block.push_back(Block(name, maxSix60MHz.second / (double)beforeMax, maxTwo80MHz.second / (double)beforeMax));
		}
	}
	return V_block;
}
std::pair<int, double> EngineMaximum::getMaximumFromMap(std::map<int, double> values) {
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

int EngineMaximum::getNumberOfCompartment(std::map<int, int> indexes, int numOfIndex) {
	for (auto it : indexes) {
		if (it.first == numOfIndex) {
			return it.second;
		}
	}
	return -1;
}

std::pair<int, double> EngineMaximum::getMaximumFromCompartment(std::map<int, int> indexes, std::map<int, double> & maximums, int compartment) {
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