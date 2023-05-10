#include "network.h"
#include "misc.h"

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


void Network::loadDB(string filename){
    // TODO: Complete this method
    ifstream file(filename.c_str());
    string line;

    string f_name, l_name, email, phone, birthday;

    while (getline(file, line)) {
    	//char delim;
        //getline(file, f_name);
	f_name=line;
	//cout<<f_name;
        getline(file, l_name);
        getline(file, birthday);
        getline(file, email);
        getline(file, phone);
        Person* p = new Person(f_name, l_name, birthday, email, phone);
	p->print_person();
        push_back(p);
	getline(file,line);
    }
}
Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){ 
    if(head!=NULL){
	Person* temp = head;
	Person* prev;
	while(temp->next !=NULL){
	    prev=temp;
	    temp=temp->next;
	    delete prev;
	}
	delete temp;
    }
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person *curr = head;
    while(curr != NULL){
	if(*curr == *searchEntry){
	    return curr;
	}
    curr=curr->next;
    }
    return NULL;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* temp = head;
    while(temp!=NULL){
	if(temp->f_name == fname && temp->l_name == lname){
	    return temp;
	}
	temp = temp->next;
    }
    return NULL;
}





void Network::saveDB(string filename){
    // TODO: Complete this method
    ofstream file(filename.c_str());
    if(file.is_open()){
	streambuf* coutbuf = cout.rdbuf();
	cout.rdbuf(file.rdbuf());
	/*
        Person* curr = head;
        while(curr != NULL){
            curr->print_person();
	    cout<<endl;
            curr = curr->next;
        }
	*/
	printDB();
	cout.rdbuf(coutbuf);
        file.close();
    }
    else{
        cout << "Error: could not open file " << filename << endl;
    }
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    newEntry->next = NULL;
    newEntry->prev = tail;

    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;

    tail = newEntry;
    count++;
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    Person* curr = head;
    while(curr!=NULL){
        if(curr->f_name == fname && curr->l_name == lname){
            if(curr==head){
                if(head==tail){
                    head=NULL;
		    tail=NULL;
                }
                else{
		    head=head->next;
                    head->prev=NULL;
                }
            }
            else if(curr==tail){
		tail=tail->prev;
		tail->next=NULL;
            }
            else{
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
            }
            delete curr;
            count--;
            return true;
        }
        curr = curr->next;
    }
    return false;
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
	cout << "6. Connect \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            // Save the network database into the file with the given name,
            // with each person saved in the format the save as printing out the person info,
            // and people are delimited similar to "networkDB.txt" format
            getline(cin,fileName);
	    saveDB(fileName);
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            DIR* dir = opendir(".");
            if (dir) {
                struct dirent* entry;
                while ((entry = readdir(dir)) != NULL) {
                    if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != NULL) {
                        std::cout << entry->d_name << std::endl;
                    }
                }
                closedir(dir);
            }
            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            cin >> fileName;
            ifstream file(fileName.c_str());
            if (!file) {
                cout << "File "<<fileName<<" does not exist!" << endl;;
            }
            
            // If file is loaded successfully, also print the count of people in it: 
            else {
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
         }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";

	    Person* newP = new Person();
	    if(search(newP)==NULL){
		push_front(newP);
		cout<<"Person Added"<<endl;
	    }
	    else{
		cout<<"Person already exists"<<endl;
		delete newP;
	    }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;

	    if(remove(fname,lname)==1){
		cout<<"Person removed"<<endl;
	    }
	    else{
		cout<<"Person not found"<<endl;
	    }
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            cin>>lname;
	    
	    Person* temp = head;
	    while(temp!=NULL){
		if(temp->l_name == lname){
		    temp->print_person();
		}
		temp = temp->next;
	    }
        }
        else if (opt == 6){
            cout<<"Make friends: \n";
            cout<<"Person 1 \n";
            cout<< "First Name: ";
            getline(cin,fname);
            cout<< "Last Name: ";
            getline(cin,lname);
            Person* p1 = search(fname,lname);
	    if(p1 == NULL)
               cout<<"Person not Found" ;
            else{
               cout<<"\nPerson 2 \n";
               cout<< "First Name: ";
               getline(cin,fname);
               cout<< "Last Name: ";
               getline(cin,lname);
               Person* p2 = search(fname,lname);
               if(p2 == NULL)
                  cout<<"Person not Found";
               else{
		p1->makeFriend(p2);
		p2->makeFriend(p1);
		cout<<"\nFriendship Made!\n";
               }            
            }
        }
            
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}

