#include <iostream>
#include "Support.h"
int main() {
	Support support("fileFocus.ini");
	if (support.getAction()) {
		support.fileDelete();
	}
	else {
		support.setPath("..\\result");
		support.loadData();
		support.run();
		support.save();
	}
	system("pause");
	return 0;
}