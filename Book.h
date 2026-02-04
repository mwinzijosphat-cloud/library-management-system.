#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;

public:
    Book(std::string t, std::string a, std::string i);
    std::string getDetails() const;
    bool borrowBook();
    void returnBook();
    bool getAvailability() const;
    std::string getISBN() const;
};

#endif
