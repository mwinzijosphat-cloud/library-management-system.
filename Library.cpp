#include "Library.h"

void Library::addBook(const Book& book) {
    books.push_back(book);
}

bool Library::removeBook(const std::string& ISBN) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getISBN() == ISBN) {
            books.erase(it);
            return true;
        }
    }
    return false;
}

Book* Library::searchBook(const std::string& keyword) {
    for (auto& b : books) {
        if (b.getISBN() == keyword) return &b;
    }
    return nullptr;
}

void Library::registerUser(const User& user) {
    users.push_back(user);
}

User* Library::findUser(const std::string& userID) {
    for (auto& u : users) {
        if (u.getUserID() == userID) return &u;
    }
    return nullptr;
}
