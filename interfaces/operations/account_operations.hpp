#ifndef INTERFACES_ACCOUNT_OPERATIONS_HPP_INCLUDED
#define INTERFACES_ACCOUNT_OPERATIONS_HPP_INCLUDED

#include <list>

#include "account.hpp"

class IAccountOperations {
    public:
        virtual list<string> read(Account&) const = 0;
        virtual bool update(Account&, map<string,string>&) = 0;
        virtual bool del(Account&) = 0;
        virtual ~IAccountOperations() {};

        Account account;
        string info;
};


#endif // INTERFACES_ACCOUNT_OPERATIONS_HPP_INCLUDED
