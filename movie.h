#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
using namespace std;

class Movie {

public:
    Movie();
    Movie(char, int, string, string, int);

    char getGenre() const;
    void setGenre(char);

    int getStock() const;
    void setStock(int);

    string getDirector() const;
    void setDirector(string);

    string getTitle() const;
    void setTitle(string);

    int getYear() const;
    void setYear(int);

    string trim(string);

    virtual void printMovie() const;

protected:
    char genre;
    int stock;
    string director;
    string title;
    int year;
};

#endif