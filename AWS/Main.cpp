#include "Engine.h"

#include <cmath>
#include <fstream>
//#include <dirent.h>
using namespace std;
void CountSegments();


int main() 
{
	CountSegments();


	Engine e;
	e.run();

	system("pause");
	return 0;
}


void CountSegments()
{
	int seg = 0;
	int separator = -2; // bo na koñcu pliku s¹ 3 puste linie
	int control = 4;
	long long rows = 0;
	long long p = 0;  // wczytywanie nazw plików - kontorla pliku z danymi
	
	string src = "C:\\Dane\\Studia\\Projekt grupowy\\AWS-master\\test\\";  //œcie¿ka do katalogu
	
	ofstream plik1("struktura.txt");  // lista plików z jedn¹ struktur¹
	ofstream plik2("struktury.txt");  // lista plików z kilkoma strukturami
	ofstream plik3("uszkodzone.txt");  // lista plików z kilkoma strukturami


	fstream plik_spr;  // sprawdzany plik
	fstream pliki;  // lista plików
	string line;

	//
	string nameFolder;
	string nameFile;
	string comend;


	pliki.open(fileList);

	if (pliki.good()) 
	{
		do
		{
			if (p == 0)
			{
				getline(pliki, nameFile);
				//comend = src +" cd.";
				//system(nameFile.c_str());
				cout << "Folder nazwa: " << nameFile << endl << endl;
			}
			else
			{
				getline(pliki, nameFile);
				comend = src + nameFile;
				//system(comend.c_str());
				cout << "Plik nazwa: " << comend << endl << endl;


				//plik_spr.open("C:\\Dane\\Studia\\Projekt grupowy\\AWS-master\\test\\66_70_1E7_500_11_i-0bcdcf03cc4b68169_r1_MER.txt");
				//plik_spr.open("C:\\Dane\\Studia\\Projekt grupowy\\AWS-master\\test\\66_75_3E7_1000_12_i-0b91cc3a375659fdc_r1_MER.txt");
				//plik_spr.open("C:\\Dane\\Studia\\Projekt grupowy\\AWS-master\\test\\66_75_3E9_2500_1_i-038bc89930887720c_r1_MER.txt");
				//plik_spr.open("C:\\Dane\\Studia\\Projekt grupowy\\AWS-master\\test\\fake.txt");  // plik z którego usune³am 1 kana³!!! dla testu


				seg = 0;
				separator = -2; // bo na koñcu pliku s¹ 3 puste linie
				control = 4;


				plik_spr.open(comend);
				if (plik_spr.good() == true)
				{

					do
					{
						//cout << "Licze!!! " << endl;
						getline(plik_spr, line);
						rows++;

						if (line == "")
						{
							separator++;
							control--;
							if (control == 0)
							{
								seg++;
								control = 4;
							}
						}

						//cout << "Separator " << separator << endl << endl;
					} while (!plik_spr.eof());

					cout << "Wierszy: " << rows << endl;
					cout << "Separatorow: " << separator << endl;
					cout << "Segmentow: " << seg << endl;
					double spr = separator / 4.0;
					cout << "Kontrola poprawnosci struktury: " << (double)spr << endl << endl;


					// przypisanie do odpowiedniej listy (wpisanie do pliku)
					if (fmod(spr, 1) == 0)
					{
						if (seg > 1)
						{
							plik2 << nameFile <<endl;
						}
						else if (seg == 1)
						{
							plik1 << nameFile << endl;
						}
					}
					else
					{
						plik3 << nameFile << endl;
					}

					plik_spr.close();

				}
			}
			p++;
		} while (!pliki.eof());
	}


	

	plik1.close();
	plik2.close();
	plik3.close();

	pliki.close();
}


