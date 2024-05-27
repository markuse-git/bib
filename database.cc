#include <iostream>
#include <string>
#include "database.h"

Database::Database(const std::string &db_name) {
    // db_name.c_str() konvertiert db_name in einen C-String (const char*), da sqlite3_open einen C-String erwartet.
    // &db -> wird initialsiert, wenn Verbindung erfolgreich ist.
    // Die Funktion sqlite3_open gibt SQLITE_OK zurück, wenn die Verbindung erfolgreich ist 
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
    /*
    sqlite3_exec ist eine SQLite-Funktion, die die SQL-Abfrage query ausführt.
        db ist der Zeiger auf die Datenbankverbindung.
        query.c_str() wandelt den std::string in einen C-String (null-terminierter char-Array) um, den sqlite3_exec benötigt.
        Die nächsten beiden Parameter sind nullptr, da keine Callback-Funktionen benötigt werden, um Zeilen oder Ergebnisdaten zu verarbeiten.
        &errMsg ist ein Zeiger auf die Speicheradresse für Fehlermeldungen.
    Die Funktion gibt einen Fehlercode zurück. Wenn dieser nicht SQLITE_OK ist, bedeutet dies, dass ein Fehler aufgetreten ist.
    */
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
