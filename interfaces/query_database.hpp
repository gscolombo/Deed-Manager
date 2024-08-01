#ifndef INTERFACES_QUERY_DATABASE_HPP_INCLUDED
#define INTERFACES_QUERY_DATABASE_HPP_INCLUDED

#include <map>
#include <string>
#include <list>
#include "account.hpp"
#include "deed.hpp"
#include "payment.hpp"

using namespace std;

struct Response {
    list<Account> accounts = {};
    list<Deed> deeds = {};
    list<Payment> payments = {};
};

class IQUeryDatabase {
    protected:
        Response result;
    public:
        virtual void add(map<string,string>&) = 0;
        virtual void update(map<string,string>&) = 0;
        virtual void get(map<string,string>&) = 0;
        virtual void del(map<string,string>&) = 0;

        virtual Response getResult() const = 0;
        virtual int getStatus() const = 0;
        virtual string getLog() const = 0;

        virtual ~IQUeryDatabase() {};
};

#endif // INTERFACES_QUERY_DATABASE_HPP_INCLUDED
