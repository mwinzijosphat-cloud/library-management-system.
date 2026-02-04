#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i), isAvailable(true) {}
    // Getters
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return isbn; }
    bool getAvailability() { return isAvailable; }
    // Setters
    void setAvailability(bool avail) { isAvailable = avail; }
};

class User {
private:
    string name;
    vector<Book*> borrowedBooks;

public:
    User(string n) : name(n) {}
    // Getters
    string getName() { return name; }
    vector<Book*> getBorrowedBooks() { return borrowedBooks; }
    // Borrow/Return
    void borrowBook(Book* book) {
        if (book->getAvailability()) {
            borrowedBooks.push_back(book);
            book->setAvailability(false);
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }
    void returnBook(Book* book) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (*it == book) {
                borrowedBooks.erase(it);
                book->setAvailability(true);
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "You didn't borrow this book." << endl;
    }
};

class Library {
private:
    vector<Book*> books;
    vector<User*> users;

public:
    // Book management
    void addBook(Book* book) { books.push_back(book); }
    void removeBook(Book* book) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (*it == book) {
                books.erase(it);
                delete book;
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
    Book* searchByTitle(string title) {
        for (Book* book : books) {
            if (book->getTitle() == title) {
                return book;
            }
        }
        return nullptr;
    }
    Book* searchByAuthor(string author) {
        for (Book* book : books) {
            if (book->getAuthor() == author) {
                return book;
            }
        }
        return nullptr;
    }
    // User management
    void addUser(User* user) { users.push_back(user); }
    // Display
    void displayBooks() {
        for (Book* book : books) {
            cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", Available: " << (book->getAvailability() ? "Yes" : "No") << endl;
        }
    }
};

// Test cases
void runTests() {
    Library lib;
    Book* book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "1234567890");
    Book* book2 = new Book("1984", "George Orwell", "0987654321");
    User* user1 = new User("John Doe");

    // Test 1: Add and display books
    lib.addBook(book1);
    lib.addBook(book2);
    cout << "Test 1: Display books" << endl;
    lib.displayBooks();

    // Test 2: Search by title
    cout << "\nTest 2: Search by title" << endl;
    Book* foundBook = lib.searchByTitle("1984");
    if (foundBook) {
        cout << "Found: " << foundBook->getTitle() << endl;
    } else {
        cout << "Book not found." << endl;
    }

    // Test 3: Borrow book
    cout << "\nTest 3: Borrow book" << endl;
    user1->borrowBook(book1);
    lib.displayBooks();

    // Test 4: Return book
    cout << "\nTest 4: Return book" << endl;
    user1->returnBook(book1);
    lib.displayBooks();

    // Test 5: Search by author
    cout << "\nTest 5: Search by author" << endl;
    foundBook = lib.searchByAuthor("F. Scott Fitzgerald");
    if (foundBook) {
        cout << "Found: " << foundBook->getTitle() << endl;
    } else {
        cout << "Book not found." << endl;
    }

    // Cleanup
    lib.removeBook(book1);
    lib.removeBook(book2);
    delete user1;
}

int main() {
    runTests();
    return 0;
}
