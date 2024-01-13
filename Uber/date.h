#pragma once
#include <iostream>
using namespace std;

class date {
	int day;
	int month;
	int year;
public:
	date();
	date(int d, int m, int y);
	void setDay(int obj);
	void setMonth(int obj);
	void setYear(int obj);
	int getDay();
	int getMonth();
	int getYear();
	friend ostream& operator<<(ostream& out, const date& temp);
};