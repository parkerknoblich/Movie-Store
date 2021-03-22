#include "customer.h"
#include <fstream>
using namespace std;

Customer::Customer() {
    iD = 0;
    firstName = "";
    lastName = "";
}

bool Customer::setData(ifstream& infile) {
    infile >> iD;
    if (infile.eof()) {
        return false;
    }
    infile >> lastName;
    infile >> firstName;
    return true;
}

void Customer::printHistory() const {
    for (Command command : commands) {
        cout << command << endl;
    }
}

int Customer::getID() {
    return iD;
}

string Customer::getFirstName() const {
    return firstName;
}

string Customer::getLastName() const {
    return lastName;
}

ostream& operator<<(ostream& output, const Customer& toPrint) {
    output << toPrint.firstName << " " << toPrint.lastName;
    return output;
}