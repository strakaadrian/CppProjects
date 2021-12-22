#include "DateTime.h"

DateTime::DateTime(int _day, int _month, int _year, int _sec, int _min, int _hours)
    : day {_day}, month {_month}, year {_year}, sec {_sec}, min {_min}, hours {_hours}
{
}

int DateTime::GetDay() const
{
    return this->day;
}

int DateTime::GetMonth() const
{
    return this->month;
}

int DateTime::GetYear() const
{
    return this->year;
}

int DateTime::GetSec() const
{
    return this->sec;
}

int DateTime::GetMin() const
{
    return this->min;
}

int DateTime::GetHours() const
{
    return this->hours;
}

std::ostream & operator<<(std::ostream &os, const DateTime &obj)
{
    os << "Date: " << obj.GetDay() << '.' << obj.GetMonth() << '.' << obj.GetYear() << '\n' 
        << "Time: " << obj.GetHours() << ':' << obj.GetMin() << ':' << obj.GetSec() << '\n';
    
    return os;
}
