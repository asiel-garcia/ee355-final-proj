#include "date.h"

using namespace std;

Date::Date(){
    day=1;
    month=1;
    year=2000;
}

Date::Date(string str){
    set_date(str);
}

Date::Date(int day, int month, int year){
    set_date(day,month,year);
}

void Date::set_date(string str){
    size_t first = str.find('/');
    size_t second = str.find('/');

    month = atoi(str.substr(0,first).c_str());
    day = atoi(str.substr(first+1,second).c_str());
    year = atoi(str.substr(second+1).c_str());
}

void Date::set_date(int day, int month, int year){
    this->month=month;
    this->day=day;
    this->year=year;
}

bool Date::operator==(const Date& rhs){
    if(day==rhs.day && month== rhs.month && year==rhs.year){
	return true;
    }
    else{return false;}
}
bool Date::operator!=(const Date& rhs){
    return !(*this == rhs);
}

void Date::print_date(string format){
    string mon;
    switch(month){
	case January: mon="January";break;
	case February: mon="February";break;
	case March: mon="March";break;
	case April: mon="April";break;
	case May: mon="May";break;
	case June: mon="June";break;
	case July: mon="July";break;
	case August: mon="August";break;
	case September: mon="September";break;
	case October: mon="October";break;
	case November: mon="November";break;
	case December: mon="December";break;
    }
    if(format =="M/D/YYYY")
	cout<<month<<'/'<<day<<'/'<<year<<endl;
    else if(format=="Month D, YYYY")
	cout<<mon<<' '<<day<<", "<<year<< endl;
    else
	cout<<"Wrong format type"<<endl;
}
