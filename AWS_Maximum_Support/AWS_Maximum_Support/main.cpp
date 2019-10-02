#include <iostream>
#pragma warning(disable : 4996)
#include "Manager.h"
int main() {
	Manager m("Config.cnf");
	m.run();
	_sleep(1000);
	return 0;
}