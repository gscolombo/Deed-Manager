#ifndef INTERFACES_AUTHENTICATION_HPP_INCLUDED
#define INTERFACES_AUTHENTICATION_HPP_INCLUDED

#include "account.hpp"
#include <map>

/**
 * @class IAuthentication
 * @brief Abstract class for authentication functionalities.
 * 
 * This interface defines the operations that can be performed to authenticate a user.
 */
class IAuthentication {
    protected:
        /**
         * @brief `Account` instance to hold the logged user account data
         */
        Account account;
        /**
         * @brief Information to be showed for the user
         */
        string info;
    public:
        /**
         * @brief Authenticate the user
         * @param credentials The user credentials
         * @return `true` if authentication is successful, `false` otherwise
         */
        virtual bool authenticate(map<string,string>& credentials) = 0;

        /**
         * @brief Validate the user credentials
         * @param cpf The user CPF
         * @param password The user password
         * @param credentials Additional credentials
         * @return `true` if credentials are valid, `false` otherwise
         */
        virtual bool validateCredentials(CPF& cpf, Password& password, map<string,string>& credentials) = 0;

        /**
         * @brief Virtual destructor
         */
        virtual ~IAuthentication() {};

        
        /**
         * @brief Get the Account object used by the implementation.
         * @return The Account object.
         */
        Account getAccount() const;

        /**
         * @brief Get the information to be shown to the user.
         * @return The information string.
         */
        string getInfo() const;
};

inline Account IAuthentication::getAccount() const {
    return account;
}

inline string IAuthentication::getInfo() const {
    return info;
}


#endif // INTERFACES_AUTHENTICATION_HPP_INCLUDED
