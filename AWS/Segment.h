//**********************************************************************************************************//
// Data utworzenia: 16-03-2019									  		Autor: Lukasz Witek vel Witkowski	//
// Opis: "Struktura _SegmentF odpowiedzialna za bezposredne przechowywwanie danych z pliku"					//
//**********************************************************************************************************//
#pragma once
#ifndef SEGMENT_HPP
#define SEGMENT_HPP
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
enum Program { //zmienna typu enumerowanego odpowiedzialna za zdefiniowanie trybu pracy agorytmu wyciagajacego dane ze struktury
	ch0, //kanal 0
	ch1, //kanal 1
	ch2, //kanal 2
	digital //digital :)
};
constexpr auto maxIterator = 10240; //wartosc okreslajaca maksymalne wielkosci dancyh w pojedynczym kanale
struct _SegmentF
{
public:
	int itrCh0; //zmienna okreslajaca rozmiar kanalu 0
	int itrCh1; //zmienna okreslajaca rozmiar kanalu 1
	int itrCh2; //zmienna okreslajaca rozmiar kanalu 2
	int itrDigital; //zmienna okreslajaca rozmiar kanalu digital
private:
	long timer0[maxIterator]; //tablica przechowujaca dane o czasie dla kanalu 0
	long timer1[maxIterator]; //tablica przechowujaca dane o czasie dla kanalu 1
	long timer2[maxIterator]; //tablica przechowujaca dane o czasie dla kanalu 2
	float ch0After[maxIterator]; //tablica przechowujaca dane po buforze dla kanalu 0
	float ch0Before[maxIterator]; //tablica przechowujaca dane przed buforze dla kanalu 0
	float ch1After[maxIterator]; //tablica przechowujaca dane po buforze dla kanalu 1
	float ch1Before[maxIterator]; //tablica przechowujaca dane przed buforze dla kanalu 1
	float ch2After[maxIterator]; //tablica przechowujaca dane po buforze dla kanalu 2
	float ch2Before[maxIterator]; //tablica przechowujaca dane przed buforze dla kanalu 2
	int ch0digital[maxIterator]; //tablica przechowujaca dane digital dla kanalu 0
	int ch1digital[maxIterator]; //tablica przechowujaca dane digital dla kanalu 1
	int ch2digital[maxIterator]; //tablica przechowujaca dane digital dla kanalu 2
	Program program; //zmienna programu
	bool full; //zmienna okreslajaca czy struktura zostala calkowicie zapelniona
	bool eof; //zmienna konca pliku
	int iterator; //zmienna pelniaca fukcje iteroujaca 
	void config(); //metoda konfugurujaca defoltowe ustawienia struktury
public:
	_SegmentF(); //konstruktor bez parametrowy
	void loadData(std::istream& file); //metoda wczytujaca dane z pliku wejsciowego ".txt"
	void clear(); //metoda czyszczaca zawartosc struktury
	bool& isFull(); //metoda zwracajaca referencje zmiennej full 
	float& getChAfter(int i, int iterator);
	float& getChBefore(int i, int iterator);
	int& getChDigital(int i, int iterator);
	//bool& isEof();
	void cutValue(std::string& data, std::string& valueAfter, std::string& valueBefore, std::size_t& ptr); //metoda wyodrebnajaca odczytana linie z pliku na poszczegolne wartosci typu std::string
	void reset(); //metoda przywracajaca strukture do ustwaien poczatkowych
	int& getIterator();
	~_SegmentF(); //destruktor
};
#endif // !SEGMENT_HPP
