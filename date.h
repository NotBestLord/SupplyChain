#ifndef __DATE_H__
#define __DATE_H__

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year) : year(year), month(month), day(day) {};
};

#endif