#ifndef SERVICES_PAYMENT_OPERATIONS_HPP_INCLUDED
#define SERVICES_PAYMENT_OPERATIONS_HPP_INCLUDED

#include "interfaces/operations/payment_operations.hpp"
#include "payments_table.hpp"

class PaymentOperations: public IPaymentOperations {
    private:
        IQUeryDatabase* paymentsTable;
    public:
        PaymentOperations() { paymentsTable = new PaymentsTable; }
        ~PaymentOperations() { delete paymentsTable; };

        Payment get(list<Payment>&, int) const;
        bool create(Deed&, map<string,string>&);
        list<string> read(Payment&) const;
        bool update(Deed&, map<string,string>&);
        bool del(map<string,string>&);
        list<Payment> listing(Deed&);
};

#endif // SERVICES_PAYMENT_OPERATIONS_HPP_INCLUDED
