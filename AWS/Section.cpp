#include "Section.h"



Section::Section()
{
}

void Section::addRecord(Record& r) {
	vRecord.push_back(r);
}
void Section::performance() {
	for (auto& x : vRecord) {
		vResultPerformance.push_back(x.performance());
	}
}
std::vector<std::string>& Section::getVectorResultPerformance() {
	return vResultPerformance;
}
void Section::clear() {
	for (auto x : vRecord) {
		x.~Record();
	}
	vRecord.clear();
}
int Section::size() {
	return vRecord.size();
}
Section::~Section()
{
}
