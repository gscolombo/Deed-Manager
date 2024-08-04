#ifndef DB_ACCOUNTS_TABLE_HPP_INCLUDED
#define DB_ACCOUNTS_TABLE_HPP_INCLUDED

#include "database.hpp"
#include "query_database.hpp"
#include "account.hpp"
#include <vector>

/**
 * @class AccountsTable
 * @brief This class represents a table of accounts in the database.
 *
 * The class extends the `Database` class to provide a table of accounts in the
 * database. It implements the `IQueryDatabase` interface to interact with the
 * database.
 */
class AccountsTable: public Database, public IQueryDatabase {
    private:
        /**
         * @brief Populates a list of `Account` objects from database rows.
         *
         * This static method populates a list of `Account` objects from database rows.
         * It is used as a callback function for the `sqlite3_exec` function.
         *
         * @param data Pointer to a list of `Account` objects.
         * @param argc The number of columns in the row.
         * @param argv An array of strings representing the values in the row.
         * @param columnName An array of strings representing the column names.
         * @return An integer representing the status of the operation.
         */
        static int populate(void*, int, char**, char**);
    public:
        /**
         * @brief Constructs a new AccountsTable object.
         *
         * This constructor initializes a new instance of the AccountsTable class.
         */
        AccountsTable() : Database() {};

        /**
         * @brief Destructs a AccountsTable object.
         *
         * This destructor deletes the query interface object.
         */
        ~AccountsTable() {};

        /**
         * @brief Adds a new account to the table.
         * @param data The data containing the new account information.
         */
        void add(map<string,string>&);

        /**
         * @brief Updates an existing account in the table.
         * @param data The data to use to update the account.
         */
        void update(map<string,string>&);

        /**
         * @brief Gets information about an existing account in the table.
         * @param data The data to use to get the account information.
         */
        void get(map<string,string>&);

        /**
         * @brief Removes an account from the table.
         * @param data The data to use to remove the account.
         */
        void del(map<string,string>&);

        /**
         * @brief Gets the result of the last operation.
         * @return The result of the last operation.
         */
        Response getResult() const;

        /**
         * @brief Gets the status of the last operation.
         * @return The status of the last operation.
         */
        int getStatus() const;

        /**
         * @brief Gets the log of the last operation.
         * @return The log string of the last operation.
         */
        string getLog() const;
};

inline Response AccountsTable::getResult() const {
    return result;
}

inline int AccountsTable::getStatus() const {
    return status;
}

inline string AccountsTable::getLog() const {
    return (string) log;
}

#endif // DB_ACCOUNTS_TABLE_HPP_INCLUDED
