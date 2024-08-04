#ifndef SERVICES_REGISTRATION_HPP_INCLUDED
#define SERVICES_REGISTRATION_HPP_INCLUDED

#include "authentication/registration.hpp"
#include "accounts_table.hpp"

/**
 * @class RegisterUser
 * @brief This class is used to register a new user account.
 *
 * The class represents an implementation of the IRegistration interface.
 * It uses the `AccountsTable` class to interact with the database table
 * `accounts`.
 *
 * The class constructor initializes a new instance of the `AccountsTable`
 * class and sets it as the query interface for the class.
 *
 * The class destructor deletes the query interface object.
 *
 * The class provides two methods: `createAccount` and `validateInput`.
 * The `createAccount` method is responsible for creating a new user account.
 * The `validateInput` method is used to validate the input data for the
 * account registration.
 *
 * The `setQueryDBInterface` method is used to set the query interface
 * object for the class.
 *
 * @sa IRegistration
 * @sa AccountsTable
 */
class RegisterUser: public IRegistration {
    private:
        /**
         * The query interface object for the class.
         */
        IQueryDatabase* IQuery;
    public:
        /**
         * Default constructor.
         *
         * Initializes a new instance of the `AccountsTable` class
         * and sets it as the query interface for the class.
         */
        RegisterUser()
        {
            IQueryDatabase* p_IQuery = new AccountsTable();
            setQueryDBInterface(p_IQuery);
        }
        /**
         * Destructor.
         *
         * Deletes the query interface object.
         */
        ~RegisterUser() { delete IQuery; };

        /**
         * Creates a new user account.
         *
         * @param data The map containing the account data.
         * @return `True` if the account was created successfully,
         *         `False` otherwise.
         */
        bool createAccount(map<string,string>&);

        /**
         * Validates the input data for the account registration.
         *
         * @param name A `Name` instance to validate the user's name.
         * @param cpf A `CPF` instance to validate the user's CPF..
         * @param password A `Password` instance to validate the user's password.
         * @param data The map containing the account data.
         * @return `True` if the input data is valid, `False` otherwise.
         */
        bool validateInput(Name&, CPF&, Password&, map<string,string>&);

        /**
         * Sets the query interface object for the class.
         *
         * @param IQuery The query interface object pointer.
         */
        void setQueryDBInterface(IQueryDatabase*);
};

inline void RegisterUser::setQueryDBInterface(IQueryDatabase* IQuery) {
    this->IQuery = IQuery;
}

#endif // SERVICES_REGISTRATION_HPP_INCLUDED
