#include "Segment.h"

void _SegmentF::config() {
	timer0 = new long[maxIterator];
	timer1 = new long[maxIterator];
	timer2 = new long[maxIterator];
	ch0After = new float[maxIterator];
	ch0Before = new float[maxIterator];
	ch1After = new float[maxIterator];
	ch1Before = new float[maxIterator];
	ch2After = new float[maxIterator];
	ch2Before = new float[maxIterator];
	ch0degetal = new int[maxIterator];
	ch1degetal = new int[maxIterator];
	ch2degetal = new int[maxIterator];
	program = Program::ch0;
	full = false;
	iterator = 0;
}
void _SegmentF::clear() {
	if (timer0 != nullptr) {
		delete[] timer0;
		timer0 = nullptr;
	}
	if (timer1 != nullptr) {
		delete[] timer1;
		timer1 = nullptr;
	}
	if (timer2 != nullptr) {
		delete[] timer2;
		timer2 = nullptr;
	}
	if (ch0After != nullptr) {
		delete[] ch0After;
		ch0After = nullptr;
	}
	if (ch0Before != nullptr) {
		delete[] ch0Before;
		ch0Before = nullptr;
	}
	if (ch1After != nullptr) {
		delete[] ch1After;
		ch1After = nullptr;
	}
	if (ch1Before != nullptr) {
		delete[] ch1Before;
		ch1Before = nullptr;
	}
	if (ch0degetal != nullptr) {
		delete[] ch0degetal;
		ch0degetal = nullptr;
	}
	if (ch1degetal != nullptr) {
		delete[] ch1degetal;
		ch1degetal = nullptr;
	}
	if (ch2After != nullptr) {
		delete[] ch2After;
		ch2After = nullptr;
	}
	if (ch2Before != nullptr) {
		delete[] ch2Before;
		ch2Before = nullptr;
	}
	if (ch2degetal != nullptr) {
		delete[] ch2degetal;
		ch2degetal = nullptr;
	}
}
_SegmentF::_SegmentF() {
	config();
}
_SegmentF::~_SegmentF() {
	clear();
}
_SegmentF::_SegmentF(const _SegmentF& s) {
	if (this != &s) *this = s;
}
_SegmentF& _SegmentF::operator=(const _SegmentF& s) {
	if (this == &s) return *this;
	if (*this == s) return *this;
	clear();
	config();
	int i;
	for (i = 0; i < maxIterator; i++) {
		timer0[i] = s.timer0[i];
		timer1[i] = s.timer1[i];
		timer2[i] = s.timer2[i];
		ch0After[i] = s.ch0After[i];
		ch0Before[i] = s.ch0Before[i];
		ch0degetal[i] = s.ch0degetal[i];
		ch1After[i] = s.ch1After[i];
		ch1Before[i] = s.ch1Before[i];
		ch1degetal[i] = s.ch1degetal[i];
		ch2After[i] = s.ch2After[i];
		ch2Before[i] = s.ch2Before[i];
		ch2degetal[i] = s.ch2degetal[i];
	}
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
			ch0degetal[iterator] = value;	break;
		case 1:
			ch1degetal[iterator] = value;	break;
		case 2:
			ch2degetal[iterator] = value;	break;
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
	long l = 0;
	return l;
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
	float f = 0.0;
	return f;
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
	float f = 0.0;
	return f;
}
int _SegmentF::getChDegetal(int i, int iterator) {
	if (iterator >= 0 && iterator < maxIterator) {
		switch (i) {
		case 0:
			return ch0degetal[iterator];
		case 1:
			return ch1degetal[iterator];
		case 2:
			return ch2degetal[iterator];
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
		if(iterator==0&&program==ch0)
		file.seekg(-1 * ((int)temp.size()+2), std::ios::cur);
		else
		file.seekg(-1 * ((int)temp.size()+3), std::ios::cur);
		switch (program) {
		case ch0:
			file >> timer0[iterator];
			file >> ch0After[iterator];
			file >> ch0Before[iterator];
			std::cout <<" "<<iterator<<" "<< timer0[iterator] << " " << ch0After[iterator] << " " << ch0Before[iterator] << "\n";
			iterator++; break;
		case ch1:
			file >> timer1[iterator];
			file >> ch1After[iterator];
			file >> ch1Before[iterator];
			std::cout <<" "<< iterator << " " << timer1[iterator] << " " << ch1After[iterator] << " " << ch1Before[iterator] << "\n";
			iterator++; break;
		case ch2:
			file >> timer2[iterator];
			file >> ch2After[iterator];
			file >> ch2Before[iterator];
			std::cout <<" "<< iterator << " " << timer2[iterator] << " " << ch2After[iterator] << " " << ch2Before[iterator] << "\n";
			iterator++; break;
		case digital:
			file >> ch0degetal[iterator];
			file >> ch1degetal[iterator];
			file >> ch2degetal[iterator];
			std::cout <<" "<< iterator << " " << ch0degetal[iterator] << " " << ch1degetal[iterator] << " " << ch2degetal[iterator] << "\n";
			iterator++; break;
		}
		std::getline(file, temp);
	}
}
bool& _SegmentF::isFull() {
	return full;
}
void _SegmentF::reset() {
	clear();
	config();
}
int _SegmentF::getIterator() {
	return iterator;
}