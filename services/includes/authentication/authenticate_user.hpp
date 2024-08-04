#ifndef SERVICES_AUTHENTICATE_USER_HPP_INCLUDED
#define SERVICES_AUTHENTICATE_USER_HPP_INCLUDED

#include "authentication/authentication.hpp"
#include "accounts_table.hpp"

/**
 * @class AuthenticateUser
 * @brief This class is used to authenticate a user.
 *
 * The class represents an implementation of the IAuthentication interface.
 * It uses the `AccountsTable` class to interact with the database table
 * `accounts`.
 *
 * The class constructor initializes a new instance of the `AccountsTable`
 * class and sets it as the query interface for the class.
 *
 * The class destructor deletes the query interface object.
 *
 * The class provides two methods: `authenticate` and `validateCredentials`.
 * The `authenticate` method is responsible for authenticating a user.
 * The `validateCredentials` method is used to validate the user's
 * credentials.
 *
 * The `setQueryDBInterface` method is used to set the query interface
 * object for the class.
 *
 * @sa IAuthentication
 * @sa AccountsTable
 */
class AuthenticateUser: public IAuthentication {
    private:
        /**
         * The query interface object for the class.
         */
        IQueryDatabase* IQuery;
    public:
        /**
         * Default constructor.
         *
         * Initializes a new instance of the AccountsTable class
         * and sets it as the query interface for the class.
         */
        AuthenticateUser()
        {
            IQueryDatabase* p_IQuery = new AccountsTable();
            setQueryDBInterface(p_IQuery);
        }

        /**
         * Destructor.
         *
         * Deletes the query interface object.
         */
        ~AuthenticateUser() { delete IQuery; };

        /**
         * Authenticates a user.
         *
         * @param data The user's credentials for authentication.
         * @return `True` if the user is authenticated, `false` otherwise.
         */
        bool authenticate(map<string,string>&);

        /**
         * Validates the user's credentials.
         *
         * @param cpf A `CPF` instance to validate the user's CPF.
         * @param password A `Password` instance to validate the user's password.
         * @param data The user's credentials.
         * @return `True` if the credentials are valid, `false` otherwise.
         */
        bool validateCredentials(CPF&, Password&, map<string,string>&);

        /**
         * Sets the query interface object for the class.
         *
         * @param IQuery The query interface object pointer.
         */
        void setQueryDBInterface(IQueryDatabase*);
};

inline void AuthenticateUser::setQueryDBInterface(IQueryDatabase* IQuery) {
    this->IQuery = IQuery;
}

#endif // SERVICES_AUTHENTICATE_USER_HPP_INCLUDED
