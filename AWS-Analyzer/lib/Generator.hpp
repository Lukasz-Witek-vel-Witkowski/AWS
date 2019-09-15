/********************************************************************************************************************************************************/
/*Date: 20.11.2018																									Author: Lukasz Witek vel Witkowski	*/
/*Name: Generator.hpp																																	*/
/*Description:A class to generate pseudo-random numbers																									*/	
/********************************************************************************************************************************************************/
#pragma once
#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#pragma warning(disable : 4996) //dopuszczenie do dzialania funkcji _sleep();
#include <iostream>
#include <vector>
#include "GeneratorBaze.h"
class Generator:public GeneratorBaze {
public:
	Generator(); //konstruktor bezparametrowy
	Generator(int Range, int Frequency); //konstruktor parametrowy (zakres generowania liczb, czestotliwosc generowania [1000/value])
	void configRandomNumbers(); //wlaczenie generowania liczb pseudolosowych
	void generationNumber(int& result); //generuje pojedyncza wartosc
	std::list<int> getgenerationCollection(unsigned int size); //po wygenerowaniu zbioru liczb zwraca std::vector<int> zaladowany wygenerowanymi danymi
	void generationCollection(unsigned int size);//generuje zbior wylosowanych danych
	void viewCollection(); //wyswietla zawartosc vectora
	std::list<int> getList();
	void generationNumberRange(double& result);
	void useBreakCollection();
	void setBreakParameter(int value);
	~Generator();
private:
	bool collectionbreak;
	std::vector<int> Vbreak;
};
#endif // !GENERATOR_HPP
