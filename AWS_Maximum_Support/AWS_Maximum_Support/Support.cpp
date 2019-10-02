#include "Support.h"



Support::Support()
{
	value = 0;
}
void Support::config(int Value) {
	value = Value;
}
std::string Support::nextValue() {
	return std::to_string(value++);
}

Support::~Support()
{
}
