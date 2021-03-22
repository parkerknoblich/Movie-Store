#ifndef MANAGER_H
#define MANAGER_H

#include "customer.h"
#include "command.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "borrow.h"

#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int TABLE_SIZE = 100;

class Manager {
public:
    Manager();
    ~Manager();

    void runDay(ifstream&, ifstream&, ifstream&);

    void inventory();

    void printCustomers();
    void performCommands();

private:

    Customer* customers[TABLE_SIZE];
    int numOfCustomers;
    vector<Comedy> comedies;
    vector<Drama> dramas;
    vector<Classic> classics;
    vector<Command> commands;


    void setCustomers(ifstream&);
    int makeHash(Customer*);

    void setMovies(ifstream&);
    void setComedies(ifstream&);
    void setDramas(ifstream&);
    void setClassics(ifstream&);
    void sortComedies(vector<Comedy>&);
    void sortDramas(vector<Drama>&);
    void sortClassics(vector<Classic>&);
    void printComedies();
    void printDramas();
    void printClassics();

    void setCommands(ifstream&);

    //string trim(string);
};
#endif