#include "Segment.h"
void _SegmentF::config() {
	clear();
}
_SegmentF::_SegmentF() {
	config();
}
_SegmentF::~_SegmentF() {}
float& _SegmentF::getChAfter(int i, int iterator) {
	if (iterator >= 0 && iterator < maxIterator) {
		switch (i) {
		case 0:
			return ch0After[iterator];
		case 1:
			return ch1After[iterator];
		case 2:
			return ch2After[iterator];
		default:							break;
		}
	}
	return ch0After[maxIterator-1];
}
float& _SegmentF::getChBefore(int i, int iterator) {
	if (iterator >= 0 && iterator < maxIterator) {
		switch (i) {
		case 0:
			return ch0Before[iterator];
		case 1:
			return ch1Before[iterator];
		case 2:
			return ch2Before[iterator];
		default:							break;
		}
	}
	return ch0After[maxIterator - 1];
}
int& _SegmentF::getChDigital(int i, int iterator) {
	if (iterator >= 0 && iterator < maxIterator) {
		switch (i) {
		case 0:
			return ch0digital[iterator];
		case 1:
			return ch1digital[iterator];
		case 2:
			return ch2digital[iterator];
		default:							break;
		}
	}
	return ch0digital[maxIterator-1];
}
void _SegmentF::loadData(std::istream& file) {
	std::string temp;
	std::getline(file, temp);
	if (temp == "") {
		//std::cout <<"iterator: "<< iterator << "\n";
		switch (program) {
		case ch0:	program = Program::ch1; iterator = 0; return;
		case ch1:	program = Program::ch2; iterator = 0; return;
		case ch2:	program = Program::digital; iterator = 0; return;
		case digital: program = Program::ch0; iterator = 0; full = true; return;
		}
	}
	else {
		std::string date;
		std::string valueAfter;
		std::string valueBefore;
		std::size_t ptr;
		date = temp;
		cutValue(date, valueAfter, valueBefore, ptr);
		switch (program) {
		case ch0:
			timer0[iterator] = atoi(date.c_str());
			ch0After[iterator] = (float)atof(valueAfter.c_str());
			ch0Before[iterator] = (float)atof(valueBefore.c_str());
			itrCh0++;
			break;
		case ch1:
			timer1[iterator] = atoi(date.c_str());
			ch1After[iterator] = (float)atof(valueAfter.c_str());
			ch1Before[iterator] = (float)atof(valueBefore.c_str());
			itrCh1++;
			break;
		case ch2:
			timer2[iterator] = atoi(date.c_str());
			ch2After[iterator] = (float)atof(valueAfter.c_str());
			ch2Before[iterator] = (float)atof(valueBefore.c_str());
			itrCh2++;
			break;
		case digital:
			ch0digital[iterator] = atoi(date.c_str());
			ch1digital[iterator] = (int)atof(valueAfter.c_str());
			ch2digital[iterator] = (int)atof(valueBefore.c_str());
			itrDigital++;
			break;
		}
		iterator++;
	}
}
bool& _SegmentF::isFull() {
	return full;
}
void _SegmentF::reset() {
	config();
}
int& _SegmentF::getIterator() {
	return iterator;
}
void _SegmentF::cutValue(std::string& data, std::string& valueAfter, std::string& valueBefore, std::size_t& ptr) {
	std::string temp;
	ptr = data.find('\t');
	temp = data.substr(0, ptr);
	data.replace(0, ptr+1, "");
	ptr = data.find('\t');
	valueBefore = data.substr(0, ptr);
	valueAfter=data.replace(0, ptr+1, "");
	data = temp;
}
void _SegmentF::clear() {
	iterator = 0;
	itrCh0 = 0;
	itrCh1 = 0;
	itrCh2 = 0;
	itrDigital = 0;
	full = false;
	eof = false;
	program = Program::ch0;
	for (int i = 0; i < maxIterator; i++) {
		ch0After[i] = 0.0;
		ch0Before[i] = 0.0;
		ch0digital[i] = 0;
		ch1After[i] = 0.0;
		ch1Before[i] = 0.0;
		ch1digital[i] = 0;
		ch2After[i] = 0.0;
		ch2Before[i] = 0.0;
		ch2digital[i] = 0;
		timer0[i] = 0;
		timer1[i] = 0;
		timer2[i] = 0;
	}
}
/*
bool& _SegmentF::isEof() {
	return eof;
}*/