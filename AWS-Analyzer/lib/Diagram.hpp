#pragma once
#ifndef DIAGRAM_HPP
#define DIAGRAM_HPP
#include <vector>
#include "Statistics.hpp"
#include <math.h>
#include "Tuple.hpp"
template <class T> class Diagram {
public:
	Diagram() {
		Scale = 0;
		SIZE = 0;
		n = 0;
	}
	template <class C>
	void setContentCollectionSTL(C collection) {
		SIZE = 0;
		Data.clear();
		for (auto x : collection) {
			Data.push_back(x);
		}
	}
	void setScale(int value) {
		Scale = value;
	}
	void settingOfIntervals() {
		bool Double = false;
		int i;
		if (n == 0) {
			if (Data.size() <= 10) {
				Histogram.clear();
				for (auto x : Data) {
					//std::cout << x << "\n";
					Tuple<T> t(x);
					switch (Histogram.size()) {
					case 0: {
						Histogram.push_back(t);
						break;
					}
					default: {
						Double = false;
						for (i = 0; i < (int)Histogram.size(); i++) {
							if (Histogram[i] != t) { Double = true; break; }
						}
						if (!Double) {
							Tuple<T> tuple(x);
							Histogram.push_back(tuple);

							break;
						}
					}
					}
				}
			}
			else if (Data.size() > 10) {
				Histogram.clear();
				int compartments;
				T Amplitude;
				double temp;
				Tmin = null;
				compartments = (int)(5 * log10((int)Data.size()) - 1);
				statistics.getAmplitudeSTL(Amplitude, Data);
				temp = Amplitude / compartments;
				sizeInterval = (int)temp;
				if (temp > (double)sizeInterval + 0.5) {
					sizeInterval++;
				}
				sizeInterval++; //niew wiem czy potrzebne!
				statistics.getMinSTL(Tmin, Data);
				Amplitude = (T)0.1;
				if (Amplitude != 0.0) {
					Double = true;
				}
				if (!Double) {
					for (i = compartments - 1; i >= 0; i--) {
						Tuple<T> t((T)(Tmin + sizeInterval * i), (T)(Tmin + sizeInterval * (i + 1) - 1));
						Histogram.push_back(t);
					}
				}
				else {
					T temp;
					T Tmax;
					T sizeInter;
					int multi = 1;
					if (Tmin == 0.0) {
						statistics.sortSTL<T>(Data);
						for (auto x : Data) {
							if (Tmin < x) {
								Tmin = x; break;
							}
						}
					}
					while (true) {
						temp = Tmin * multi;
						if (temp > 1.0) break;
						multi++;
					}
					statistics.getMaxSTL(Tmax, Data);
					Amplitude = Tmax * multi - Tmin * multi;
					sizeInter = (Amplitude / compartments);
					sizeInter /= multi;
					for (i = compartments - 1; i >= 0; i--) {
						Tuple<T> t((T)(Tmin + sizeInter * i), (T)(Tmin + sizeInter * (i + 1)));
						Histogram.push_back(t);
					}
				}
			}
		}
		else {
			T Amplitude;
			T skok;
			T tmin;
			int i = 0;
			statistics.getMinSTL(tmin,Data);
			statistics.getAmplitudeSTL(Amplitude,Data);
			skok = Amplitude / (n + 1);
			for (i = ((int)skok*(n+1)); i >=0;i--) {
				Tuple<T> t((T)(tmin + skok * i), (T)(Tmin + skok * (i + 1) - 1));
				Histogram.push_back(t);
			}
		}
		for (auto x : Data) {
			for (i = 0; i < (int)Histogram.size(); i++) {
				if (Histogram[i] == x) { SIZE++; }
			}
		}
	}
	void setSizeClass(int size) {
		n = size;
	}
	void view(bool _what) {
		if (Scale == 0) {
			std::cout << "The histogram scale is not set!\n"; return;
		}
		int i;
		bool what=false;
		T t;
		statistics.getMaxSTL(t,Histogram);
		if (t > Scale) {
			what = true;
			t = t / Scale;
			for (i = 0; i < (int)Histogram.size(); i++) {
				Histogram[i] + t;
				Histogram[i] += Scale;
				Histogram[i] + _what;
			}
		}
		else {
			for (i = 0; i < (int)Histogram.size(); i++) {
				Histogram[i] += t+2;
				Histogram[i] += Scale;
			}
		}
		statistics.sortSTL<T>(Histogram);
		for (i = 0; i < (int)Histogram.size(); i++) {
			std::cout << Histogram[i];
		}
		if (what) {
			std::cout << "Proporcje histogramu: " << (char)254 << " - " << t << "\n";
			std::cout << "Suma wszystkich odnotowanych elementow: " << SIZE<<"\n";
		}
		else {
			std::cout << "Proporcje histogramu: " << (char)254 << " - " << 1 << "\n";
			std::cout << "Suma wszystkich odnotowanych elementow: " << SIZE<<"\n";
		}
	}	
	~Diagram() {}
private:
	std::vector<Tuple<T>> Histogram;
	Statistics statistics;
	T Tmin;
	int Scale;
	int sizeInterval;
	unsigned int SIZE;
	int n; //ilosc klas w histogramie
	std::vector<T> Data;
};
#endif // !DIAGRAMS_HPP

