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

public:
    Date()
    {
        day = -1;
        month = -1;
        year = -1;
    }
    Date(int d, int m, int y);
    Date(string);

    // Setters
    bool setDay(int);
    bool setMonth(int);
    bool setYear(int);

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Other functions
    friend ostream &operator<<(ostream &, Date &);
    bool operator<(const Date &);
    bool operator>(const Date &);
    bool operator==(const Date &);
    bool operator!=(const Date &);
    Date operator+(const Date &);
    Date operator-(const Date &);
    Date operator+(const int &days);
    Date operator-(const int &days);
};

#endif
