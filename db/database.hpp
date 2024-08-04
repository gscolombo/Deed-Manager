#ifndef DB_DATABASE_HPP_INCLUDED
#define DB_DATABASE_HPP_INCLUDED

#include <sqlite3.h>

#include <iostream>
using namespace std;

/**
 * @class Database
 * @brief Class representing a database connection.
 *
 * This class provides a connection to the SQLite database used by the application.
 * It is responsible for opening and closing the database connection.
 */
class Database {
    protected:
        /**
         * @brief SQLite database connection.
         */
        sqlite3* connection;
        /**
         * @brief Status of the SQLite database connection.
         */
        int status;
        /**
         * @brief SQLite database log.
         */
        const char* log;
        /**
         * @brief SQLite database error message.
         */
        char* error = nullptr;
    public:
        /**
         * @brief Constructor.
         *
         * This constructor opens a connection to the SQLite database.
         */
        Database() {
            status = sqlite3_open("db/manager.db", &connection);
            status = sqlite3_exec(connection, "PRAGMA foreign_keys = ON;", 0, 0, 0);
        };
        /**
         * @brief Destructor.
         *
         * This destructor closes the SQLite database connection.
         */
        ~Database() { sqlite3_close(connection); };
};

#endif // DB_DATABASE_HPP_INCLUDED
