// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef DATE_H
#define DATE_H

#include <iostream>

using std::ostream;
using std::string;

class Date
{
private:
    int day;
    int month;
    int year;

    void _crunch();

public:
    Date()
    {
        day = -1;
        month = -1;
        year = -1;
    }
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
        _crunch();
    }
    Date(string);

    // Setters
    void setDay(int d){
        day=d;
        _crunch();
    }
    void setMonth(int m){
        month=m;_crunch();
    }
    void setYear(int y){
        year = y;_crunch();
    }

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Other functions
    friend ostream &operator<<(ostream &, Date &);
    bool operator<(Date &d) {return this->year<d.year||this->month<d.month||this->day<d.day;}
    bool operator>(Date &d) {return this->year>d.year||this->month>d.month||this->day>d.day;}
    bool operator==(Date &d) {return this->year==d.year&&this->month==d.month&&this->day==d.day;}
    bool operator!=(Date &d) {return this->year!=d.year&&this->month!=d.month&&this->day!=d.day;}
    Date operator+(Date &d) {return Date(this->day+d.day,this->month+d.month,this->year+d.year);}
    Date operator-(Date &d) {return Date(this->day+d.day,this->month+d.month,this->year+d.year);}
    Date operator+(int &days) {return Date(this->day+days,this->month,this->year);}
    Date operator-(int &days) {return Date(this->day-days,this->month,this->year);}
};

void Date::_crunch(){
    int daysInMonths[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //first clean up month
    year += month/12;
    month %= month;
    //then prune off days
    while (day>daysInMonths[month%12])
    {
        day-=daysInMonths[month%12];
        month++;
    }
    //in case days dropped below 0 (for subtraction)
    while (day<daysInMonths[(month+11)%12]){
        day+=daysInMonths[(month+11)%12];
        month+=11;
        month%=12;
    }
    //then fix month again if needed
    year += month/12;
    month %= month;
}

ostream &operator<<(ostream &out, Date &d){
    out<<d.day+1<<"/"<<d.month+1<<"/"<<d.year+1;
    return out;
}

Date::Date(string str){
    this->day = stoi(s.substr(0, s.find("/")).trim());
    this->month = stoi(s.substr(s.find("/"), s.find("/", s.find("/"))).trim());
    this->year = stoi(s.substr(s.find("/",s.find("/"))).trim());
}

#endif
