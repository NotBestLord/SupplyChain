#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

public:
    Date();
	Date(int day, int month, int year) : day(day), month(month), year(year) {}

	void setDay(int day) { this->day = day; }
	int getDay() const { return day; }
	void setMonth(int month) { this->month = month; }
	int getMonth() const { return month; }
	void setYear(int year) { this->year = year; }
	int getYear() const { return year; }

	friend std::istream& operator>>(std::istream& is, Date& d);
	friend std::ostream& operator<<(std::ostream& os, const Date& d);
};

#endif