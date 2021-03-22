#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <fstream>
using namespace std;

class Command {

friend ostream& operator<<(ostream&, const Command&);

public:
    Command();

    char getTranType() const;
    char getMediaType() const;
    char getGenre() const;
    int getID() const;
    int getMonth() const;
    int getYear() const;
    string getActor() const;
    string getDirector() const;
    string getTitle() const;

protected:
    char tranType;
    char mediaType;
    char genre;
    int iD;
    int month;
    int year;
    string actor;
    string director;
    string title;
};
#endif