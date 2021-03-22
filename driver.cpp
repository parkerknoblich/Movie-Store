#include <iostream>
#include <fstream>
using namespace std;

#include "manager.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

int main() {
    ifstream customers("data4customers.txt");
    if (!customers) {
        cout << "Customers File could not be opened." << endl;
        return 1;
    }
    ifstream movies("data4movies.txt");
    if (!movies) {
        cout << "Movies File could not be opened." << endl;
        return 1;
    }
    ifstream commands("data4commands.txt");
    if (!commands) {
        cout << "Commands File could not be opened." << endl;
        return 1;
    }
    Manager store;
    store.runDay(customers, movies, commands);
}