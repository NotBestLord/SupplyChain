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
    Date(const Date& other);
    Date(Date&& other);

    void setDay(int day) { this->day = day; }
	int getDay() const { return day; }
    void setMonth(int month) { this->month = month; }
	int getMonth() const { return month; }
    void setYear(int year) { this->year = year; }
	int getYear() const { return year; }

	friend istream& operator>>(istream& is, const Date& p);
	friend ostream& operator<<(ostream& os, const Date& p);
};
