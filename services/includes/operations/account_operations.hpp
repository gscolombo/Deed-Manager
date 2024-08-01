#ifndef SERVICES_ACCOUNT_OPERATIONS_HPP_INCLUDED
#define SERVICES_ACCOUNT_OPERATIONS_HPP_INCLUDED

#include "interfaces/operations/account_operations.hpp"
#include "accounts_table.hpp"

class AccountOperations: public IAccountOperations {
    private:
        IQUeryDatabase* IQuery;
    public:
        AccountOperations()
        {
            IQUeryDatabase* p_IQuery = new AccountsTable();
            setQueryDBInterface(p_IQuery);
        }
        ~AccountOperations() { delete IQuery; };

        list<string> read(Account&) const;
        bool update(Account&, map<string,string>&);
        bool del(Account&);

        void setQueryDBInterface(IQUeryDatabase*);
};

inline void AccountOperations::setQueryDBInterface(IQUeryDatabase* IQuery) {
    this->IQuery = IQuery;
}

#endif // SERVICES_ACCOUNT_OPERATIONS_HPP_INCLUDED
