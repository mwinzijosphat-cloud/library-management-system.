#include "Book.h"
#include <sstream>

Book::Book(std::string t, std::string a, std::string i)
    : title(t), author(a), ISBN(i), isAvailable(true) {}

std::string Book::getDetails() const {
    std::ostringstream oss;
    oss << "Title: " << title << ", Author: " << author
        << ", ISBN: " << ISBN << ", Available: " << (isAvailable ? "Yes" : "No");
    return oss.str();
}

bool Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        return true;
    }
    return false;
}

void Book::returnBook() {
    isAvailable = true;
}

bool Book::getAvailability() const {
    return isAvailable;
}

std::string Book::getISBN() const {
    return ISBN;
}
