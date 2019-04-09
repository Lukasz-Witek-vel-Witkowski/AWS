#include "Segment.h"
void _SegmentF::config() {
	clear();
}
_SegmentF::_SegmentF() {
	config();
}
_SegmentF::~_SegmentF() {}
void _SegmentF::setTimer(int i, int iterator, long& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			timer0[iterator] = value; break;
		case 1:
			timer1[iterator] = value; break;
		case 2:
			timer2[iterator] = value; break;
		default:					  break;
		}
	}
}
void _SegmentF::setChAfter(int i,int iterator, float& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			ch0After[iterator] = value; break;
		case 1:
			ch1After[iterator] = value;	break;
		case 2:
			ch2After[iterator] = value;	break;
		default:						break;
		}
	}
}
void _SegmentF::setChBefore(int i, int iterator ,float& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			ch0Before[iterator] = value; break;
		case 1:
			ch1Before[iterator] = value; break;
		case 2:
			ch2Before[iterator] = value; break;
		default:						 break;
		}
	}
}
void _SegmentF::setChDigital(int i, int iterator,int& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			ch0digital[iterator] = value; break;
		case 1:
			ch1digital[iterator] = value; break;
		case 2:
			ch2digital[iterator] = value; break;
		default:						  break;
		}
	}
}
long& _SegmentF::getTimer(int i, int iterator) {
	if (iterator >= 0 && iterator < maxIterator) {
		switch (i) {
		case 0:
			return timer0[iterator];
		case 1:
			return timer1[iterator];
		case 2:
			return timer2[iterator];
		default:							break;
		}
	}
	return timer0[maxIterator-1];
}
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
	if (full) {
		return;
	}
	if (temp == "") {
		//std::cout <<"iterator: "<< iterator << "\n";
		switch (program) {
		case ch0:	program = Program::ch1; iterator = 0; return;
		case ch1:	program = Program::ch2; iterator = 0; return;
		case ch2:	program = Program::digital; iterator = 0; return;
		case digital: full = true;
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
	if (file.eof) {
		eof = true; return;
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
bool& _SegmentF::isEof() {
	return eof;
}