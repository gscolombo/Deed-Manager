#ifndef DB_DEEDS_TABLE_HPP_INCLUDED
#define DB_DEEDS_TABLE_HPP_INCLUDED

#include "database.hpp"
#include "query_database.hpp"
#include "account.hpp"

class DeedsTable: public Database, public IQUeryDatabase {
    private:
        static int populate(void*, int, char**, char**);
    public:
        DeedsTable() : Database() {};
        ~DeedsTable() {};

        void add(map<string,string>&);
        void update(map<string,string>&);
        void get(map<string,string>&);
        void del(map<string,string>&);

        Response getResult() const;
        int getStatus() const;
        string getLog() const;
};

inline Response DeedsTable::getResult() const {
    return result;
}

inline int DeedsTable::getStatus() const {
    return status;
}

inline string DeedsTable::getLog() const {
    return (string) log;
}


#endif // DB_DEEDS_TABLE_HPP_INCLUDED
