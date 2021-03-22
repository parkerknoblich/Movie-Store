#include "command.h"

#include <iostream>
using namespace std;

Command::Command() {
    tranType = '\0';
    mediaType = '\0';
    genre = '\0';
    iD = 0;
    month = 0;
    year = 0;
    actor = "";
    director = "";
    title = "";
}

char Command::getTranType() const {
    return tranType;
}

char Command::getMediaType() const {
    return mediaType;
}

char Command::getGenre() const {
    return genre;
}

int Command::getID() const {
    return iD;
}

int Command::getMonth() const {
    return month;
}

int Command::getYear() const {
    return year;
}

string Command::getActor() const {
    return actor;
}

string Command::getDirector() const {
    return director;
}

string Command::getTitle() const {
    return title;
}

ostream& operator<<(ostream& output, const Command& toPrint) {
    output << toPrint.getTranType() << " ";
    output << toPrint.getID() << " ";
    output << toPrint.getMediaType() << " ";
    output << toPrint.getGenre() << " ";
    if (toPrint.getGenre() == 'F') {
        output << toPrint.getTitle() << ", ";
        output << toPrint.getYear() << endl;
    }
    else if (toPrint.getGenre() == 'D') {
        output << toPrint.getDirector() << ", ";
        output << toPrint.getTitle() << "," << endl;
    }
    else if (toPrint.getGenre() == 'C') {
        output << toPrint.getMonth() << " ";
        output << toPrint.getYear() << " ";
        output << toPrint.getActor() << endl;
    }
    return output;
}