#include <iostream>
#include "library.h"
#include "book.h"
#include "user.h"

int main() {
    Library library("library.db");

    // Benutzer hinzufügen
    User user1(1, "John Doe", "john@example.com");
    library.add_user(user1);

    // Bücher hinzufügen
    Book book1(1, "first book", "markus", "12345678");
    library.add_book(book1);

    // Buch ausleihen
    // library.borrow_book(1, 1);

    // Buch zurückgeben
    // library.return_book(1, 1);

    // Benutzer entfernen
    // library.remove_user(1);

    // Buch entfernen
    // library.remove_book(1);

    std::cout << "Program finished successfully" << std::endl;
    return 0;
}
