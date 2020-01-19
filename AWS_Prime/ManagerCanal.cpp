#include "ManagerCanal.h"



ManagerCanal::ManagerCanal()
{
	
}
void ManagerCanal::setMax(std::vector<MaxValue> m, ManagerCanal::Value c) {
	int i = 0;
	std::cout << "wywolanie metody << " << c << "\n";
	switch (c)
	{
	case ManagerCanal::C_Orgin:
		std::cout << "Parametr C_Orgin\n";
		V_max.push_back(m);
		break;
	case ManagerCanal::C_2_80:
		std::cout << "Parametr C_2_80\n";
		V_max.push_back(m);
		break;
	case ManagerCanal::C_6_60:
		std::cout << "Parametr C_6_60\n";
		V_max.push_back(m);
		break;
	default:
		break;
	}
}
void ManagerCanal::veryfication() {
	if (V_max[1].size() > 0 && V_max[2].size() > 0 && V_max[0].size() > 0) {
		long long value;
		long long iterator = 0;
		long long iterator_base = 0;
		long long iter = 0;
		std::vector<MaxValue> V_temp;
		MaxValue temp;
		if (V_max[1].size() != V_max[2].size()) {
			for (auto x : V_max[1]) {
				value = x.getMax().getIterator();
				for (std::vector<MaxValue>::iterator it = V_max[2].begin(); it < V_max[2].end(); it++) {
					if (it->getMax().getIterator() < value) {
						temp = *it;
						//continue;
					}
					else {
						V_temp.push_back(temp); break;
					}
					iterator++;
				}
				iterator_base++;
			}
			if (V_temp.size() == V_max[1].size()) {
				V_max[2] = V_temp;
			}
		}
		V_temp.clear();
		iter = 0;
		iterator_base = 0;
		iterator = 0;
		if (V_max[1].size() != V_max[0].size()) {
			for (auto x : V_max[1]) {
				value = x.getMax().getIterator();
				for (std::vector<MaxValue>::iterator it = V_max[0].begin(); it < V_max[0].end(); it++) {
					if (it->getMax().getIterator() < value) {
						temp = *it;
					}
					else {
						V_temp.push_back(temp);
					}
					iterator++;
				}
				iterator_base++;
			}
			if (V_temp.size() == V_max[1].size()) {
			}
		}
	}
}
void ManagerCanal::position() {
	if(V_max.size()==3&&V_max[0].size()>0&&V_max[1].size()>0&&V_max[2].size()>0){
		Position* one;
		Position* two;
		Position* zeero;
		Position* main_1;
		Position* main_2;
		Position* temp;
		int position_0 = -1;
		int position_1 = -1;
		int position_2 = -1;
		while (V_max[0].size() != V_max[1].size() || V_max[0].size() != V_max[2].size()) {
			position_0++;
			position_1++;
			position_2++;
			if (position_1 + 1 < V_max[1].size() && position_0+1 < V_max[0].size() && position_2+1 < V_max[2].size()) {
				if (V_max[1].size() < V_max[2].size() && V_max[0].size() < V_max[2].size()) {	//
					if (position_2 + 1 < V_max[2].size() && position_1 < V_max[1].size() && position_0 < V_max[0].size()) {
						main_1 = &(V_max[2][position_2].getMax());
						main_2 = &(V_max[2][position_2 + 1].getMax());
						one = &(V_max[1][position_1].getMax());
						two = &(V_max[0][position_0].getMax());
						if (main_1->getIterator() < one->getIterator() && main_2->getIterator() < one->getIterator() && main_1->getIterator() < two->getIterator() && main_2->getIterator() < two->getIterator()) { // spelnione
							V_max[0].erase(V_max[2].begin());
							continue;
						}
						else {
							position_2 = (int)V_max[2].size() - 2;
							position_1 = (int)V_max[1].size() - 1;
							position_0 = (int)V_max[0].size() - 1;
							main_1 = &(V_max[2][position_2].getMax());
							main_2 = &(V_max[2][position_2 + 1].getMax());
							one = &(V_max[1][position_1].getMax());
							two = &(V_max[0][position_0].getMax());
							if (main_1->getIterator() > two->getIterator() && main_2->getIterator() > two->getIterator() && main_1->getIterator() > one->getIterator() && main_2->getIterator() > one->getIterator()) {
								V_max[2].erase(V_max[2].begin() + position_2 + 1);
								V_max[2].erase(V_max[2].begin() + position_2);
								continue;
							}
							else if (main_1->getIterator() > one->getIterator() && main_1->getIterator() > two->getIterator()) {
								std::cout << "BLAD krytyczny!\n";
							}
							else if (main_2->getIterator() > one->getIterator() && main_2->getIterator() > two->getIterator()) {
								V_max[2].erase(V_max[2].begin() + position_2 + 1);
								continue;
							}
						}
					}
				}
				else if (V_max[0].size() < V_max[1].size() && V_max[2].size() < V_max[1].size())
				{
					if (position_1 + 1 < V_max[1].size() && position_0 < V_max[0].size() && position_2 < V_max[2].size()) {
						main_1 = &(V_max[1][position_1].getMax());
						main_2 = &(V_max[1][position_1 + 1].getMax());
						one = &(V_max[0][position_0].getMax());
						two = &(V_max[2][position_2].getMax());
						if (main_1->getIterator() < one->getIterator() && main_2->getIterator() < one->getIterator() && main_1->getIterator() < two->getIterator() && main_2->getIterator() < two->getIterator()) { // spelnione
							V_max[0].erase(V_max[1].begin());
							continue;
						}
						else {
							position_1 = (int)V_max[1].size() - 2;
							position_2 = (int)V_max[1].size() - 1;
							position_0 = (int)V_max[2].size() - 1;
							if (position_0 > 0 && position_1 > 0 && position_2 > 0) {
								main_1 = &(V_max[1][position_1].getMax());
								main_2 = &(V_max[1][position_1 + 1].getMax());
								one = &(V_max[0][position_0].getMax());
								two = &(V_max[2][position_2].getMax());
								if (main_1->getIterator() > two->getIterator() && main_2->getIterator() > two->getIterator() && main_1->getIterator() > one->getIterator() && main_2->getIterator() > one->getIterator()) {
									V_max[1].erase(V_max[1].begin() + position_1 + 1);
									V_max[1].erase(V_max[1].begin() + position_1);
								}
								else if (main_1->getIterator() > one->getIterator() && main_1->getIterator() > two->getIterator()) {
									std::cout << "BLAD krytyczny!\n";
								}
								else if (main_2->getIterator() > one->getIterator() && main_2->getIterator() > two->getIterator()) {
									V_max[1].erase(V_max[1].begin() + position_1 + 1);
								}
							}
						}
					}
				}
				else if (V_max[1].size() < V_max[0].size() && V_max[2].size() < V_max[0].size()) {
					if (position_0 + 1 < V_max[0].size() && position_1 < V_max[1].size() && position_2 < V_max[2].size()) {
						main_1 = &(V_max[0][position_0].getMax());
						main_2 = &(V_max[0][position_0 + 1].getMax());
						one = &(V_max[1][position_1].getMax());
						two = &(V_max[2][position_2].getMax());
						if (main_1->getIterator() < one->getIterator() && main_2->getIterator() < one->getIterator() && main_1->getIterator() < two->getIterator() && main_2->getIterator() < two->getIterator()) { // spelnione
							V_max[0].erase(V_max[0].begin());
							continue;
						}
						else {
							position_0 = (int)V_max[0].size() - 2;
							position_1 = (int)V_max[1].size() - 1;
							position_2 = (int)V_max[2].size() - 1;
							if (position_0 > 0 && position_1 > 0 && position_2 > 0) {
								main_1 = &(V_max[0][position_0].getMax());
								main_2 = &(V_max[0][position_0 + 1].getMax());
								one = &(V_max[1][position_1].getMax());
								two = &(V_max[2][position_2].getMax());
								if (main_1->getIterator() > two->getIterator() && main_2->getIterator() > two->getIterator() && main_1->getIterator() > one->getIterator() && main_2->getIterator() > one->getIterator()) {
									V_max[0].erase(V_max[0].begin() + position_0 + 1);
									V_max[0].erase(V_max[0].begin() + position_0);
								}
								else if (main_1->getIterator() > one->getIterator() && main_1->getIterator() > two->getIterator()) {
									std::cout << "BLAD krytyczny!\n";
								}
								else if (main_2->getIterator() > one->getIterator() && main_2->getIterator() > two->getIterator()) {
									V_max[0].erase(V_max[0].begin() + position_0 + 1);
								}
								continue;
							}
						}
					}
				}
				else {
					if (V_max[0].size() < V_max[1].size() && V_max[0].size() < V_max[2].size() && V_max[1].size() == V_max[2].size()) {
						if (position_1 + 1 < V_max[1].size() && position_0 + 1 < V_max[0].size()) {
							zeero = &(V_max[0][position_0].getMax());
							temp = &(V_max[0][position_0 + 1].getMax());
							main_1 = &(V_max[1][position_1].getMax());
							main_2 = &(V_max[1][position_1 + 1].getMax());
							one = &(V_max[2][position_2].getMax());
							two = &(V_max[2][position_2 + 1].getMax());
							if (zeero->getIterator() < one->getIterator() && zeero->getIterator() < two->getIterator() && zeero->getIterator() < main_1->getIterator() && zeero->getIterator() < main_2->getIterator()) { // spelnione
								if (temp->getIterator() > one->getIterator() && temp->getIterator() > two->getIterator() && temp->getIterator() > main_1->getIterator() && temp->getIterator() > main_2->getIterator()) {
									V_max[1].erase(V_max[1].begin() + position_1 + 1);
									V_max[2].erase(V_max[2].begin() + position_2 + 1);
									continue;
								}
							}

						}
						else {
							return;
						}
					}

				}
			}
			else {
			return;
}
		}
	}
}
long double ManagerCanal::getcoefficient2_80(int value) {
	
		std::cout << "wartosc orginalu = " << V_max[0][value].getMax().getIterator() << " - " << V_max[0][value].getMax().getValue() << "\n";
		std::cout << "wartosc 2_80 = " << V_max[2][value].getMax().getIterator() << " - " << V_max[2][value].getMax().getValue() << "\n";
		std::cout << "wspolczynik = " << V_max[2][value].getMax().getValue() / V_max[0][value].getMax().getValue() << "\n";
		return V_max[2][value].getMax().getValue() / V_max[0][value].getMax().getValue();

}
long double ManagerCanal::getcoefficient6_60(int value) {

		std::cout << "wartosc orginalu = " << V_max[0][value].getMax().getIterator() << " - " << V_max[0][value].getMax().getValue() << "\n";
		std::cout << "wartosc 6_60 = " << V_max[1][value].getMax().getIterator() << " - " << V_max[1][value].getMax().getValue() << "\n";
		std::cout << "wspolczynik = " << V_max[1][value].getMax().getValue() / V_max[0][value].getMax().getValue()<<"\n";
		return V_max[1][value].getMax().getValue() / V_max[0][value].getMax().getValue();

}
int  ManagerCanal::getSize(int j) {
	if (V_max[1].size() < V_max[2].size() && V_max[1].size() < V_max[0].size()) {
		return (int)V_max[1].size();
	}
	else if (V_max[0].size() < V_max[1].size() && V_max[0].size() < V_max[2].size())
	{
		return (int)V_max[0].size();
	}
	return (int)V_max[2].size();

}
void ManagerCanal::cout() {
	/*if (V_max[1].size() < V_max[2].size()&& V_max[1].size() < V_max[0].size()) {
		std::cout << "SIZE ++ 1\n";
	}
	else if (V_max[0].size() < V_max[1].size() && V_max[0].size() < V_max[2].size())
	{
		std::cout << "SIZE ++ 0\n";
	}
	else
	{
		std::cout << "SIZE ++ 2\n";
	}*/
	for (int j = 0; j < V_max.size(); j++) {
		for (int k = 0; k < V_max[j].size(); k++) {
			std::cout << j << " MAX = " << V_max[j][k].getMax().getIterator() << " -- " << V_max[j][k].getMax().getValue() << "\n";
		}
	}
}
void ManagerCanal::reset() {
	V_max.clear();
}
ManagerCanal::~ManagerCanal()
{
}
