#pragma once
#include <vector>
#include <string>
struct Attribute
{
	std::string value;
	bool compartment;
	std::vector<std::string> V_attribute;
	Attribute() {}
	bool In_terms_of(std::string data) {
		if (compartment) {
			if (V_attribute.size() % 2 == 0) {
				for (int i = 0; i < V_attribute.size()-1; i += 2) {
					if (V_attribute[i] <= data && V_attribute[i + 1] >= data) return true;
				}
			}
			else {
				for (int i = 0; i < V_attribute.size()-1; i++) {
					if (V_attribute[i] <= data && V_attribute[i + 1] >= data) return true;
				}
			}
		}
		else {
			for (auto x : V_attribute) {
				if (x == data) {
					return true;
				}
			}
		}
		return false;
	}
	void clearWhiteChars() {
		for (auto& x : V_attribute) {
			if (x.find(' ') < x.size()) {
				x.erase(x.begin() + x.find(' '));
			}
		}
	}
};