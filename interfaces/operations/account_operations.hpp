#ifndef INTERFACES_ACCOUNT_OPERATIONS_HPP_INCLUDED
#define INTERFACES_ACCOUNT_OPERATIONS_HPP_INCLUDED

#include <list>

#include "account.hpp"

/**
 * @class IAccountOperations
 * @brief Abstract class for account operations.
 * 
 * This interface defines the operations that can be performed on an user's account.
 */
class IAccountOperations {
protected:
    /**
     * @brief `Account` instance to hold the new user account data
     */
    Account account;

    /**
     * @brief Information to be showed for the user.
     */
    string info;
public:
    /**
     * @brief Read the account data.
     * @param account The account to be read.
     * @return A list of strings containing the account data.
     */
    virtual list<string> read(Account& account) const = 0;

    /**
     * @brief Update the account data.
     * @param account The account to be updated.
     * @param data The new data for the account.
     * @return True if the update is successful, false otherwise.
     */
    virtual bool update(Account& account, map<string, string>& data) = 0;

    /**
     * @brief Delete the account.
     * @param account The account to be deleted.
     * @return True if the deletion is successful, false otherwise.
     */
    virtual bool del(Account& account) = 0;

    /**
     * @brief Get the `Account` object used by the implementation.
     * @return The `Account` object.
     */
    Account getAccount() const;

    /**
     * @brief Get the information to be shown to the user.
     * @return The information string.
     */
    string getInfo() const;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IAccountOperations() {};
};

inline Account IAccountOperations::getAccount() const {
    return account;
}

inline string IAccountOperations::getInfo() const {
    return info;
}


#endif // INTERFACES_ACCOUNT_OPERATIONS_HPP_INCLUDED
