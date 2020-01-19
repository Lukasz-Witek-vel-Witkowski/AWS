#include "EngineMaximum.h"



EngineMaximum::EngineMaximum()
{
	system("cls");
	std::cout << "Ladowanie danych\n";
	manager.setConfig(config);
	fileResult = manager.getNameResultFile();
	b_program = manager.getProgramMethod();
	setLimit(manager.getLimit());
}


EngineMaximum::~EngineMaximum()
{
}
void EngineMaximum::run() {
	
	if (!b_program) {
		manager.runProcessing(); //wczytanie danych
		int size = manager.getSize();
		std::string temp = "del " + fileResult;
		system(temp.c_str());
		manager.maxWithFile();
	}
		system("cls");
		std::cout << "Tworzenie pliku result \n";
		manager.Finish(fileResult);
		std::cout << "Weryfikacja danych \n";
		manager.divisionIntoAttributes(fileResult);
		std::cout << "Koniec programu \n";
}
void EngineMaximum::setLimit(long limit) {
	Limit = limit;
}
