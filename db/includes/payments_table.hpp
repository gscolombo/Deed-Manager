#ifndef DB_PAYMENTS_TABLE_HPP_INCLUDED
#define DB_PAYMENTS_TABLE_HPP_INCLUDED

#include "database.hpp"
#include "query_database.hpp"


/**
 * @class PaymentsTable
 * @brief Class representing a payments table in the database.
 *
 * This class inherits from the Database class and implements the IQueryDatabase
 * interface for query-related operations.
 */
class PaymentsTable: public Database, public IQueryDatabase {
    private:
        /**
         * @brief Callback function for populating a list of `Payment` objects from database rows.
         *
         * This function is called by the `sqlite3_exec` function to populate
         * a list of `Payment` objects from database rows with the data retrieved 
         * from the database.
         *
         * @param data Pointer to a list of `Payment` objects 
         * @param argc Number of columns in the result set.
         * @param argv Pointer to the array of column values.
         * @param cols Pointer to the array of column names.
         * @return Integer indicating the success or failure of the operation.
         */
        static int populate(void*, int, char**, char**);
    public:
        /**
         * @brief Constructor for the PaymentsTable class.
         *
         * Initializes the PaymentsTable object.
         */
        PaymentsTable() : Database() {};

        /**
         * @brief Destructor for the PaymentsTable class.
         *
         * Deallocates any resources used by the `PaymentsTable` object.
         */
        ~PaymentsTable() {};

        /**
         * @brief Adds a payment to the database.
         *
         * @param payment Map containing data to create a payment.
         */
        void add(map<string,string>&);

        /**
         * @brief Updates a payment in the database.
         *
         * @param payment Map containing data to update a payment.
         */
        void update(map<string,string>&);

        /**
         * @brief Retrieves a payment from the database.
         *
         * @param payment Map containing data to retrieve a payment.
         */
        void get(map<string,string>&);

        /**
         * @brief Deletes a payment from the database.
         *
         * @param payment Map containing data to delete a payment.
         */
        void del(map<string,string>&);

        /**
         * @brief Gets the result of the last operation.
         *
         * @return The result of the last operation.
         */
        Response getResult() const;

        /**
         * @brief Gets the status of the last operation.
         *
         * @return The status of the last operation.
         */
        int getStatus() const;

        /**
         * @brief Gets the log of the last operation.
         *
         * @return The log of the last operation.
         */
        string getLog() const;
};

inline Response PaymentsTable::getResult() const {
    return result;
}

inline int PaymentsTable::getStatus() const {
    return status;
}

inline string PaymentsTable::getLog() const {
    return (string) log;
}

#endif // DB_PAYMENTS_TABLE_HPP_INCLUDED
