//**********************************************************************************************************//
// Data utworzenia: 20-03-2019									  		Autor: Lukasz Witek vel Witkowski	//
// Opis: "Klasa File odpowiadajaca za oblugiwanie procesów odczytu i zapisu danych z pliku do struktury		//
//		  i odwrotnie. "																					//
//**********************************************************************************************************//
#pragma once
#ifndef FILE_HPP
#define FILLE_HPP
#include "Segment.h"
#pragma warning(disable : 4996) // aby nie wywalal bedu zwiazanego ze stosowaniem satrego sposobu programowania
class File
{
public:
	File(); //konstruktor bezparametrowy
	void setNameFile(std::string& name); //metoda umozliwiajaca ustawienie nazwy pliku
	void setOutputFolder(std::string name); //metoda umozliwiajaca ustaweienie nazwy folderu typu output
	void setOutPutFiles(std::string name); //metoda umozliwiajaca ustawienie nazwy folderu typu result
	void setPath(std::string path); //medoa slurzaca do ustwaienia scierzki
	void loadFile(); //metoda slurzaca do odczytu danych z pliku wejsciowego o rozszerzeniu ".txt"
	_SegmentF& getTemp(); //metoda zwarcajaca referencje do zmiennej temp typu _SegmentF
	void saveFile(); //metoda slurzaca do zapisu danych do pliku ".bin"
	void SetOutPutFileCanal(std::string data); //metoda odpowiedzialna za wyciaganie danych z pliku ".bin" 
											   //i zapisywaniu ich w odzielnych plikach ".txt"
	void setIterator(int Canal); //metoda slurzaca do ustawienia wartosci iteratora struktury
	int getCanal(); //metoda zwracajaca aktualny kanal
	void clear(); //metoda czyszczaca zawartosc klasy zwi¹zana z nazwa pliku
	void segmentclear(); //metoda wywo³uje metode czysczaca na zmiennej temp
	~File(); //destruktor
private:
	_SegmentF temp; //zmienna odpowiadajaca za przechowywaie struktury calego pliku
	int canal; //zmienna przechowujaca informacje o kanale
	int iteratorSegments; //zmienna przechowujaca informacje o iteratorze struktury
	int iteratorChanel; //zmienna przechowujaca informacje o iteratorze kanalu 
	std::string nameFile; //zmienna przechowujaca nazwe pliku
	std::string path; //zmienna przechowujaca nawe scierzki
	std::string outPutFiles; //zmienna przechowujaca nazwe folderu typu output
	std::string outputFolder; //zmienna przechowujaca nazwe folderu typu result
};
std::istream& operator>>(std::istream& file, File& f); //przeciazony operator przesuniecia bitowego na wejscie danych 
#endif // !FILE_HPP



