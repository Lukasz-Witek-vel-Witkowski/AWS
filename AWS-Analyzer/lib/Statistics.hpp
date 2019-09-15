#pragma once
#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <list>
#include <algorithm>
#include <math.h>
#include "Tuple.hpp"
class Statistics {
public:
	Statistics()
	{
		massage = true;
	}
	void massageDisplay(bool value) {	//ustawienie wyswietlania komunikatow defoltowo na true
		massage = value;
	}
	template <class T,class C>
	void getMaxSTL(T& max,C Collection) {
		std::list<T> data;
		for(auto& x: Collection)
		data.push_back(x);
		sortDescending(data);
		max = *data.begin();
	}
	template <class T, class C>
	void getMinSTL(T& min, C Collection)
	{
		std::list<T> data;
		for (auto x : Collection)
			data.push_back(x);
		sortAscending(data);
		min = *data.begin();
	}
	template <class T, class C>
	void getAverageSTL(T& average, C Collection) {
		int size = 0;
		for (auto x : Collection) {
			if (size == 0) {
				average = x;
			}
			average = average + x;
			size++;
		}
		average = average / size;
	}
	template <class T, class C>
	void getMedianSTL(T& median, C Collection) {
		if (!Collection.empty()) {
			int iterator;
			std::list<T> Data;
			typename std::list<T>::iterator it;
			for (auto x : Collection)
				Data.push_back(x);
			if (Data.size() < 2) {
				if(massage)
				std::cout << "Too little data in the collection\n"; return;
			}
			sortAscending(Data);
			if (Data.size() % 2 == 0) {//kiedy parzyste
				T first;
				T secend;
				it = Data.begin();
				for (iterator = 0; iterator < (int)(Data.size() / 2); iterator++) it++;
				first = *it--;
				secend = *it;
				median = (first + secend) / 2;
			}
			else {
				it = Data.begin();
				for (iterator = 0; iterator < (int)((Data.size()) / 2); iterator++) it++;
				median = *it;
			}
			return;
		}
		if (massage)
			std::cout << "This collection is empty!\n";
	}
	template <class T,class C>
	void sortSTL(C& collection) {
		sort(collection.begin(), collection.end(),foo<T>);
	}
	template <class T, class C>
	void getAmplitudeSTL(T& amplitude, C collection) {
		T min = null;
		T max = null;
		getMinSTL(min, collection);
		getMaxSTL(max, collection);
		amplitude = max - min;
	}
	template <class T, class C>
	void getSumSTL(T& sum, C collection) {
		if (!collection.empty()) {
			for (auto x : collection)
				sum = sum + x; 
			return;
		}
		if(massage) 
			std::cout << "This collection is empty!\n";
	}
	template <class T, class C>
	void getStandardDeviation(T& standart, C Collection) {
		T average;
		getAverageSTL(average, Collection);
		T result=null;
		for (auto x : Collection) {
			if (result == null) result = pow(x - average, 2);
			else
				result += pow(x - average, 2);
		}
		standart=(sqrt(result/Collection.size()));
	}
	template <class T, class C>
	void getParameters(T& min, T& max, double& average, T& median, T& amplitud, double& standart, C Collection) { //min, max,srednia,mediana,amplituda,odchylenie standartowe, zbior danych
		int size = 0;
		sortAscending(Collection);
		min = *Collection.begin();
		max = *Collection.rbegin();
		amplitud = max - min;
		for (auto x : Collection) {
			if (average == null) average = x;
			else average = average + x;
			size++;
		}
		average = average / size;
		getMedianSTL(median, Collection);
		getStandardDeviation(standart, Collection);
	}
	~Statistics()
	{ }

private:
	template <class T>
	void sortAscending(std::list<T>& collection) {
		collection.sort();
	}
	template <class T>
	void sortDescending(std::list<T>& collection) {
		collection.sort(std::greater<T>());
	}
	bool massage;
};

#endif // !STATISTICS_HPP
