#pragma once

struct Chart {
	long double Mhz60;
	long double Mhz80;
	long double before;
	long double precent;
	void setParameter(int i, long double value) {
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
	long long getLimit() {
		if (before >= Mhz60 && before >= Mhz80) {
			return long long (before*precent);
		}
		else if (Mhz60 >= before && Mhz60 >= Mhz80) {
			return long long (Mhz60*precent);
		}
		else if (Mhz80 >= before && Mhz80 >= Mhz60) {
			return long long (Mhz80*precent);
		}
		return 1;
	}
};