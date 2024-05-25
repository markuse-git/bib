#include <string>
#include <iostream>
#include "library.h"

Library::Library(const std::string &db_name) : db{db_name} {
    db.execute_query(
        "CREATE TABLE IF NOT EXISTS Books ("
        "ID INT PRIMARY KEY NOT NULL, "
        "TITLE TEXT NOT NULL, "
        "AUTHOR TEXT NOT NULL, "
        "ISBN TEXT NOT NULL, "
        "BORROWED INT NOT NULL);"
    );

    db.execute_query(
        "CREATE TABLE IF NOT EXISTS Users ("
        "ID INT PRIMARY KEY NOT NULL, "
        "NAME TEXT NOT NULL, "
        "EMAIL TEXT NOT NULL);"
    );

    db.execute_query(
        "CREATE TABLE IF NOT EXISTS BorrowedBooks ("
        "USER_ID INT NOT NULL, "
        "BOOK_ID INT NOT NULL, "
        "FOREIGN KEY(USER_ID) REFERENCES Users(ID), "
        "FOREIGN KEY(BOOK_ID) REFERENCES Books(ID));"
    );
}

void Library::add_book(const Book &book) {
    std::string query = "INSERT INTO Books (ID, TITLE, AUTHOR, ISBN, BORROWED) VALUES (" +
                        std::to_string(book.get_id()) + ", '" + book.get_title() + "', '" +
                        book.get_author() + "', '" + book.get_isbn() + "', " +
                        std::to_string(book.get_is_available()) + ");";
    std::cout << "Executing query (add_book): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to add book with ID " << book.get_id() << std::endl;
    }
}

void Library::remove_book(int book_id) {
    std::string query = "DELETE FROM Books WHERE ID = " + std::to_string(book_id) + ";";
    std::cout << "Executing query (remove_book): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to remove book with ID " << book_id << std::endl;
    }
}

void Library::return_book(int book_id, int user_id) {
    std::string query = "UPDATE Books SET BORROWED = 0 WHERE ID =" + std::to_string(book_id) + ";";
    std::cout << "Executing query (return_book): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to return book with ID " << book_id << std::endl;
    }
    query = "DELETE FROM BorrowedBooks WHERE USER_ID = " + std::to_string(user_id) + " AND BOOK_ID = " + std::to_string(book_id) + ";";
    std::cout << "Executing query (delete_borrowed_return): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to update BorrowedBooks table for book ID " << book_id << " and user ID " << user_id << std::endl;
    }
}

void Library::borrow_book(int book_id, int user_id) {
    std::string query = "UPDATE Books SET BORROWED = 1 WHERE ID =" + std::to_string(book_id) + ";";
    std::cout << "Executing query (borrow_book): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to borrow book with ID " << book_id << std::endl;
    }
    query = "INSERT INTO BorrowedBooks (USER_ID, BOOK_ID) VALUES (" + std::to_string(user_id) + ", " + std::to_string(book_id) + ");";
    std::cout << "Executing query (insert_borrowed_borrow): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to update BorrowedBooks table for book ID " << book_id << " and user ID " << user_id << std::endl;
    }
}

void Library::add_user(const User &user) {
    std::string query = "INSERT INTO Users (ID, NAME, EMAIL) VALUES(" +
                        std::to_string(user.get_id()) + ", '" + user.get_name() + "', '" +
                        user.get_email() + "');";
    std::cout << "Executing query (add_user): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to add user with ID " << user.get_id() << std::endl;
    }
}

void Library::remove_user(int user_id) {
    std::string query = "DELETE FROM Users WHERE ID = " + std::to_string(user_id) + ";";
    std::cout << "Executing query (remove_user): " << query << std::endl; // Debug-Ausgabe
    if (!db.execute_query(query)) {
        std::cerr << "Failed to remove user with ID " << user_id << std::endl;
    }
}
