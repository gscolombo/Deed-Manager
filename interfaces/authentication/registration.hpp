#ifndef INTERFACES_REGISTRATION_HPP_INCLUDED
#define INTERFACES_REGISTRATION_HPP_INCLUDED

#include "account.hpp"
#include <map>

/**
 * @class IRegistration
 * @brief Abstract class for registration functionalities.
 * 
 * This interface defines the operations that can be performed to register a new user.
*/
class IRegistration {
    protected:
        /**
         * @brief `Account` instance to hold the new user account data.
         */
        Account account;

        /**
         * @brief Information to be showed for the user.
         */
        string info;
    public:
        /**
         * @brief Create an account with the given credentials.
         * @param credentials The user credentials.
         * @return `true` if account creation is successful, `false` otherwise.
         */
        virtual bool createAccount(map<string,string>& credentials) = 0;

        /**
         * @brief Validate the user input credentials.
         * @param name The user name as a `Name` object.
         * @param cpf The user CPF as a `CPF` object.
         * @param password The user password as a `Password` object.
         * @param credentials Credentials given by user's input.
         * @return `true` if credentials are valid, `false` otherwise.
         */
        virtual bool validateInput(Name& name, CPF& cpf, Password& password, map<string,string>& credentials) = 0;

        /**
         * @brief Virtual destructor
         */
        virtual ~IRegistration() {};
    
        /**
         * @brief Get the `Account` object used by the implementation.
         * @return The `Account` object.
         */
        Account getAccount() const;

        /**
         * @brief Get the information to be shown for the user.
         * @return The information string.
         */
        string getInfo() const;
};


inline Account IRegistration::getAccount() const {
    return account;
}

inline string IRegistration::getInfo() const {
    return info;
}


#endif // INTERFACES_REGISTRATION_HPP_INCLUDED
