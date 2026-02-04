#include "User.h"
#include <iostream>

User::User(std::string n, std::string id) : name(n), userID(id) {}

bool User::borrowBook(Book* book) {
    if (book->borrowBook()) {
        borrowedBooks.push_back(book);
        return true;
    }
    return false;
}

bool User::returnBook(Book* book) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == book) {
            book->returnBook();
            borrowedBooks.erase(it);
            return true;
        }
    }
    return false;
}

void User::viewBorrowedBooks() const {
    std::cout << "Borrowed books by " << name << ":\n";
    if (borrowedBooks.empty()) {
        std::cout << "None\n";
    } else {
        for (auto b : borrowedBooks) {
            std::cout << b->getDetails() << std::endl;
        }
    }
}

std::string User::getUserID() const {
    return userID;
}
