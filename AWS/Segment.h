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
private:
	long *timer0 = nullptr;
	long *timer1 = nullptr;
	long *timer2 = nullptr;
	float *ch0After = nullptr;
	float *ch0Before = nullptr;
	float *ch1After = nullptr;
	float *ch1Before = nullptr;
	float *ch2After = nullptr;
	float *ch2Before = nullptr;
	int *ch0degetal = nullptr;
	int *ch1degetal = nullptr;
	int *ch2degetal = nullptr;
	Program program;
	bool full;
	int iterator;
	void config();
	void clear();
public:
	_SegmentF();
	_SegmentF(const _SegmentF& s);
	_SegmentF& operator=(const _SegmentF& s);
	bool operator==(const _SegmentF& s);
	void loadData(std::istream& file);
	void setTimer(int i, int iterator,long& value);
	void setChAfter(int i, int iterator,float& value);
	void setChBefore(int i,int iterator, float& value);
	void setChDegetal(int i, int iterator,int& value);
	long& getTimer(int i, int iterator);
	bool& isFull();
	float& getChAfter(int i, int iterator);
	float& getChBefore(int i, int iterator);
	int getChDegetal(int i, int iterator);
	void reset();
	int getIterator();
	~_SegmentF();
};
#endif // !SEGMENT_HPP
