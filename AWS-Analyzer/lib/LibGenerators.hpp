#pragma once
#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include "Generator.hpp"
#include "GeneratorSingiel.hpp"
#include "Diagram.hpp"
void parameters(Generator& G);
void question(bool& what, bool& contine);
template <class T>
void parameters(GeneratorSingiel<T>& G);
template <class T>
void parameters(std::list<T>& G);
void question(bool& what, bool& contine) {
	std::string c;
	do {
		if (!contine)
			std::cout << "Do you want to continue? (Y/N)\n";
		else
			std::cout << "The wrong value was given!\n continue ? (Y/N)\n";
		std::cin >> c;
		switch (c[0]) {
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
template <class T>
void parameters(GeneratorSingiel<T>& G) {
	T min = NULL;
	T max = NULL;
	double average = NULL;
	T median = NULL;
	double standart = NULL;
	T aplitude = NULL;
	G.getParameters(min, max, average, median, aplitude, standart, G.getList());
	std::cout << "Minimum value of the set: " << min << "\n"; //minimalna wartosc
	std::cout << "maximum value of the set: " << max << "\n"; //makszmalna wartosc
	std::cout << "The average value of the set : " << average << "\n"; //sednia
	std::cout << "Median: " << median << "\n"; //mediana
	std::cout << "Amplitude: " << aplitude << "\n"; //aplituda
	std::cout << "Standard deviation: " << standart << "\n"; //odchzlenie standartowe
}
template <class T>
void parameters(std::list<T>& G) {
	GeneratorSingiel<T> g;
	for(auto x: G)
	g.setConntent(x);
	parameters(g);
}
void parameters(Generator& G) {
	double min = NULL;
	double max = NULL;
	double average = NULL;
	double median = NULL;
	double standart = NULL;
	double aplitude = NULL;
	G.getParameters(min, max, average, median, aplitude, standart, G.getList());
	std::cout << "Minimum value of the set: " << min << "\n"; //minimalna wartosc
	std::cout << "maximum value of the set: " << max << "\n"; //makszmalna wartosc
	std::cout << "The average value of the set : " << average << "\n"; //sednia
	std::cout << "Median: " << median << "\n"; //mediana
	std::cout << "Amplitude: " << aplitude << "\n"; //aplituda
	std::cout << "Standard deviation: " << standart << "\n"; //odchzlenie standartowe
}
#endif // !FUNCTION_HPP
