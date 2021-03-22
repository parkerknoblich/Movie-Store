#include "comedy.h"
#include <iostream>
#include <fstream>
#include <string>

Comedy::Comedy() {
    setGenre('F');
    setStock(0);
    setDirector("");
    setTitle("");
    setYear(0);
}

Comedy::Comedy(int stock, string director, string title, int year) {
    setGenre('F');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYear(year);
}

void Comedy::setData(ifstream& infile) {
    string temp;
    getline(infile, temp, ',');
    getline(infile, temp, ',');
    setStock(atoi(temp.c_str()));
    getline(infile, temp, ',');
    setDirector(trim(temp));
    getline(infile, temp, ',');
    setTitle(trim(temp));
    getline(infile, temp);
    setYear(atoi(temp.c_str()));
}

bool Comedy::operator==(const Comedy& other) const {
    if ((getTitle() == other.getTitle()) && (getYear() == other.getYear())) {
        return true;
    }
    return false;
}

bool Comedy::operator!=(const Comedy& other) const {
    return !(*this == other);
}

bool Comedy::operator>(const Comedy& other) const {
    if (getTitle().compare(other.getTitle()) > 0) {
        return true;
    }
    else if (getTitle().compare(other.getTitle()) == 0) {
        if (getYear() > other.getYear()) {
            return true;
        }
    }
    return false;
}

bool Comedy::operator<(const Comedy& other) const {
    return !(*this > other || *this == other);
}

ostream& operator<<(ostream& output, const Comedy& toPrint) {
    output << toPrint.getTitle() << " " << toPrint.getYear() << endl;
    return output;
}