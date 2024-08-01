#ifndef SERVICES_DEED_OPERATIONS_HPP_INCLUDED
#define SERVICES_DEED_OPERATIONS_HPP_INCLUDED

#include "interfaces/operations/deed_operations.hpp"
#include "deeds_table.hpp"

class DeedOperations: public IDeedOperations {
    private:
        IQUeryDatabase* deedsTable;
    public:
        DeedOperations() { deedsTable = new DeedsTable; }
        ~DeedOperations() { delete deedsTable; };

        bool create(Account&, map<string,string>&);
        list<string> read(Deed&) const;
        bool update(Account&, map<string,string>&);
        bool del(map<string,string>&);
        list<Deed> listing(Account&);
        Deed get(list<Deed>&, int) const;
};

#endif // SERVICES_DEED_OPERATIONS_HPP_INCLUDED
