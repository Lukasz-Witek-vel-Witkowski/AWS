#include "Result.h"



Result::Result()
{
}
void Result::set_2_80(double value) {
	MHZ_2_80 = value;
}
void Result::set_6_60(double value) {
	MHZ_6_60 = value;
}
void Result::setFile(std::string data) {
	file = data;
}
std::string Result::getFile() {
	return file;
}
double Result::get_2_80() {
	return MHZ_2_80;
}
double Result::get_6_60() {
	return MHZ_6_60;
}
Result::~Result()
{
}
