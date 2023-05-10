
#ifndef NETWORK_H
#define NETWORK_H

#include "person.h"
#include "date.h"
// You may need to add more libraries 
#include <stdlib.h>
#include <fstream>
#include <limits>
class Network{

    private:
        Person* head;
        Person* tail;
        int count; 
        Person* search(Person* searchEntry);
        Person* search(string fname, string lname);

    public:
        Network();
        Network(string fileName);
        ~Network();
        void printDB();
	void loadDB(string fileName);
	void saveDB(string fileName);
        void push_front(Person* newEntry);
        void push_back(Person* newEntry);
        bool remove(string fname, string lname);
        void showMenu();
};

#endif
