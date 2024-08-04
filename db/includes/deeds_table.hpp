#ifndef DB_DEEDS_TABLE_HPP_INCLUDED
#define DB_DEEDS_TABLE_HPP_INCLUDED

#include "database.hpp"
#include "query_database.hpp"
#include "account.hpp"

/**
 * @class DeedsTable
 * @brief Class representing a deed table in the database.
 *
 * This class inherits from the Database class and implements the IQueryDatabase
 * interface for query-related operations. 
 */
class DeedsTable: public Database, public IQueryDatabase {
    private:
        /**
         * @brief Callback function for populating a list of `Deed` objects from database rows.
         *
         * This function is called by the `sqlite3_exec` function to populate
         * a list of `Deed` objects from database rows with the data retrieved 
         * from the database.
         *
         * @param data Pointer to a list of `Deed` objects 
         * @param argc Number of columns in the result set.
         * @param argv Pointer to the array of column values.
         * @param cols Pointer to the array of column names.
         * @return Integer indicating the success or failure of the operation.
         */
        static int populate(void*, int, char**, char**);
    public:
        /**
         * @brief Constructor for the DeedsTable class.
         *
         * Initializes the DeedsTable object.
         */
        DeedsTable() : Database() {};

        /**
         * @brief Destructor for the DeedsTable class.
         *
         * Deallocates any resources used by the DeedsTable object.
         */
        ~DeedsTable() {};

        /**
         * @brief Adds a deed to the database.
         *
         * @param deed Map containing data to create a deed.
         */
        void add(map<string,string>&);

        /**
         * @brief Updates a deed in the database.
         *
         * @param deed Map containing data to update a deed.
         */
        void update(map<string,string>&);

        /**
         * @brief Retrieves a deed from the database.
         *
         * @param deed Map containing data to retrieve a deed.
         */
        void get(map<string,string>&);

        /**
         * @brief Deletes a deed from the database.
         *
         * @param deed Map containing  data to delete a deed.
         */
        void del(map<string,string>&);

        /**
         * @brief Retrieves the result of the last operation.
         *
         * @return The result object containing the result of the last operation.
         */
        Response getResult() const;

        /**
         * @brief Retrieves the status of the last operation.
         *
         * @return The status code of the last operation.
         */
        int getStatus() const;

        /**
         * @brief Retrieves the log message of the last operation.
         *
         * @return The log message of the last operation.
         */
        string getLog() const;
};

inline Response DeedsTable::getResult() const {
    return result;
}

inline int DeedsTable::getStatus() const {
    return status;
}

inline string DeedsTable::getLog() const {
    return (string) log;
}


#endif // DB_DEEDS_TABLE_HPP_INCLUDED
