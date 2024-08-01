#ifndef DOMAINS_TEST_PAYMENT_CODE_HPP_INCLUDED
#define DOMAINS_TEST_PAYMENT_CODE_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/payment_code.hpp"

class UTPaymentCode : public UnitTest {
    private:
            string validPaymentCodes[5] = {
                "24287393", "32152807", "55197662", "87322894", "67768438"
            };

            string invalidPaymentCodes[5] = {
                "batata", "1231233A", "11111111111", "1.1.1.1.1", "02436364"
            };

    public:
            UTPaymentCode(){
                setID("Payment code domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_PAYMENT_CODE_HPP_INCLUDED
