#ifndef DB_DATABASE_HPP_INCLUDED
#define DB_DATABASE_HPP_INCLUDED

#include <sqlite3.h>

#include <iostream>
using namespace std;

class Database {
    protected:
        sqlite3* connection;
        int status;
        const char* log;
        char* error = nullptr;
        static int populate(void*, int, char**, char**);
    public:
        Database(const Database&);
        Database operator=(const Database&);
        Database()
        {
            status = sqlite3_open("db/manager.db", &connection);
            status = sqlite3_exec(connection, "PRAGMA foreign_keys = ON;", 0, 0, 0);
        };
        ~Database() { sqlite3_close(connection); };
};

#endif // DB_DATABASE_HPP_INCLUDED
