#include "Filtr.h"
#pragma warning(disable : 4996)


Filtr::Filtr(Canal* V_pos)
{
	V_base = V_pos;
	number = 0;
}
std::vector<MaxValue> Filtr::filtration() {
	//V_area.clear();
	int iterator;
	int start = 0;
	bool active = false;
	findingNoise(); //liczenie szumow
	if (type) { //znajdywanie maksimum
		P_makismum.setValue(0, 0.0);
		for (auto& x : V_base->getVector()) {
				if (P_makismum < x) {
					iterator = 0;
					P_makismum = x;
					active = false;
				}
				else {
					if (P_makismum.getValue() > 50 * Noise) {
						if (x.getValue() < P_makismum.getValue()*(1.0 - (long double)((90 * 1.0) / 100.0)) && iterator > parametr_graniczny + P_makismum.getIterator()) {
							//if(x.getValue() <= 10 * Noise){
							if (x.getValue() >= 2 * Noise) {
								MaxValue V_temp;
								number++;
								pValueMax = P_makismum;
								pValueMin.setValue(P_makismum.getIterator(), P_makismum.getValue()*(1.0 - (long double)((precent*1.0) / 100.0))); //stworzenei przedzialu filtru
								for (auto& y : V_base->getVector()) {
									if (y <= pValueMax && y > pValueMin&&y.getIterator() >= start) {
										V_temp.setValue(y);
										V_temp.setMax(P_makismum);	//tworzenie obszaru dzialania filtru
									}
									if (x.getIterator() <= y.getIterator() && !active) {
										start = y.getIterator();
										V_area.push_back(V_temp);
										P_makismum.setValue(0, 0.0);
										active = true;
										break;
									}
								}
							}
						}
					}
					iterator++;
				}
		}
	}
	else { //znajdywanie minimum
		P_makismum.setValue(0, 0.0);
		for (auto& x : V_base->getVector()) {
			if (P_makismum > x) {
				P_makismum = x;
			}
		}
		pValueMin = P_makismum;
		pValueMax.setValue(P_makismum.getIterator(), (P_makismum.getValue()* (1.0+ (long double)((precent*1.0) / 100.0)))); //stworzenei przedzialu filtru
		for (auto& x : V_base->getVector()) {
			if (x < pValueMax&&x > pValueMin || x.getIterator() == P_makismum.getIterator()) {
			//	V_area[0].push_back(x);													 //tworzenie obszaru dzialania filtru
			}
		}
	}
	return V_area;
}
void Filtr::setPrecent(int p) {
	precent = p;
}
void Filtr::setType(bool b) {
	type = b;
}
int Filtr::getNumber() {
	return number;
}
void Filtr::findingNoise() {
	long double predecessor = 0.0;
	long double Value = 0.0;
	bool active = false;
	for (auto x : V_base->getVector()) {
		if (active) {
			if (x.getValue() >= 4 * predecessor) {
				Noise = Value / x.getIterator()*1.0;
				return;
			}
			else {
				Value += x.getValue();
			}
		}
		else {
			active = true;
			predecessor = x.getValue();
			Value += x.getValue();
		}
	}
}
Filtr::~Filtr()
{
}
