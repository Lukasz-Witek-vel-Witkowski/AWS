#pragma once
#ifndef GENERATORBAZE_HPP
#define GENERATORBAZE_HPP
#include <list>
#include <time.h>
#include "Statistics.hpp"
class GeneratorBaze: public Statistics {
public:
	GeneratorBaze();
	~GeneratorBaze();
	void setRange(int value); //ustawienie zakresu losowan
	void setMinimumValue(int value); //ustawienie minimalnej wartosci losowania!
	void massageDisplay(bool value); //ustawienie wyswietlania komunikatow defoltowo na true
	void configRandomNumbers(); //wlaczenie generowania liczb pseudolosowych
	void setFrequency(int value); //ustaweinie czestotliwosci [1000/value] 
	virtual void generationNumber(int& result)=0; //generuje pojedyncza wartosc
	virtual std::list<int> getgenerationCollection(unsigned int size)=0; //po wygenerowaniu zbioru liczb zwraca std::vector<int> zaladowany wygenerowanymi danymi
	void configProbabilistic(double start, double end, int Frequency);
	virtual void generationCollection(unsigned int size)=0;//generuje zbior wylosowanych danych
	virtual void viewCollection()=0; //wyswietla zawartosc vectora
	unsigned int getRange(); //zwarac ustawiona wartosc zakresu losowania
	unsigned int getFrequence(); //zwraca ustawiona wartosc przerwy miedzylosowaniami wyrazona w milisekundach
protected:
	bool activeRandomNumber; //zarzadza aktywacja generatora liczb pseldo-losowych
	double getStart();
	double getStop();
	bool massage; //zarzadza aktywacja powiadomien konsolowych
	unsigned int range; //zakres generatora
	int minimumValue;
	double *Double;
	bool doubleActive;
	bool generationProbabilistic;
	unsigned int frequence; //czestotliowsc losowan [1000/frequence]  wyrazona w milisekundach
	std::list<int> List; //lista na welosowane dane
};
#endif // !GENERATORBAZE_HPP
