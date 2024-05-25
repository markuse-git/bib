#pragma once

#include "database.h"
#include "book.h"
#include "user.h"

#include <string>
#include <vector>


class Library{
    public:
        Library(const std::string &db_name);
        void add_book(const Book &book);
        void remove_book(int book_id);
        void borrow_book(int book_id, int user_id);
        void return_book(int book_id, int user_id);

        void add_user(const User &user);
        void remove_user(int user_id);
    private:
        Database db;
        std::vector<Book> books;
        std::vector<User> users;
};