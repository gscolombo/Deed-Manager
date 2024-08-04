#ifndef SERVICES_PAYMENT_OPERATIONS_HPP_INCLUDED
#define SERVICES_PAYMENT_OPERATIONS_HPP_INCLUDED

#include "interfaces/operations/payment_operations.hpp"
#include "payments_table.hpp"

/**
 * @class PaymentOperations
 * @brief Implements the IPaymentOperations interface.
 *
 * This class implements the IPaymentOperations interface. It handles
 * operations related to payments.
 */
class PaymentOperations: public IPaymentOperations {
    private:
        /// @brief Instance of the PaymentsTable class.
        IQueryDatabase* paymentsTable;
    public:
        /**
         * @brief Constructor.
         *
         * Initializes the paymentsTable instance.
         */
        PaymentOperations() { paymentsTable = new PaymentsTable; }

        /**
         * @brief Destructor.
         *
         * Deletes the paymentsTable instance.
         */
        ~PaymentOperations() { delete paymentsTable; };

        /**
         * @brief Retrieves a payment from a list of payments.
         *
         * @param payments The list of payments.
         * @param index The index of the payment to be retrieved.
         * @return The payment at the given index.
         */
        Payment get(list<Payment>&, int) const;

        /**
         * @brief Creates a payment for the given deed.
         *
         * @param deed The deed for which the payment will be created.
         * @param data The data for the new payment.
         * @return `true` if payment creation is successful, `false` otherwise.
         */
        bool create(Deed&, map<string,string>&);

        /**
         * @brief Reads the data of a payment.
         *
         * @param payment The payment to be read.
         * @return A list of strings containing the payment data.
         */
        list<string> read(Payment&) const;

        /**
         * @brief Updates the data of a payment.
         *
         * @param deed The deed associated with the payment.
         * @param data The data to update the payment.
         * @return `true` if the update is successful, `false` otherwise.
         */
        bool update(Deed&, map<string,string>&);

        /**
         * @brief Deletes a payment.
         *
         * @param data The data with the keys of the payment to be deleted.
         * @return `true` if the deletion is successful, `false` otherwise.
         */
        bool del(map<string,string>&);

        /**
         * @brief Lists the payments of a deed.
         *
         * @param deed The deed for which the payments will be listed.
         * @return A list of payments.
         */
        list<Payment> listing(Deed&);
};

#endif // SERVICES_PAYMENT_OPERATIONS_HPP_INCLUDED
