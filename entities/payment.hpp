#ifndef ENTITIES_PAYMENT_HPP_INCLUDED
#define ENTITIES_PAYMENT_HPP_INCLUDED

#include "../domains/payment_code.hpp"
#include "../domains/percent.hpp"
#include "../domains/date.hpp"
#include "../domains/status.hpp"

#include <tuple>

/**
 * @class Payment
 * @brief Class for payment entity representation.
*/
class Payment {
    private:
        /**
         * @brief The code of the payment.
         */
        PaymentCode code;

        /**
         * @brief The date of the payment.
         */
        Date date;

        /**
         * @brief The percent of the payment.
         */
        Percent percent;

        /**
         * @brief The status of the payment.
         */
        Status status;
    public:
            /**
             * Constructor for the Payment class. Initializes the Payment object with the given code, date, percent, and status.
             *
             * @param code The code for the payment.
             * @param date The date of the payment as a tuple of integers representing day, month, and year, in that order.
             * @param percent The percent of the payment.
             * @param status The status of the payment as an integer corresponding to an index of the status list.
             */
            Payment(string code, tuple<int,int,int> date, double percent, int status)
            {
                this->code.setPaymentCode(code);
                this->date.setDate(get<0>(date), get<1>(date), get<2>(date));
                this->percent.setValue(percent);
                this->status.setIndex(status);
            }

            string getPaymentCode() const; ///< @brief Get payment code.
            string getDate() const; ///< @brief Get payment date.
            string getStatus() const; ///< @brief Get payment status.
            string getPercentual() const; ///< @brief Get payment percentual formatted.
            double getPercentualValue() const; ///< @brief Get payment percentual value.
};

inline string Payment::getPaymentCode() const {
    return code.getCode();
}

inline string Payment::getDate() const {
    return date.getDate();
}

inline string Payment::getStatus() const {
    return status.getItem();
}

inline string Payment::getPercentual() const {
    return percent.getFormattedValue();
}

inline double Payment::getPercentualValue() const {
    return percent.getValue();
}


#endif // ENTITIES_PAYMENT_HPP_INCLUDED
