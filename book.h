#pragma once

#include <string>

class Book{
    public:
        Book(int id, std::string title, std::string author, std::string isbn);
        std::string get_author() const;
        std::string get_title() const;
        std::string get_isbn() const;
        int get_id() const;
        bool get_is_available() const;
        void borrow();
        void return_book();
    private:
        int id;
        std::string title;
        std::string author;
        std::string isbn;
        bool is_available;
};