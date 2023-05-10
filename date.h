#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;
//enum MONTH {January=1,February=2,Marh=3,April=4,May=5,June=6,July=7,August=8,September=9,Octobar=10,November=11,December=12};
class Date{
protected:
    string date;
    int month;
    int day;
    int year;
    string format;

public:
    Date();
    Date(string date);
    Date(int day, int month, int year);
    bool set_date(string date);
    bool set_date(int day, int month, int year);
    void print_date(string format);
    bool operator==(const Date& rhs);
};

#endif
