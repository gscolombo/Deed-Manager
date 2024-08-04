#ifndef DOMAINS_PAYMENT_CODE_HPP_INCLUDED
#define DOMAINS_PAYMENT_CODE_HPP_INCLUDED

#include "../includes/alphanumerical_code.hpp"

#include <ctype.h>

/**
 * @class PaymentCode
 * @brief Class for payment code domain representation.
*/
class PaymentCode : public AlphanumericalCode {
    private:
            /**
             * @brief Check if codes is 8 digits string with first digit different than 0.
             * @param code Reference to code string to be validated.
             * @throw invalid_argument If payment code is invalid.
            */
            void validate(string&) const;
    public:
            /**
             * @brief Set payment code if valid.
             * @param code Reference to code string to be set.
             * @throw invalid_argument If payment code is invalid.
            */
            void setPaymentCode(string&);
};

#endif // DOMAINS_PAYMENT_CODE_HPP_INCLUDED
