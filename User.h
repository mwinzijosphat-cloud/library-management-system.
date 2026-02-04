#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    std::string name;
    std::string userID;
    std::vector<Book*> borrowedBooks;

public:
    User(std::string n, std::string id);
    bool borrowBook(Book* book);
    bool returnBook(Book* book);
    void viewBorrowedBooks() const;
    std::string getUserID() const;
};

#endif
