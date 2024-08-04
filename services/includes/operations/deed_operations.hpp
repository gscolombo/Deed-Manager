#ifndef SERVICES_DEED_OPERATIONS_HPP_INCLUDED
#define SERVICES_DEED_OPERATIONS_HPP_INCLUDED

#include "interfaces/operations/deed_operations.hpp"
#include "deeds_table.hpp"

/**
 * @class DeedOperations
 * @brief Class for deed operations.
 * 
 * This class implements the IDeedOperations interface for deed related
 * operations. It uses the DeedsTable class to communicate with the
 * database.
 */
class DeedOperations: public IDeedOperations {
    private:
        /**
         * @brief Pointer to the query database.
         */
        IQueryDatabase* deedsTable;
    public:
        /**
         * @brief Constructor.
         * 
         * Initializes the deedsTable pointer with a new instance of DeedsTable.
         */
        DeedOperations() { deedsTable = new DeedsTable; }
        /**
         * @brief Destructor.
         * 
         * Deletes the deedsTable pointer.
         */
        ~DeedOperations() { delete deedsTable; };

        /**
         * @brief Create a deed for the given account.
         * @param account The account for which the deed will be created.
         * @param data The data for the new deed.
         * @return `true` if deed creation is successful, `false` otherwise.
         */
        bool create(Account& account, map<string,string>& data);
        
        /**
         * @brief Read the data of a deed.
         * @param deed The deed to be read.
         * @return A list of strings containing the deed data.
         */
        list<string> read(Deed& deed) const;

        /**
         * @brief Update the data of a deed.
         * @param account The account associated with the deed.
         * @param data The data to update the deed.
         * @return `true` if the update is successful, `false` otherwise.
         */
        bool update(Account& account, map<string,string>& data);

        /**
         * @brief Delete a deed.
         * @param data The data with the keys of the deed to be deleted.
         * @return `true` if the deletion is successful, `false` otherwise.
         */
        bool del(map<string,string>& data);

        /**
         * @brief List the deeds of an account.
         * @param account The account for which the deeds will be listed.
         * @return A list of deeds.
         */
        list<Deed> listing(Account& account);

        /**
         * @brief Get a deed from a list of deeds.
         * @param deeds The list of deeds.
         * @param index The index of the deed to be retrieved.
         * @return The deed at the given index.
         */
        Deed get(list<Deed>&, int) const;
};

#endif // SERVICES_DEED_OPERATIONS_HPP_INCLUDED
