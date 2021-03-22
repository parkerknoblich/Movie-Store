#include "movie.h"

Movie::Movie() {
    setGenre('\0');
    setStock(0);
    setDirector("");
    setTitle("");
    setYear(0);
}

//Movie::Movie(char genre, int stock, string director, string title, int year) {
//    setGenre(genre);
//    setStock(stock);
//    setDirector(director);
//    setTitle(title);
//    setYear(year);
//}

char Movie::getGenre() const {
    return genre;
}

void Movie::setGenre(char genre) {
    this->genre = genre;
}

int Movie::getStock() const {
    return stock;
}

void Movie::setStock(int stock) {
    this->stock = stock;
}

string Movie::getDirector() const {
    return director;
}

void Movie::setDirector(string director) {
    this->director = director;
}

string Movie::getTitle() const {
    return title;
}

void Movie::setTitle(string title) {
    this->title = title;
}

int Movie::getYear() const {
    return year;
}

void Movie::setYear(int year) {
    this->year = year;
}

string Movie::trim(string token) {
    while (!token.empty() && isspace(token.back())) {
        token.pop_back();
    }
    size_t pos = 0;
    while (pos < token.size() && isspace(token[pos])) {
        ++pos;
    }
    return token.substr(pos);
}

void Movie::printMovie() const {
    cout << getStock() << ", ";
    cout << getDirector() << ", ";
    cout << getTitle() << ", ";
    cout << getYear() << endl;
}