#include "Generator.hpp"
Generator::Generator():GeneratorBaze() {
	range = 0;
	frequence = 0;
	activeRandomNumber = false;
	collectionbreak = false;
}
Generator::Generator(int Range, int Frequency):GeneratorBaze() {
	configRandomNumbers();
	setRange(Range);
	setFrequency(Frequency);
	collectionbreak = false;
}
void Generator::useBreakCollection() {
	collectionbreak = true;
}
void Generator::setBreakParameter(int value) {
	if(collectionbreak)
	Vbreak.push_back(value);
}
void Generator::configRandomNumbers() {
	srand((unsigned int) time(null));
	activeRandomNumber = true;
}
void Generator::generationNumber(int& result) {
	result = -1;
	if (activeRandomNumber&&range != 0&&!collectionbreak)
		result = (rand() % range) + minimumValue;
	else if (activeRandomNumber&&range != 0 && collectionbreak) {
		bool what=false;
		do {
			result = (rand() % range) + minimumValue;
			for (auto x : Vbreak) {
				if (x == result) {
					what = true;
					break;
				}
				else { what = false; break; }
			}
		} while (what);
	}
	else if (activeRandomNumber == false&&massage)
		std::cout << "Generator is not configured!\n";
	else if (range == 0&&massage)
		std::cout << "Generator range is not set!\n";
}
std::list<int> Generator::getgenerationCollection(unsigned int size) {
	generationCollection(size);
	return List;
}
void Generator::generationCollection(unsigned int size) {
	int result;
	std::list<int>::iterator it;
	if (frequence != 0 && frequence < 10000) {
		if (massage)
			std::cout << "Generation data...\n";
		List.clear(); //wyzerowac listy
		List.resize(size);
		it = List.begin();
		while (it!=List.end()) {
			generationNumber(result); //generowanie wartoci przez generator
			if (result == -1) return;
			*it = result; //dodanie wyniku do listy wygenerowanych wartosci
			it++;
			_sleep(frequence); //opuznienie czasowe wyrazone w [ms]
		}
		//system("cls");
	}
	else if (frequence == 0 && massage)
		std::cout << "Generation frequency is not set!\n";
	else if (frequence > 10000 && massage)
		std::cout << "Too much frequency!\n";
}
void Generator::viewCollection() {
	int i = 1;
	if (List.size() > 0) {
		for (auto x : List) {
			std::cout << i++ << ":\t" << x << "\n";
		}
		return;
	}
	else if(massage)
		std::cout << "The list is empty\n";
}
std::list<int> Generator::getList() {
	return List;
}
void  Generator::generationNumberRange(double& result) {
	result = -1.0;
	if (activeRandomNumber&& generationProbabilistic) {
		result = getStart() + (getStop() - getStart())*( rand() / double(RAND_MAX));
	}
	else if (!generationProbabilistic)
		std::cout << "Generator is not configured probabilistic!\n";
	else if (activeRandomNumber == false && massage)
		std::cout << "Generator is not configured!\n";
	else if (range == 0 && massage)
		std::cout << "Generator range is not set!\n";
}
Generator::~Generator() {}