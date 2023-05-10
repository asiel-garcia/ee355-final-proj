#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
enum MONTH {January=1,February=2,March=3,April=4,May=5,June=6,July=7,August=8,September=9,October=10,November=11,December=12};
class Date{
protected:
    int month;
    int day;
    int year;
    string format;

public:
    Date();
    Date(string str);
    Date(int day, int month, int year);
    void set_date(string str);
    void set_date(int day, int month, int year);
    string month_name(string mon);
    void print_date(string format);
    bool operator==(const Date& rhs);
    bool operator!=(const Date& rhs);
};

#endif
