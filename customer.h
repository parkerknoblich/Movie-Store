#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "command.h"

#include <fstream>
#include <vector>
using namespace std;

class Customer {

    friend ostream& operator<<(ostream&, const Customer&);

public:
    Customer();
    bool setData(ifstream&);
    int getID();
    string getFirstName() const;
    string getLastName() const;
    void printHistory() const;
private:
    int iD;
    string firstName;
    string lastName;
    vector<Command> commands;
};

#endif