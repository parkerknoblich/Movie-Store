#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

#include <iostream>
using namespace std;

class Drama : public Movie {

    friend ostream& operator<<(ostream&, const Drama&);

public:
    Drama();
    Drama(int, string, string, int);

    void setData(ifstream&);

    bool operator==(const Drama&) const;
    bool operator!=(const Drama&) const;
    bool operator>(const Drama&) const;
    bool operator<(const Drama&) const;
};

#endif