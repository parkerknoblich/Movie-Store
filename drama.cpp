#include "drama.h"
#include <iostream>
#include <fstream>
#include <string>

Drama::Drama() {
    setGenre('D');
    setStock(0);
    setDirector("");
    setTitle("");
    setYear(0);
}

Drama::Drama(int stock, string director, string title, int year) {
    setGenre('D');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYear(year);
}

void Drama::setData(ifstream& infile) {
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

bool Drama::operator==(const Drama& other) const {
    if ((getDirector() == other.getDirector()) && (getTitle() == other.getTitle())) {
        return true;
    }
    return false;
}

bool Drama::operator!=(const Drama& other) const {
    return !(*this == other);
}

bool Drama::operator>(const Drama& other) const {
    if (getDirector().compare(other.getDirector()) > 0) {
        return true;
    }
    else if (getDirector().compare(other.getDirector()) == 0) {
        if (getTitle().compare(other.getTitle()) > 0) {
            return true;
        }
    }
    return false;
}

bool Drama::operator<(const Drama& other) const {
    return !(*this > other || *this == other);
}

ostream& operator<<(ostream& output, const Drama& toPrint) {
    output << toPrint.getDirector() << " " << toPrint.getTitle() << endl;
    return output;
}