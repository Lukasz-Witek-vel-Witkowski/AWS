#include "GeneratorBaze.h"
GeneratorBaze::GeneratorBaze() {
	minimumValue = 0;
	massage = true;
	doubleActive = false;
	generationProbabilistic = false;
	Double = null;
}
GeneratorBaze::~GeneratorBaze() {
	delete[] Double;
};
void GeneratorBaze::setRange(int value) {
	range = value;
}
void GeneratorBaze::configRandomNumbers() {
	srand((unsigned int)time(null));
	activeRandomNumber = true;
}
void GeneratorBaze::setFrequency(int value) {
	frequence = value;
}
void GeneratorBaze::setMinimumValue(int value) {
	minimumValue = value;
}
unsigned int GeneratorBaze::getRange() {
	return range;
}
unsigned int GeneratorBaze::getFrequence() {
	return frequence;
}
void GeneratorBaze::massageDisplay(bool value) {
	massage = value;
}
void  GeneratorBaze::configProbabilistic(double start, double end, int Frequency) {
	if (start != end && end!= 0) {
		delete[] Double;
		Double = new double[2];
		doubleActive = true;
		configRandomNumbers();
		setFrequency(Frequency);
		Double[0] = start;
		Double[1] = end;
		generationProbabilistic = true;
	}
	else {
		if (massage)
			std::cout << "The generator has bad parameters!\n";
	}
}
double GeneratorBaze::getStart() {
	if (doubleActive) {
		return Double[0];
	}
	return 0.0;
}
double GeneratorBaze::getStop() {
	if (doubleActive) {
		return Double[1];
	}
	return 0.0;
}
