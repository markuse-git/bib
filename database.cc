#include <iostream>
#include <string>
#include "database.h"

Database::Database(const std::string &db_name) {
    if (sqlite3_open(db_name.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }
}

Database::~Database() {
    if (db) {
        sqlite3_close(db);
    }
}

bool Database::execute_query(const std::string &query) {
    char *errMsg = nullptr;
    std::cout << "Executing query (db.cc): " << query << std::endl; // Debug-Ausgabe
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
