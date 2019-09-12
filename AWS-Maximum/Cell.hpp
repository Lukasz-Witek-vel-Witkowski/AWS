#pragma once

struct Cell {

	double Before;
	double CH60;
	double CH80;

	Cell(double before, double ch60, double ch80) {
		Before = before;
		CH60 = ch60;
		CH80 = ch80;
	}
	Cell& operator==(Cell& c) {
		if (this == &c) return *this;
		Before = c.Before;
		CH60 = c.CH60;
		CH80 = c.CH80;
		return *this;
	}
	~Cell() {}
};