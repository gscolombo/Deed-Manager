#ifndef DB_ACCOUNTS_TABLE_HPP_INCLUDED
#define DB_ACCOUNTS_TABLE_HPP_INCLUDED

#include "database.hpp"
#include "query_database.hpp"
#include "account.hpp"
#include <vector>

class AccountsTable: public Database, public IQUeryDatabase {
    private:
        static int populate(void*, int, char**, char**);
    public:
        AccountsTable() : Database() {};
        ~AccountsTable() {};

        void add(map<string,string>&);
        void update(map<string,string>&);
        void get(map<string,string>&);
        void del(map<string,string>&);

        Response getResult() const;
        int getStatus() const;
        string getLog() const;
};

inline Response AccountsTable::getResult() const {
    return result;
}

inline int AccountsTable::getStatus() const {
    return status;
}

inline string AccountsTable::getLog() const {
    return (string) log;
}

#endif // DB_ACCOUNTS_TABLE_HPP_INCLUDED
