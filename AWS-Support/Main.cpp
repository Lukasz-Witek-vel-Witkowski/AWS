#include <iostream>
#include "Support.h"
int main() {
	Support support("fileFocus.ini");
	support.setPath("..\\result");
	support.loadData();
	support.run();
	support.save();
	system("pause");
	return 0;
}