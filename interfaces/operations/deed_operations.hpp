#ifndef INTERFACES_DEED_OPERATIONS_HPP_INCLUDED
#define INTERFACES_DEED_OPERATIONS_HPP_INCLUDED

#include "query_database.hpp"

#include "account.hpp"
#include "deed.hpp"

/**
 * @class IDeedOperations
 * @brief Abstract class for deed related operations.
 * 
 * This interface defines the operations that can be performed on a user's deed.
 */
class IDeedOperations {
    protected:
        /**
         * @brief Information to be showed for the user.
         */
        string info;
    public:
        /**
         * @brief Create a deed for the given account.
         * @param account The account for which the deed will be created.
         * @param data The data for the new deed.
         * @return `true` if deed creation is successful, `false` otherwise.
         */
        virtual bool create(Account& account, map<string,string>& data) = 0;

        /**
         * @brief Read the data of a deed.
         * @param deed The deed to be read.
         * @return A list of strings containing the deed data.
         */
        virtual list<string> read(Deed& deed) const = 0;

        /**
         * @brief Update the data of a deed.
         * @param account The account associated with the deed.
         * @param data The data to update the deed.
         * @return true if the update is successful, false otherwise.
         */
        virtual bool update(Account& account, map<string,string>& data) = 0;

        /**
         * @brief Delete a deed.
         * @param data The data with the keys of the deed to be deleted.
         * @return true if the deletion is successful, false otherwise.
         */
        virtual bool del(map<string,string>& data) = 0;

        /**
         * @brief List the deeds of an account.
         * @param account The account for which the deeds will be listed.
         * @return A list of deeds.
         */
        virtual list<Deed> listing(Account& account) = 0;

        /**
         * @brief Get a deed from a list of deeds.
         * @param deeds The list of deeds.
         * @param index The index of the deed to be retrieved.
         * @return The deed at the given index.
         */
        virtual Deed get(list<Deed>& deeds, int index) const = 0;

        /**
         * @brief Virtual destructor.
         */
        virtual ~IDeedOperations() {};

        /**
         * @brief Get the information to be shown to the user.
         * @return The information string.
         */
        string getInfo() const;
};

inline string IDeedOperations::getInfo() const {
    return info;
}

#endif // INTERFACES_DEED_OPERATIONS_HPP_INCLUDED
