#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

#include <iostream>
using namespace std;

class Comedy : public Movie {

    friend ostream& operator<<(ostream&, const Comedy&);

public:
    Comedy();
    Comedy(int, string, string, int);

    void setData(ifstream&);

    bool operator==(const Comedy&) const;
    bool operator!=(const Comedy&) const;
    bool operator>(const Comedy&) const;
    bool operator<(const Comedy&) const;
};

#endif