#include <iostream>
#include "Book.h"
#include "User.h"
#include "Library.h"

using namespace std;

int main() {
    Library lib;

    Book b1("C++ Primer", "Lippman", "12345");
    Book b2("Clean Code", "Martin", "54321");
    lib.addBook(b1);
    lib.addBook(b2);

    User u1("Julius", "U001");
    lib.registerUser(u1);

    cout << "--- Library Demo ---\n";

    Book* found = lib.searchBook("12345");
    if (found) cout << "Found: " << found->getDetails() << endl;

    User* user = lib.findUser("U001");
    if (user && found) {
        user->borrowBook(found);
        user->viewBorrowedBooks();
        user->returnBook(found);
        user->viewBorrowedBooks();
    }

    cout << "--- End of Demo ---\n";
    return 0;
}
