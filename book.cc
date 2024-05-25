#include <string>

#include "book.h"



Book::Book(int id, std::string title, std::string author, std::string isbn)
: id{id}, title{title}, author{author}, isbn{isbn}, is_available{true}{

}

std::string Book::get_author() const{
    return author;
}

int Book::get_id() const{
    return id;
}

std::string Book::get_title() const{
    return title;
}

std::string Book::get_isbn() const{
    return isbn;
}

bool Book::get_is_available() const{
    return is_available;
}

void Book::borrow(){
    is_available = false;
}

void Book::return_book(){
    is_available = true;
}