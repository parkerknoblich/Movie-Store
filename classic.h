#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

#include <iostream>
using namespace std;

class Classic : public Movie {

    friend ostream& operator<<(ostream&, const Classic&);

public:
    Classic();
    Classic(int, string, string, string, int, int);

    void setData(ifstream&);

    void printMovie() const;

    string getActor() const;
    void setActor(string);

    int getMonth() const;
    void setMonth(int);

    bool operator==(const Classic&) const;
    bool operator!=(const Classic&) const;
    bool operator>(const Classic&) const;
    bool operator<(const Classic&) const;
private:
    string actor;
    int month;
};

#endif
