#pragma once

#include <sqlite3.h>
#include <string>


class Database{
    private:
        sqlite3 *db;
        std::string db_name;
    public:
        Database(const std::string &db_name);
        ~Database();
        bool execute_query(const std::string &query);
};