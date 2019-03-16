#include "Record.h"



Record::Record()
{
	measurement = false;
	diagnosis = true;
	section = false;
	good = false;
}
Record::Record(const Record& r) {
	if (this != &r) *this = r;
}
Record& Record::operator=(const Record& r) {
	if (this == &r) return *this;
	if (*this == r) return *this;
	measurement = r.measurement;
	good = r.good;
	diagnosis = r.diagnosis;
	section = r.section;
	if (measurement) {
		time = new long;
		firstMeasurement = new float;
		secendMeasurement = new float;
		*time = *r.time;
		*firstMeasurement = *r.firstMeasurement;
		*secendMeasurement = *r.secendMeasurement;
	}
	else {
		firstValue = new int;
		secendValue = new int;
		thirdValue = new int;
		*firstValue = *r.firstValue;
		*secendValue = *r.secendValue;
		*thirdValue = *r.thirdValue;
	}
	return *this;
}
bool Record::operator==(const Record& r) {
	if (measurement == r.measurement&&good == r.good&&diagnosis == r.diagnosis&&section == r.section) {
		if (measurement) {
			if (*time == *r.time&& *firstMeasurement == *r.firstMeasurement&& *secendMeasurement) return true;
			return false;
		}
		else {
			if (*firstValue == *r.firstValue&&*secendValue == *r.secendValue&&*thirdValue == *r.thirdValue) return true;
			return false;
		}
	}
	return false;
}
void Record::loadData(std::istream& file) {
	std::string temp;
	std::getline(file, temp);
	std::cout<<" "<< temp <<'\n';
	if (diagnosis) diagnostics(temp);
	if (temp == "") {
		diagnosis = true; 
		section = true;
		return;
	}
	else {
		good = true;
		file.seekg(-1*(int)temp.size(), std::ios::cur);
		if (measurement) {
			time = new long;
			secendMeasurement = new float;
			firstMeasurement = new float;
			file >> *time;
			file >> *firstMeasurement;
			file >> *secendMeasurement;
			std::getline(file, temp);
		}
		else {
			firstValue = new int;
			secendValue = new int;
			thirdValue = new int;
			file >> *firstValue;
			file >> *secendValue;
			file >> *thirdValue;
			std::getline(file, temp);
		}
	}
}
void Record::diagnostics(std::string& data) {
	measurement = false;
	if (data.size() > 0) {
		if (data.find('.') || data.find(',')) {
			measurement = true;
			return;
		}
		else {
			std::string temp;
			int intValue;
			for (int i = 0; i < (int)data.size(); i++) {
				if (data[i] == ' ' || data[i] == '\t') break;
				temp.push_back(data[i]);
			}
			intValue=atoi(temp.c_str());
			if (intValue > limit) { 
				measurement = true; 
				return; }
		}
	}
}
Record::~Record()
{
	if (good) {
		if (measurement) {
			delete firstMeasurement;
			delete secendMeasurement;
			delete time;
		}
		else {
			delete firstValue;
			delete secendValue;
			delete thirdValue;
		}
	}
}
bool Record::newSection() {
	if (section) {
		section = false;
		return true;
	}
	return false;
}
std::string Record::performance() {
	//z tego co udalo mi sie zapamietac!!
	std::string data="";
	if (measurement) {
		//data += std::to_string(*time);
		//data += ' ';
		data += std::to_string((long)(*firstMeasurement *sPow));
		//data += ' ';
		//data += std::to_string((long)(*secendMeasurement *sPow));
	}
	else {
	/*	data += std::to_string(*firstValue);
		data += ' ';
		data += std::to_string(*secendValue);
		data += ' ';
		data += std::to_string(*thirdValue);*/
	}
	return data;
}
long Record::getTime() {
	return *time;
}
int Record::getCanal() { return canal; }
void Record::setCanal(int Canal) { canal = Canal; }
float Record::getAfter() {
	if (measurement) return *firstMeasurement;
	return 0.0;
}
float Record::getBefore() {
	if (measurement) return *secendMeasurement;
	return 0.0;
}
int Record::getValue(int iter) {
	switch (iter) {
	case 0:	return *firstValue;
	case 1:	return *secendValue;
	case 2: return *thirdValue;
	}
	return 0;
}