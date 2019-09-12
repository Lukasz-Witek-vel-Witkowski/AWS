//**********************************************************************************************************//
// Data utworzenia: 20-03-2019									  		Autor: Lukasz Witek vel Witkowski	//
// Opis: "Klasa Manager spelniajaca funkcje klasy sterujacej glownym algorytmem poprzez zarzadzanie			//
//		  plikami do przetworzenia. "																		//
//**********************************************************************************************************//
#pragma once
#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <string>
#include <vector>
#include <iostream>
#include "MangerChart.h"
constexpr auto fileList = "fileList.ini";
constexpr auto fileFocus = "fileFocus.ini";
#pragma warning(disable : 4996) // aby nie wywalal bedu zwiazanego ze stosowaniem satrego sposobu programowania
#include <fstream>
#include "Chart.h"
#include "ManagerName.h"
class Manager {
public:
	Manager(); //konstruktor bezparametrowy
	Manager(std::string data);	//konstruktor parametrowy
	void setNameFolder(std::string name, std::string nametwo);	//metoda sluzaca do ustawiania zmiennej NameFolder
	int sizeProduction();	// metoda zwraca ilosc plikow do obsluzenia 
	void countSegments(int value);
	int size();	// metoda zwraca ilosc wszystkich plikow w zbiorze
	void fileSearch(bool what, int module); // metoda sluzy do utworzenia listy plkow na podstawie 
	std::string& nextFile(); //metoda zwracajaca kolejna nazwe pliku ze zbioru
	void resetIterator(); //metoda slurzaca do zerowania iteratora 
	void setVector(std::vector<std::string>& v);
	//void loadFileIn(); //metoda slurzaca do czytania plikow opisujacych zlozone pliki 
	void onAlternative(); //metoda slurzaca do przelaczenia trybu pracy metody fileSearch() na tryb plikow o rozszerzeniu8 .bin
	void offAlternative(); //metoda slurzaca do przelaczenia trybu pracy metody fileSearch() na tryb plikow o rozszerzeniu8 .txt
	void saveData();
	void loadData();
	void setNameFileData(std::string data);
	void nsetNameFile(std::string name);
	std::string nfindName(std::string data);
	void nloadData();
	void run();
	void analization();
	~Manager(); //destruktor
private:
	std::vector<std::string> vFile; //zmienna vectoru spelniajaca role zbioru plikow do przetworzenia
	std::vector<Chart> vChart;
	std::string nameFolderOne; //zmienna przechowujaca dane o folderze
	std::string nameFolderSecend; //zmienna przechowujaca dane o folderze
	std::string data; //zmienna pomocnicza
	std::string path; //zmienna przechowujaca dane o scieszce
	std::string nameFileData;
	bool active; //zmienna sterujaca praca niekturych metod
	bool alterbative; //zmienna sterujaca praca niekturych metod
	int iterator; //zmienna spelniajca role iterowania zbioru plikow
	ManagerName managerName;
	MangerChart managerChart;
};
#endif // !MANAGER_HPP
