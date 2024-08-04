#ifndef INTERFACE_PAYMENT_OPERATIONS_HPP_INCLUDED
#define INTERFACE_PAYMENT_OPERATIONS_HPP_INCLUDED

#include "query_database.hpp"

#include "account.hpp"
#include "deed.hpp"
#include "payment.hpp"

/**
 * @class IPaymentOperations
 * @brief Abstract class for payment related operations.
 *
 * This interface defines the operations that can be performed on a user's payment.
 */
class IPaymentOperations {
    protected:
        /**
         * @brief Information to be showed for the user.
         */
        string info;
    public:
        /**
         * @brief Get a payment from a list of payments.
         * @param payments The list of payments.
         * @param index The index of the payment to be retrieved.
         * @return The payment at the given index.
         */
        virtual Payment get(list<Payment>& payments, int index) const = 0;
        /**
         * @brief Create a payment for the given deed.
         * @param deed The deed for which the payment will be created.
         * @param data The data for the new payment.
         * @return `true` if payment creation is successful, `false` otherwise.
         */
        virtual bool create(Deed& deed, map<string,string>& data) = 0;
        /**
         * @brief Read the data of a payment.
         * @param payment The payment to be read.
         * @return A list of strings containing the payment data.
         */
        virtual list<string> read(Payment& payment) const = 0;
        /**
         * @brief Update the data of a payment.
         * @param deed The deed associated with the payment.
         * @param data The data to update the payment.
         * @return `true` if the update is successful, `false` otherwise.
         */
        virtual bool update(Deed& deed, map<string,string>& data) = 0;
        /**
         * @brief Delete a payment.
         * @param data The data with the keys of the payment to be deleted.
         * @return `true` if the deletion is successful, `false` otherwise.
         */
        virtual bool del(map<string,string>& data) = 0;
        /**
         * @brief List the payments of a deed.
         * @param deed The deed for which the payments will be listed.
         * @return A list of payments.
         */
        virtual list<Payment> listing(Deed& deed) = 0;

        /**
         * @brief Destructor.
         */
        virtual ~IPaymentOperations() {};

        /**
         * @brief Get information to be showed for the user.
         * @return The information string
         */
        string getInfo() const;
};

inline string IPaymentOperations::getInfo() const {
    return info;
}

#endif // INTERFACE_PAYMENT_OPERATIONS_HPP_INCLUDED
