#ifndef INTERFACES_QUERY_DATABASE_HPP_INCLUDED
#define INTERFACES_QUERY_DATABASE_HPP_INCLUDED

#include <map>
#include <string>
#include <list>
#include "account.hpp"
#include "deed.hpp"
#include "payment.hpp"

using namespace std;

/**
 * @struct Response
 * @brief Struct representing a database response.
 *
 * This struct contains three lists: `accounts`, `deeds`, and `payments`.
 * Each list contains the corresponding database entries retrieved from a \b SELECT operation.
 */
struct Response {
    /**
     * @brief A list of `Account` objects representing accounts.
     */
    list<Account> accounts = {};

    /**
     * @brief A list of `Deed` objects representing deeds.
     */
    list<Deed> deeds = {};

    /**
     * @brief A list of `Payment` objects representing payments.
     */
    list<Payment> payments = {};
};

/**
 * @class IQueryDatabase
 * @brief Abstract class for operations related with database querying.
 *
 * This interface provides functions for adding, updating, deleting and
 * retrieving data from a database.
 */
class IQueryDatabase {
    protected:
        /**
         * @brief The result of the last \b SELECT operation.
         */
        Response result;

    public:
        /**
         * @brief Adds data to the database.
         * @param data The data to be added.
         */
        virtual void add(map<string,string>& data) = 0;

        /**
         * @brief Updates data in the database.
         * @param data The data to be updated along with key values.
         */
        virtual void update(map<string,string>& data) = 0;

        /**
         * @brief Retrieves data from the database.
         * @param data The data to be used as filters for querying.
         */
        virtual void get(map<string,string>& data) = 0;

        /**
         * @brief Deletes data from the database.
         * @param data The data containing the keys to guide deletion.
         */
        virtual void del(map<string,string>& data) = 0;

        /**
         * @brief Gets the result of the last operation.
         * @return The result of the last \b SELECT operation.
         */
        virtual Response getResult() const = 0;

        /**
         * @brief Gets the status of the last operation.
         * @return The status of the last operation.
         */
        virtual int getStatus() const = 0;

        /**
         * @brief Gets the log of the last operation.
         * @return The log of the last operation.
         */
        virtual string getLog() const = 0;

        /**
         * @brief Destructor.
         */
        virtual ~IQueryDatabase() {};
};

#endif // INTERFACES_QUERY_DATABASE_HPP_INCLUDED
