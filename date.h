#pragma once
#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year) : day(day), month(month), year(year) {}

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	friend istream& operator>>(istream& is, const Date& p);
	friend ostream& operator<<(ostream& os, const Date& p);
};
