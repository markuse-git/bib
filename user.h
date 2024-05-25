#pragma once

#include <string>


class User{
    public:
        User(int id, const std::string &name, const std::string &email);
        int get_id() const;
        std::string get_name() const;
        std::string get_email() const;
    private:
        int id;
        std::string name;
        std::string email;
};