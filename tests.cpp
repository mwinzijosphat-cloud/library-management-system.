#include <iostream>
#include <cassert>
#include "Book.h"
#include "User.h"
#include "Library.h"

void testBorrowAvailableBook() {
    Book b("C++ Primer", "Lippman", "12345");
    User u("Julius", "U001");
    assert(u.borrowBook(&b) == true);
    assert(b.getAvailability() == false);
    std::cout << "✅ testBorrowAvailableBook passed\n";
}

void testBorrowUnavailableBook() {
    Book b("Clean Code", "Martin", "54321");
    User u("Julius", "U001");
    u.borrowBook(&b);
    assert(u.borrowBook(&b) == false);
    std::cout << "✅ testBorrowUnavailableBook passed\n";
}

void testSearchBook() {
    Library lib;
    Book b("Algorithms", "Cormen", "11111");
    lib.addBook(b);
    assert(lib.searchBook("11111") != nullptr);
    assert(lib.searchBook("99999") == nullptr);
    std::cout << "✅ testSearchBook passed\n";
}

int main() {
    testBorrowAvailableBook();
    testBorrowUnavailableBook();
    testSearchBook();
    std::cout << "\nAll tests completed successfully!\n";
    return 0;
}
