#pragma once
#ifndef SEGMENT_HPP
#define SEGMENT_HPP
constexpr auto maxIterator = 1024;
struct _SegmentF
{
public:
	long *timer0;
	long *timer1;
	long *timer2;
	float *ch0After;
	float *ch0Before;
	float *ch1After;
	float *ch1Before;
	float *ch2After;
	float *ch2Before;
	int *ch0degetal;
	int *ch1degetal;
	int *ch2degetal;
	_SegmentF() {
		timer0 = new long[maxIterator];
		timer1 = new long[maxIterator];
		timer2 = new long[maxIterator];
		ch0After = new float[maxIterator];
		ch0Before = new float[maxIterator];
		ch1After = new float[maxIterator];
		ch1Before = new float[maxIterator];
		ch2After = new float[maxIterator];
		ch2Before = new float[maxIterator];
		ch0degetal = new int[maxIterator];
		ch1degetal = new int[maxIterator];
		ch2degetal = new int[maxIterator];
	}
	~_SegmentF() {
		delete[] timer0;
		delete[] timer1;
		delete[] timer2;
		delete[] ch0After;
		delete[] ch0Before;
		delete[] ch1After;
		delete[] ch1Before;
		delete[] ch2After;
		delete[] ch2Before;
		delete[] ch0degetal;
		delete[] ch1degetal;
		delete[] ch2degetal;
	}
};
#endif // !SEGMENT_HPP
