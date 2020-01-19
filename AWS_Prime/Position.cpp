#include "Position.h"

Position::Position() {
	iterator = 0;
	value = 0.0;
}
void Position::setValue(long iterator, long double value) {
	this->iterator = iterator;
	this->value = value;
}
Position& Position::operator = (const Position& p) {
	if (this == &p) return *this;
	if (*this == p) return *this;
	this->iterator = p.iterator;
	this->value = p.value;
	return *this;
}
Position::Position(const Position& p) {
	if (this != &p) *this = p;
}
bool Position::operator==(const Position& p) {
	return (this->iterator == p.iterator && this->value == p.value);
}
bool Position::operator!=(const Position& p) {
	return (this->iterator != p.iterator && this->value != p.value);
}
long Position::getIterator() {
	return iterator;
}
long double Position::getValue() {
	return value;
}
bool Position::operator<(const Position& p) {
	if (this->value < p.value) return true;
	return false;
}
bool Position::operator>(const Position& p) {
	if (this->value > p.value) return true;
	return false;
}
bool Position::operator<=(const Position& p) {
	if (this->value <= p.value) return true;
	return false;
}
Position::~Position() {}