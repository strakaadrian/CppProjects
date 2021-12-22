#ifndef _DATETIME_H_
#define _DATETIME_H_

#include <iostream>

class DateTime
{
private:
    int day;
    int month;
    int year;
    int sec;
    int min;
    int hours;

public:
    DateTime(int, int, int, int, int, int);

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    int GetSec() const;
    int GetMin() const;
    int GetHours() const;

    friend std::ostream & operator<<(std::ostream &, const DateTime &);
};

#endif