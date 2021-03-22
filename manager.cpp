#include "manager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

Manager::Manager() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        customers[i] = nullptr;
    }
    numOfCustomers = 0;
}

Manager::~Manager() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete customers[i];
        customers[i] = nullptr;
    }
    /*for (Command* command : commands) {
        delete command;
        command = nullptr;
    }*/
}

void Manager::runDay(ifstream& customers, ifstream& movies, ifstream& commands) {
    setCustomers(customers);
    printCustomers();
    setMovies(movies);
    inventory();
    //setCommands(commands);
}

void Manager::setCustomers(ifstream& infile) {
    while (true) {
        Customer* customer = new Customer();
        bool nextLine = customer->setData(infile);
        if (!nextLine) {
            delete customer;
            customer = nullptr;
            break;
        }
        else {
            int hash = makeHash(customer);
            customers[hash] = customer;
        }
    }
}

int Manager::makeHash(Customer* customer) {
    int hashOne = customer->getID() % TABLE_SIZE;
    if (customers[hashOne] == nullptr) {
        customers[hashOne] = customer;
    }
    else {
        int hashTwo = 7 - (customer->getID() % 7);
        int i = 1;
        while (true) {
            int newHash = (hashOne + i * hashTwo) % TABLE_SIZE;
            if (customers[newHash] == nullptr) {
                customers[newHash] = customer;
                break;
            }
            else {
                i++;
            }
        }
    }
    numOfCustomers++;
    return 5;
 }

void Manager::setMovies(ifstream& movies) {
    char genre;
    movies >> genre;
    for (;;) {
        if (movies.eof()) {
            break;
        }
        if (genre == 'C') {
            setClassics(movies);
        }
        else if (genre == 'F') {
            setComedies(movies);
        }
        else if (genre == 'D') {
            setDramas(movies);
        }
        else {
            cout << "Invalid genre code." << endl << endl;
            movies.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        movies >> genre;
    }
    sortComedies(comedies);
    sortDramas(dramas);
    sortClassics(classics);
}

void Manager::setClassics(ifstream& infile) {
    Classic classic;
    classic.setData(infile);
    classics.push_back(classic);
}

void Manager::setComedies(ifstream& infile) {
    Comedy comedy;
    comedy.setData(infile);
    comedies.push_back(comedy);
}

void Manager::setDramas(ifstream& infile) {
    Drama drama;
    drama.setData(infile);
    dramas.push_back(drama);
}

void Manager::setCommands(ifstream& infile) {
    char tranType;
    infile >> tranType;
    for (;;) {
        if (infile.eof()) {
            break;
        }
        if (tranType != 'I' && tranType != 'H' && tranType != 'B' && tranType != 'R') {
            cout << "Invalid error code: " << tranType << endl;
            continue;
        }
        if (tranType == 'I') {
            printComedies();
            printDramas();
            printClassics();
        }
        else if (tranType == 'H') {
            string temp;
            getline(infile, temp);
            int iD = stoi(temp);

        }
        else if (tranType == 'B') {
            Borrow borrow;
           // borrow.setData(infile);
        }
        else {

        }
    }
}

void Manager::sortComedies(vector<Comedy>& toSort) {
    int smallPos;
    for (int i = 0; i < toSort.size(); i++) {
        smallPos = i;
        for (int j = i + 1; j < toSort.size(); j++) {
            if (toSort.at(j) < toSort.at(smallPos)) {
                smallPos = j;
            }
        }
        Comedy temp = toSort[smallPos];
        toSort[smallPos] = toSort[i];
        toSort[i] = temp;
    }
}

void Manager::sortDramas(vector<Drama>& toSort) {
    int smallPos;
    for (int i = 0; i < toSort.size(); i++) {
        smallPos = i;
        for (int j = i + 1; j < toSort.size(); j++) {
            if (toSort.at(j) < toSort.at(smallPos)) {
                smallPos = j;
            }
        }
        Drama temp = toSort[smallPos];
        toSort[smallPos] = toSort[i];
        toSort[i] = temp;
    }
}

void Manager::sortClassics(vector<Classic>& toSort) {
    int smallPos;
    for (int i = 0; i < toSort.size(); i++) {
        smallPos = i;
        for (int j = i + 1; j < toSort.size(); j++) {
            if (toSort.at(j) < toSort.at(smallPos)) {
                smallPos = j;
            }
        }
        Classic temp = toSort[smallPos];
        toSort[smallPos] = toSort[i];
        toSort[i] = temp;
    }
}

void Manager::inventory() {
    printComedies();
    cout << endl;
    printDramas();
    cout << endl;
    printClassics();
    cout << endl;
}

void Manager::printComedies() {
    for (Comedy comedy : comedies) {
        cout << comedy;
    }
}

void Manager::printDramas() {
    for (Drama drama : dramas) {
        cout << drama;
    }
}

void Manager::printClassics() {
    for (Classic classic : classics) {
        cout << classic;
    }
}

void Manager::printCustomers() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (customers[i] != nullptr) {
            cout << i << " " << *customers[i] << endl;

        }
    }
    cout << endl;
}