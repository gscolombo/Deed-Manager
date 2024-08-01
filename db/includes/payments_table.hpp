#ifndef DB_PAYMENTS_TABLE_HPP_INCLUDED
#define DB_PAYMENTS_TABLE_HPP_INCLUDED

#include "database.hpp"
#include "query_database.hpp"

class PaymentsTable: public Database, public IQUeryDatabase {
    private:
        static int populate(void*, int, char**, char**);
    public:
        PaymentsTable() : Database() {};
        ~PaymentsTable() {};

        void add(map<string,string>&);
        void update(map<string,string>&);
        void get(map<string,string>&);
        void del(map<string,string>&);

        Response getResult() const;
        int getStatus() const;
        string getLog() const;
};

inline Response PaymentsTable::getResult() const {
    return result;
}

inline int PaymentsTable::getStatus() const {
    return status;
}

inline string PaymentsTable::getLog() const {
    return (string) log;
}

#endif // DB_PAYMENTS_TABLE_HPP_INCLUDED
