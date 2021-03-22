#include "classic.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

Classic::Classic() {
    setGenre('C');
    setStock(0);
    setDirector("");
    setTitle("");
    setActor("");
    setMonth(0);
    setYear(0);
}

Classic::Classic(int stock, string director, string title, string actor, int month, int year) {
    setGenre('C');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setActor(actor);
    setMonth(month);
    setYear(year);
}

void Classic::setData(ifstream& infile) {
    string temp;
    getline(infile, temp, ',');
    getline(infile, temp, ',');
    setStock(atoi(temp.c_str()));
    getline(infile, temp, ',');
    setDirector(trim(temp));
    getline(infile, temp, ',');
    setTitle(trim(temp));
    getline(infile, temp, ' ');
    getline(infile, temp, ' ');
    string firstName = temp;
    getline(infile, temp, ' ');
    string lastName = temp;
    string actorName = firstName + " " + lastName;
    setActor(trim(actorName));
    getline(infile, temp, ' ');
    setMonth(atoi(temp.c_str()));
    getline(infile, temp, '\n');
    setYear(atoi(temp.c_str()));
}

bool Classic::operator==(const Classic& other) const {
    if ((getMonth() == other.getMonth()) && (getYear() == other.getYear()) && (getActor() == other.getActor())) {
        return true;
    }
    return false;
}

bool Classic::operator!=(const Classic& other) const {
    return !(*this == other);
}

bool Classic::operator>(const Classic& other) const {
    if (getYear() > other.getYear()) {
        return true;
    }
    else if (getYear() == other.getYear()) {
        if (getMonth() > other.getMonth()) {
            return true;
        }
        else if (getMonth() == other.getMonth()) {
            if (getActor() > other.getActor()) {
                return true;
            }
        }
    }
    return false;
}

bool Classic::operator<(const Classic& other) const {
    return !(*this == other || *this > other);
}

string Classic::getActor() const {
    return actor;
}

void Classic::setActor(string actor) {
    this->actor = actor;
}

int Classic::getMonth() const {
    return month;
}

void Classic::setMonth(int month) {
    this->month = month;
}

ostream& operator<<(ostream& output, const Classic& toPrint) {
    output << toPrint.getMonth() << " " << toPrint.getYear() << " " << toPrint.getActor() << endl;
    return output;
}

void Classic::printMovie() const {
    cout << getStock() << ", ";
    cout << getDirector() << ", ";
    cout << getTitle() << ", ";
    cout << getActor() << ", ";
    cout << getMonth() << ", ";
    cout << getYear() << endl;
}