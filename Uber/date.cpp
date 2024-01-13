#include "date.h"
#include <ctime>
date::date() {
	time_t var = time(0);
	tm temp;
	localtime_s(&temp, &var);
	year = 1900 + temp.tm_year;
	month = 1 + temp.tm_mon;
	day = temp.tm_mday;
}
date::date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
void date::setDay(int obj) {
	day = obj;
}

void date::setMonth(int obj) {
	month = obj;
}
void date::setYear(int obj) {
	year = obj;
}

int date::getDay() {
	return day;
}
int date::getMonth() {
	return month;
}
int date::getYear() {
	return year;
}
ostream& operator<<(ostream& out, const date& temp) {
	out << temp.day << "/" << temp.month << "/" << temp.year;
	return out;
}