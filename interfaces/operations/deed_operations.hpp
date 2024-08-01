#ifndef INTERFACES_DEED_OPERATIONS_HPP_INCLUDED
#define INTERFACES_DEED_OPERATIONS_HPP_INCLUDED

#include "query_database.hpp"

#include "account.hpp"
#include "deed.hpp"

class IDeedOperations {
    public:
        virtual bool create(Account&, map<string,string>&) = 0;
        virtual list<string> read(Deed&) const = 0;
        virtual bool update(Account&, map<string,string>&) = 0;
        virtual bool del(map<string,string>&) = 0;
        virtual list<Deed> listing(Account&) = 0;
        virtual Deed get(list<Deed>&, int) const = 0;

        virtual ~IDeedOperations() {};

        string info;
};

#endif // INTERFACES_DEED_OPERATIONS_HPP_INCLUDED
