#include <string>

#include "user.h"

User::User(int id, const std::string &name, const std::string &email)
: id{id}, name{name}, email{email}{

}

int User::get_id() const{
    return id;
}

std::string User::get_name() const{
    return name;
}

std::string User::get_email() const{
    return email;
}