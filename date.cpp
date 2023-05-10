#include <string>
#include <iostream>
#include "date.h"

using namespace std;

Date::Date(){
    day=1;
    month=1;
    year=2000;
}

Date::Date(string date){
    set_date(date);
}

Date::date(int day, int month, int year){
    set_date(day,month,year)
}

void Date::set_date(string date){
    size_t first = date.find('/');
    size_t second = date.find('/');

    this->month = date.substr(0,first);
    this->day = date.substr(first+1,second);
    this->year = date.substr(second+1);

}

string Date::month_name(string month){
    string month_string;
    if(month == "1"){
	month_string = "January";
    }
    else if(month == "2"){
	month_string = "February";
    }
    else if(month == "3"){
	month_string = "March";
    }
    else if(month == "4"){
	month_string = "April";
    }
    else if(month == "5"){
	month_string = "May";
    }
    else if(month == "6"){
        month_string = "June";
    }
    else if(month == "7"){
	month_string = "July";
    }
    else if(month == "8"){
        month_string = "August";
    }
    else if(month == "9"){
	month_string = "September";
    }
    else if(month == "10"){
        month_string = "October";
    }
    else if(month == "11"){
	month_string = "November";
    }
    else if(month == "12"){
        month_string = "December";
    }
    return month_string;
}

bool Date::operator==(const Date& rhs){
    return (date == rhs.date);
}

void Date::print_date(string format){
    cout<<format<<endl;
    cout<<month_name(month)<<" "<<day<<", "<<year<<endl;
}
