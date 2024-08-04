#ifndef SERVICES_ACCOUNT_OPERATIONS_HPP_INCLUDED
#define SERVICES_ACCOUNT_OPERATIONS_HPP_INCLUDED

#include "interfaces/operations/account_operations.hpp"
#include "accounts_table.hpp"

/**
 * @class AccountOperations
 * @brief This class represents an implementation of the IAccountOperations
 * interface.
 *
 * The class uses the AccountsTable class to interact with the database table
 * `accounts`.
 *
 * The class constructor initializes a new instance of the AccountsTable class
 * and sets it as the query interface for the class.
 *
 * The class destructor deletes the query interface object.
 *
 * The class provides three methods: `read`, `update` and `del`.
 * The `read` method is used to read information about an account.
 * The `update` method is used to update an account's information.
 * The `del` method is used to remove an account from the database.
 *
 * @sa IAccountOperations
 * @sa AccountsTable
 */
class AccountOperations: public IAccountOperations {
    private:
        /// The query interface object pointer for the class.
        IQueryDatabase* IQuery;
    public:
        /**
         * Default constructor.
         *
         * Initializes a new instance of the AccountsTable class
         * and sets it as the query interface for the class.
         */
        AccountOperations()
        {
            IQueryDatabase* p_IQuery = new AccountsTable();
            setQueryDBInterface(p_IQuery);
        }
        /**
         * Destructor.
         *
         * Deletes the query interface object.
         */
        ~AccountOperations() { delete IQuery; };

        /**
         * Reads information about an account.
         *
         * @param account The account object to read.
         * @return A list of strings containing the account's information.
         */
        list<string> read(Account&) const;
        /**
         * Updates an account's information.
         *
         * @param account The account object to update.
         * @param data The data to update the account.
         * @return `True` if the update was successful, `False` otherwise.
         */
        bool update(Account&, map<string,string>&);
        /**
         * Removes an account from the database.
         *
         * @param account The account object to remove.
         * @return `True` if the deletion was successful, `False` otherwise.
         */
        bool del(Account&);

        /**
         * Sets the query interface object pointer for the class.
         *
         * @param IQuery The query interface object pointer.
         */
        void setQueryDBInterface(IQueryDatabase*);
};

inline void AccountOperations::setQueryDBInterface(IQueryDatabase* IQuery) {
    this->IQuery = IQuery;
}

#endif // SERVICES_ACCOUNT_OPERATIONS_HPP_INCLUDED
