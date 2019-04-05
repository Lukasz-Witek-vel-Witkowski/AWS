#pragma once
#ifndef SEGMENT_HPP
#define SEGMENT_HPP
#include <fstream>
#include <string>
#include <iostream>
enum Program {
	ch0,
	ch1,
	ch2,
	digital
};
constexpr auto maxIterator = 1024;
struct _SegmentF
{
public:
	int itrCh0;
	int itrCh1;
	int itrCh2;
	int itrDigital;
private:
	long timer0[maxIterator];
	long timer1[maxIterator];
	long timer2[maxIterator];
	float ch0After[maxIterator];
	float ch0Before[maxIterator];
	float ch1After[maxIterator];
	float ch1Before[maxIterator];
	float ch2After[maxIterator];
	float ch2Before[maxIterator];
	int ch0digital[maxIterator];
	int ch1digital[maxIterator];
	int ch2digital[maxIterator];
	Program program;
	bool full;
	std::string nameFile;
	int iterator;
	void config();
public:
	_SegmentF();
	_SegmentF(const _SegmentF& s);
	_SegmentF& operator=(const _SegmentF& s);
	bool operator==(const _SegmentF& s);
	void loadData(std::istream& file);
	void setTimer(int i, int iterator,long& value);
	void setChAfter(int i, int iterator,float& value);
	void setChBefore(int i,int iterator, float& value);
	void setChDigital(int i, int iterator,int& value);
	void setNameFile(std::string name);
	long& getTimer(int i, int iterator);
	bool& isFull();
	float& getChAfter(int i, int iterator);
	float& getChBefore(int i, int iterator);
	int getChDigital(int i, int iterator);
	void cutValue(std::string& data, std::string& value, std::size_t& ptr);
	void reset();
	int getIterator();
	~_SegmentF();
};
#endif // !SEGMENT_HPP
