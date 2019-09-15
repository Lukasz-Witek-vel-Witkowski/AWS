#pragma once

struct Chart {
	double Mhz60;
	double Mhz80;
	double before;
	double precent;
	void setParameter(int i, double value) {
		switch (i) {
		case 1:
			before = value;
			break;
		case 2:
			Mhz60 = value;
			break;
		case 3:
			Mhz80 = value;
		}
	}
	int getLimit() {
		if (before >= Mhz60 && before >= Mhz80) {
			return (int)before*precent;
		}
		else if (Mhz60 >= before && Mhz60 >= Mhz80) {
			return (int)Mhz60*precent;
		}
		else if (Mhz80 >= before && Mhz80 >= Mhz60) {
			return (int)Mhz80*precent;
		}
	}
};