#pragma once
#include <vector>
#include <map>
#include "Chart.h"
class MangerChart
{
	std::vector<std::vector<double>> V_manager;
	std::map<int, std::string> m_organizer;
	std::vector<std::vector<std::string>> v_Type;
public:
	MangerChart();
	void setValueChart(Chart* x);
	void analization();
	void setDataChart(std::vector<Chart>* V);
	~MangerChart();
};

