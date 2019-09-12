#include "MangerChart.h"



MangerChart::MangerChart()
{
	v_Type.resize(3);
}
void MangerChart::setValueChart(Chart* x) {
	int i;
	bool is;
	std::string temp;
	for (i = 1; i < 4; i++) {
		temp = x->getType(i);
		is = false;
		for (auto x : v_Type[i - 1]) {
			if (x == temp) is = true;
		}
		if (!is) {
			v_Type[i - 1].push_back(temp);
		}
	}
}
void MangerChart::analization() {
	int i = 0;
	for (auto X : v_Type) {
		for (auto Y : X) {
			m_organizer[i++] = Y;
		}
	}
}
void MangerChart::setDataChart(std::vector<Chart>* V) {
	for (auto x : *V) {
		//m_organizer. //dodanie danych do histogramow!
	}
}
MangerChart::~MangerChart()
{
}
