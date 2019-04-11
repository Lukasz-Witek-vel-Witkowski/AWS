//**********************************************************************************************************//
// Data utworzenia: 10-04-2019									  		Autor: Lukasz Witek vel Witkowski	//
// Opis: "Klasa Focus spelniajaca funkcje klasy pomocniczej, przechowuj¹cej dane o plikach"					//
//**********************************************************************************************************//
#pragma once
#ifndef FOCUS_HPP
#define FOCUS_HPP
#include <string>
class Focus
{
	std::string nameFile; //zmienna przechowujaca nazwe pliku
	int segment; //zmienna przechowujaca wartosc sektorow w pliku
public:
	Focus(); //konstruktor
	Focus(const Focus& f); //kostruktor kopiujacy
	Focus& operator=(const Focus& f); //operator przypisania
	bool operator==(const Focus& f); //operator porownania
	void setName(std::string&  name); //metoda do wstawiania do klasy nazwy pliku
	std::string& getName(); //metoda zwracajaca nazwe pliku
	int& getSize(); //metoda zwaracajaca ilosc sektorow w pliku
	void setSize(int& value); //metoda sluzaca do wstawiania wartosci sektorow w pliku
	~Focus(); //destruktor
};
#endif // !FOCUS_HPP
