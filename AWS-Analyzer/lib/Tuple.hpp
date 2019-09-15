#pragma once
#ifndef TUPLE_HPP
#define TUPLE_HPP
#include <iostream>
const int null = 0;
constexpr auto FIRST = 0;
constexpr auto SECEND = 1;
template <class T>
class Tuple {
public:
	Tuple() {
		divider = 1;
		Interval = false;
		size = 0;
		active = false;
		compartment = false;
	}
	Tuple(T t) {
		divider = 1;
		Interval = false;
		value = new T[1];
		value[FIRST] = t;
		size = 0;
		active = true;
		compartment = false;
	}
	Tuple(T tMIN, T tMAX) {
		divider = 1;
		Interval = true;
		value = new T[2];
		value[FIRST] = tMIN;
		value[SECEND] = tMAX;
		size = 0;
		active = true;
		compartment = false;
	}
	Tuple(const Tuple& t) {
		if (this != &t) {
			*this = t;
		}
	}
	Tuple& operator=(const Tuple<T>& t) {
		if (this == &t) return *this;
		if (*this == t) return *this;
		active = t.active;
		Interval = t.Interval;
		compartment = t.compartment;
		Scale = t.Scale;
		if (Interval) {
			value = new T[2];
			value[FIRST] = t.value[FIRST];
			value[SECEND] = t.value[SECEND];
		}
		else {
			value = new T[1];
			value[FIRST] = t.value[FIRST];
		}
		size = t.size;
		divider = t.divider;
		return *this;
	}
	bool operator==(const Tuple<T>& t) {
		if (active==true&&t.active==true) {
			if (Interval == t.Interval&& size == t.size) {
				if (Interval&&value[FIRST] == t.value[FIRST] && value[SECEND] == t.value[SECEND]) return true;
				else if (!Interval&&value[FIRST] == t.value[FIRST]) return true;
			}
		}
		return false;
	}
	bool operator==(const T& t) {
		if (Interval) {
			if (value[SECEND] >= t && t >= value[FIRST]) {
				size++;		
				return true;
			}	
			return false;
		}
		else if (value[FIRST] == t) {
			size++; 
			return true;
		}
		return false;
	}
	bool operator!=(const Tuple<T>& t) {
		if (this->active==true && t.active == true) {
			if (Interval&&this->value[FIRST] == t.value[FIRST] && this->value[SECEND] == t.value[SECEND]) return true;
			if (!Interval&&this->value[FIRST] == t.value[FIRST]) return true;
		}
		return false;
	}
	int getSize() {
		return size;
	}
	operator T()
	{
		return size;
	}
	T getMinInterval() {
		if (Interval) return value[FIRST];
		return value[FIRST];
	}
	T getMaxInterval() {
		if (Interval) return value[SECEND];
		return value[FIRST];
	}
	bool getInterval() {
		return Interval;
	}
	bool operator+(const T& t)  {
		divider = t; return true;
	}
	bool operator*(const T& t) { //poczatek intervalu
		if(Interval)
		T[FIRST] = t; return true;
	}
	bool operator/(const T& t) { //koniec intervalu
		if (Interval)
		T[SECEND] = t; return true;
	}
	bool operator+(const bool& t) {
		compartment = t; return true;
	}
	bool operator+=(int t) {
		Scale = t; return true;
	}
	int getDivider() {
		return divider;
	}
	~Tuple() {
		if (Interval)
			delete[] value;
		else
			delete value;
	}
	int getScale() {
		return Scale;
	}
	bool comp() {
		return compartment;
	}
private:
	bool Interval;
	bool active;
	bool compartment;
	T* value;
	int size;
	int Scale;
	int divider;
};
template <class T>
std::ostream& operator<<(std::ostream& is, Tuple<T>& t) {
	char _char = (char)254;
	if (t.getSize() != 0) {
		if (t.getInterval()&&!t.comp()) {
			is << t.getMinInterval() << '-' << t.getMaxInterval() << "\t|";
		}
		else if (t.getInterval() && !t.comp()) {
			is << t.getMinInterval() << '-' << t.getMaxInterval() << "\t|";
		}
		else
			is << t.getMinInterval() << "\t|";
		int i;
		for (i = 0; i < t.getSize() / t.getDivider(); i++) {
			is << _char;
		}
		is.width(t.getScale() - i);
		is << "\t" << t.getSize() << "\n";
	}
	return is;
}
template <class T>
bool operator>(const int& i, const Tuple<T>& tuple) {
	return i>tuple.getSize();
}
template <class T>
bool operator>(const Tuple<T>& i, const Tuple<T>& tuple) {
	return i.getSize() > tuple.getSize();
}
template <class T>
bool foo(Tuple<T> Tleft, Tuple<T> Tright) {
	return Tleft.getMinInterval() < Tright.getMinInterval();
}
#endif // !TUPLE_HPP
