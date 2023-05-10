#include "person.h"
#include "date.h"
#include "contact.h"

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete phone;
    delete email;
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name = f_name;
    this->l_name = l_name;
    birthdate = new Date(b_date);
    this->email = new Email("",email);
    this->phone = new Phone("",phone);
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    std::getline(std::cin,type); // code here
    cout << "Email address: ";
    std::getline(std::cin,temp); // code here

    email = new Email(type, temp);

    cout << "Type of phone number: ";
    std::getline(std::cin,type); // code here
    cout << "Phone number: ";
    std::getline(std::cin, temp); // code here
    phone = new Phone(type, temp); // code here
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!

    ifstream infile(filename.c_str());
    if(!infile){
	cout<<"unable to open file "<<filename<<endl;
	exit(1);
    }

    string temp, p, e, type1, type2;

    std::getline(infile, f_name);
    std::getline(infile, l_name);
    std::getline(infile, temp);
    birthdate = new Date(temp);
    std::getline(infile,type1, ' ');
    std::getline(infile, p);
    email = new Email(type1, p);
    std::getline(infile,type2, ' ');
    std::getline(infile,e);
    phone = new Phone(type2, e);

    infile.close();
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)

    return (f_name == rhs.f_name && l_name == rhs.l_name && *birthdate == *(rhs.birthdate));
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!

    return !(*this == rhs);
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
}
