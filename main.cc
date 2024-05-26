#include <iostream>
#include "library.h"
#include "book.h"
#include "user.h"

int main() {
    Library library("library.db");

    // Benutzer hinzufügen
    User user2(2, "Hans Hartz", "hans@hartz.de");
    library.add_user(user2);

    // Bücher hinzufügen
    Book book2(2, "second book", "Ursula Pitchi", "23456789");
    library.add_book(book2);

    // Buch ausleihen
    // library.borrow_book(2, 2);

    // Buch zurückgeben
    library.return_book(2, 2);

    // Benutzer entfernen
    // library.remove_user(1);

    // Buch entfernen
    // library.remove_book(1);

    std::cout << "Program finished successfully" << std::endl;
    return 0;
}
