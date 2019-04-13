//**********************************************************************************************************//
// Data utworzenia: 20-03-2019									  		Autor: Lukasz Witek vel Witkowski	//
// Opis: "Klasa File odpowiadajaca za oblugiwanie procesów odczytu i zapisu danych z pliku do struktury		//
//		  i odwrotnie. "																					//
//**********************************************************************************************************//
#pragma once
#ifndef FILE_HPP
#define FILLE_HPP
#include "Segment.h"
#include "Focus.h"
#pragma warning(disable : 4996) // aby nie wywalal bedu zwiazanego ze stosowaniem satrego sposobu programowania
#include <vector>
class File
{
	std::string fileIN; //nazwa pliku wejsciowego
	std::vector<_SegmentF> V_Segment; //vector na segmenty w plikach
	std::vector<std::string> vNameFileBinary; //vector na nazwy plikow
	long iterator; //iterator
	std::string path; //zmienna przechowujaca nawe scierzki
	std::string outPutFiles; //zmienna przechowujaca nazwe folderu typu output
	std::string outputFolder; //zmienna przechowujaca nazwe folderu typu result
	std::string nameFile; //zmienna pomocnicza
public:
	File(); //konstruktor
	void loadFile(); //metoda slurzaca do odczytu danych z pliku wejsciowego o rozszerzeniu ".txt"
	void saveFile(); //metoda slurzaca do zapisu danych do pliku ".bin"
	std::vector<std::string>& getVector(); //metoda zwraca referencje do vectora
	void setOutPutFolder(std::string name); //metoda umozliwiajaca ustaweienie nazwy folderu typu output
	void setOutPutFiles(std::string name); //metoda umozliwiajaca ustawienie nazwy folderu typu result
	void setPath(std::string path); //medoa slurzaca do ustwaienia scierzki
	void setFocus(Focus& f); //metoda slurzy do pobierania focusa
	void setFileIn(std::string name); //metoda sluzrzy do wstawiania nazwy pliku
	void SetOutPutFileCanal(std::string NameFile, bool digital); // metoda odpowiedzialna za wyciaganie danych z pliku ".bin"
												   //i zapisywaniu ich w odzielnych plikach ".txt"
	~File(); //destruktor
};
#endif // !FILE_HPP
