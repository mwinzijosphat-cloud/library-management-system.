#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const Book& book);
    bool removeBook(const std::string& ISBN);
    Book* searchBook(const std::string& keyword);
    void registerUser(const User& user);
    User* findUser(const std::string& userID);
};

#endif
