//**********************************************************************************************************//
// Data utworzenia: 16-03-2019									  		Autor: Lukasz Witek vel Witkowski	//
// Opis: "Klasa Engine spelniajaca funkcje klasy nadrzednej calego projektu. W niej zachodza procesy		//
//		  wykonywane na klasach podrzednych, w celu realizacji zadan programu. "							//
//**********************************************************************************************************//

#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
constexpr auto config = "file.cnf";
#include "Manager.h"
#include "File.h"
class Engine
{
public:
	Engine(); //konstruktor bezparametrowy
	void loadFileConfig(); //metoda wczytujaca dane z pliku konfiguracyjnego
	void run(); //metoda realizujaca glowny algorytm programu
	void saveDataChanel(); //metoda wydzielajaca z plikow binarnych poszczegolne dane i zapisujaca w osobnych plikach
	~Engine(); //destruktor
private:
	Manager manager; //zmienna manager odpowiadajaca za automatyzacje procesu realizacji glownego algorytmu
	bool canal; //zmienna canal odpowiadajaca za tryb pracy glownego algorytmu (false = z plikow wejsciowych ".txt"
				//zapisuje struktury na pliki ".bin", a nastepnie z tych plikow wyodrebnia poszczegolen dane struktury
				//do osobnych plikow ".txt") (true - z plikow ".bin" wyodrebnia poszczegolen dane ze struktury do 
				//osbnych plikow ".txt")
	bool digital;
	short iteratorLoadFile; //zmeinna pomocnicza do iterowania poszczegolnych plikow podaczas realizacji glownego algorytmu 
	//File filePointer; // zmienna typu File odpowiadajaca za wykonywanie operacji na plikach
	File focus;
	std::string nameFolder; //zmienna przechowujaca dane o folderze roboczym
	std::string outputFolder; //zmienna przechowujaca dane o folderze output
	std::string outPutFiles; //zmienna przechowujaca dane o folderze result
};
#endif // !ENGINE_HPP



