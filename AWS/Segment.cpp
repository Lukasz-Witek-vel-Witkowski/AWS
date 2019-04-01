#include "Segment.h"

void _SegmentF::config() {
	program = Program::ch0;
	full = false;
	iterator = 0;
}
_SegmentF::_SegmentF() {
	config();
}
_SegmentF::~_SegmentF() {}
_SegmentF::_SegmentF(const _SegmentF& s) {
	if (this != &s) *this = s;
}
_SegmentF& _SegmentF::operator=(const _SegmentF& s) {
	if (this == &s) return *this;
	if (*this == s) return *this;
	config();
	int i;
	for (i = 0; i < maxIterator; i++) {
		timer0[i] = s.timer0[i];
		timer1[i] = s.timer1[i];
		timer2[i] = s.timer2[i];
		ch0After[i] = s.ch0After[i];
		ch0Before[i] = s.ch0Before[i];
		ch0digital[i] = s.ch0digital[i];
		ch1After[i] = s.ch1After[i];
		ch1Before[i] = s.ch1Before[i];
		ch1digital[i] = s.ch1digital[i];
		ch2After[i] = s.ch2After[i];
		ch2Before[i] = s.ch2Before[i];
		ch2digital[i] = s.ch2digital[i];
	}
	return *this;
}
bool _SegmentF::operator==(const _SegmentF& s) {
	return false;
}
void _SegmentF::setTimer(int i, int iterator, long& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			timer0[iterator] = value;	break;
		case 1:
			timer1[iterator] = value;	break;
		case 2:
			timer2[iterator] = value;	break;
		default:						break;
		}
	}
}
void _SegmentF::setChAfter(int i,int iterator, float& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			ch0After[iterator] = value;	break;
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
			ch0Before[iterator] = value;	break;
		case 1:
			ch1Before[iterator] = value;	break;
		case 2:
			ch2Before[iterator] = value;	break;
		default:							break;
		}
	}
}
void _SegmentF::setChDegetal(int i, int iterator,int& value) {
	if (iterator >= 0 && iterator < maxIterator&& &value != nullptr) {
		switch (i) {
		case 0:
			ch0digital[iterator] = value;	break;
		case 1:
			ch1digital[iterator] = value;	break;
		case 2:
			ch2digital[iterator] = value;	break;
		default:							break;
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
int _SegmentF::getChDegetal(int i, int iterator) {
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
	int j = 0;
	return i;
}
void _SegmentF::loadData(std::istream& file) {
	std::string temp;
	std::getline(file, temp);
	if (full) {
		return;
	}
	if (temp == "") {
		switch (program) {
		case ch0:	program = Program::ch1; iterator = 0; return;
		case ch1:	program = Program::ch2; iterator = 0; return;
		case ch2:	program = Program::digital; iterator = 0; return;
		case digital: full = true;
		}
	}
	else {
		std::string value, yong;
		std::size_t ptr; 
		switch (program) {
		case ch0:
			cutValue(temp, value, ptr);
			timer0[iterator] = atoi(value.c_str());
			cutValue(temp, value, ptr);
			ch0After[iterator] = (float)atof(value.c_str());
			ch0Before[iterator] = (float)atof(temp.c_str());
			//std::cout <<" "<<iterator<<" "<< timer0[iterator] << " " << ch0After[iterator] << " " << ch0Before[iterator] << "\n";
			iterator++; break;
		case ch1:
			cutValue(temp, value, ptr);
			timer1[iterator] = atoi(value.c_str());
			cutValue(temp, value, ptr);
			ch1After[iterator] = (float)atof(value.c_str());
			ch1Before[iterator] = (float)atof(temp.c_str());
			//std::cout <<" "<< iterator << " " << timer1[iterator] << " " << ch1After[iterator] << " " << ch1Before[iterator] << "\n";
			iterator++; break;
		case ch2:
			cutValue(temp, value, ptr);
			timer2[iterator] = atoi(value.c_str());
			cutValue(temp, value, ptr);
			ch2After[iterator] = (float)atof(value.c_str());
			ch2Before[iterator] = (float)atof(temp.c_str());
			//std::cout <<" "<< iterator << " " << timer2[iterator] << " " << ch2After[iterator] << " " << ch2Before[iterator] << "\n";
			iterator++; break;
		case digital:
			cutValue(temp, value, ptr);
			ch0digital[iterator] = atoi(value.c_str());
			cutValue(temp, value, ptr);
			ch1digital[iterator] = atoi(value.c_str());
			ch2digital[iterator] = atoi(temp.c_str());
			//std::cout <<" "<< iterator << " " << ch0degetal[iterator] << " " << ch1degetal[iterator] << " " << ch2degetal[iterator] << "\n";
			iterator++; break;
		}
	}
}
bool& _SegmentF::isFull() {
	return full;
}
void _SegmentF::reset() {
	config();
}
int _SegmentF::getIterator() {
	return iterator;
}
void _SegmentF::cutValue(std::string& data, std::string& value, std::size_t& ptr) {
	ptr = data.find('\t');
	value = data.substr(ptr);
	data = data.replace(0, ptr, "");
}
void _SegmentF::setNameFile(std::string name) {
	nameFile = name;
}