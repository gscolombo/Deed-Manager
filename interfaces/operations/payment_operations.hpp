#ifndef INTERFACE_PAYMENT_OPERATIONS_HPP_INCLUDED
#define INTERFACE_PAYMENT_OPERATIONS_HPP_INCLUDED

#include "query_database.hpp"

#include "account.hpp"
#include "deed.hpp"
#include "payment.hpp"

class IPaymentOperations {
    public:
        virtual Payment get(list<Payment>&, int) const = 0;
        virtual bool create(Deed&, map<string,string>&) = 0;
        virtual list<string> read(Payment&) const = 0;
        virtual bool update(Deed&, map<string,string>&) = 0;
        virtual bool del(map<string,string>&) = 0;
        virtual list<Payment> listing(Deed&) = 0;

        virtual ~IPaymentOperations() {};

        string info;
};

#endif // INTERFACE_PAYMENT_OPERATIONS_HPP_INCLUDED
