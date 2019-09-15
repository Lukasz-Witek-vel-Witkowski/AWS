#pragma once
#ifndef GENERATORSINGIEL_HPP
#define GENERATORSINGIEL_HPP
#include "GeneratorBaze.h"
#include <fstream>
#include <string>
#include <Vector>
void question(bool& what);
template <class T>
class GeneratorSingiel: public GeneratorBaze {
public:	
	GeneratorSingiel():GeneratorBaze() {
		range = 0;
		frequence = 0;
		activeCollection = false;
		activeRandomNumber = false;
		Good = true;
	} //konstruktor bezparametrowy
	GeneratorSingiel(std::string data, int Frequency):GeneratorBaze() {
		configRandomNumbers();
		setNameFile(data);
		activeCollectionSize();
		setFrequency(Frequency);
		activeCollection = false;
		Good = true;
	} //konstruktor parametrowy (zakres generowania liczb, czestotliwosc generowania [1000/value])
	GeneratorSingiel(T start, T stop, int Frequency) :GeneratorBaze() {
		configRandomNumbers();
		activeRandomNumber = false;
		autoGeneratorCollectionINT(start, stop);
		activeCollectionSize();
		setFrequency(Frequency);
		Good = true;
	}
	void activeCollectionSize() { //ustawienie na zakres losowan wielkosci kolekcji zadanej
		if (Collection.size() > 0) {
			range = Collection.size();
			generationList();
			activeCollection = true;
		}
		else {
			if (massage)
				std::cout << "Collection is empty!\n";
		}
	}
	void setNameFile(std::string data) {
		Filename = data;
		std::ifstream file;
		file.open(data.c_str());
		if (file.good()) {
			int size;
			int i;
			T temp;
			if (massage)
				std::cout << "Load file " << data;
			file >> size;
			for (i = 0; i < size; i++) {
				file >> temp;
				Collection.push_back(temp);
			}
			file.close();
			if (massage)
				std::cout << "Load file is sukcesfull!\n";
		}
	}
	void generationNumber(int& result) { //generuje pojedyncza wartosc
		result = -1;
		if (activeRandomNumber&&range != 0) {
			result = rand() % List.size();
		}
		else if (activeRandomNumber == false && massage)
			std::cout << "Generator is not configured!\n";
		else if (range == 0 && massage)
			std::cout << "Generator range is not set!\n";
	}
	std::list<int> getgenerationCollection(unsigned int size) { std::cout<<"The method is blocked!\n"; std::list<int> temp; return temp;}
	std::list<T> getgenerationCollection(unsigned int& size) {//po wygenerowaniu zbioru liczb zwraca std::vector<int> zaladowany wygenerowanymi danymi
		generationCollection(size);
		return Result;
	}
	void autoGeneratorCollectionINT(T start, T stop) {
		int i;
		for (i = start; i < stop; i++) {
			Collection.push_back(i);
		}
		range = Collection.size();
		activeRandomNumber = true;
	}
	void setConntent(T data) {
		Result.push_back(data);
	}
	void generationCollection(unsigned int size) {//generuje zbior wylosowanych danych
		int result;
		if (activeCollection) {
			if (size > List.size()) {
				Good = false; return;
			}
			while (size > Result.size()) {
				generationNumber(result);
				Result.push_back(Collection[*List.begin() + result]);
				List.remove(result);
			}
		}
		else {
			bool what = false;
			if (range != Collection.size()) {
				std::cout << "Range is not positive!\n"
					<< "Set Range on Collection Size?";
					question(what);
				if (what) {
					activeCollectionSize();
				}
				else {
					try {
						while (size > Result.size()) {
							generationList();
							generationNumber(result);
							Result.push_back(Collection[*List.begin() + result]);
							List.remove(result);
						}
					}
					catch (...) {
						std::cout << "Error!\n"; 
						Result.clear();
						return;
					}
				}
			}
			while (size > Result.size()) {
				generationNumber(result);
				Result.push_back(Collection[*List.begin() + result]);
				List.remove(result);
			}
		}
	}
	bool good() {
		return Good;
	}
	void generationNumberRange(double& result) {
		result = -1;
		if (activeRandomNumber&& generationProbabilistic) {
			result = (getStart() + (getStop() - getStart()))* (rand() / double(RAND_MAX));
		}
		else if (!generationProbabilistic)
			std::cout << "Generator is not configured probabilistic!\n";
		else if (activeRandomNumber == false && massage)
			std::cout << "Generator is not configured!\n";
		else if (range == 0 && massage)
			std::cout << "Generator range is not set!\n";
	}
	void viewCollection() {
		int size = 1;
		for (auto x : Result) {
			std::cout << size++ <<"\t"<< x << "\n";
		}
	}
	void viewCollectionBaze() {
		int size = 1;
		for (auto x : Collection) {
			std::cout << size++ << x << "\n";
		}
	}//wyswietla zawartosc vectora
	std::list<T> getList() {
		return Result;
	}
	~GeneratorSingiel() {}
private:
	std::vector<T> Collection;
	std::list<T> Result;
	bool activeCollection;
	bool Good;
	std::string Filename;
	void generationList() {
		int i;
		for (i = 0; i < (int)range; i++) {
			List.push_back(i);
		}
	}
};
void question(bool& what) {
	char c;
	char contine = false;
	do {
		if (!contine)
			std::cout << "Chcez kontynulowac? Y/N\n";
		else
			std::cout << "Podano zla wartosc!\n Kontynulowac? Y/N\n";
		std::cin >> c;
		switch (c) {
		case 'y':
		case 'Y':
			contine = false;
			break;
		case 'n':
		case 'N':
			contine = false;
			what = false;
			break;
		default:
			contine = true;
			break;
		}
	} while (contine);
}
#endif // !GENERATORSINGIEL_HPP
