#ifndef ENTITIES_TEST_PAYMENT_HPP_INCLUDED
#define ENTITIES_TEST_PAYMENT_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../entities/payment.hpp"
#include "../../domains/status.hpp"

class UTPayment : public UnitTest {
    private:
            // Class instantiation arguments
            string codes[3] = { "24687493", "55123762", "87362894", };
            tuple<int,int,int> dates[3] = { {3,5,2024}, {23,2,2057}, {9,6,2033} };
            double percents[3] = { 53.87, 89.323, 0.452 };
            int status[3] = {0, 1, 2};

            // Getters models
            string formattedDates[3] = { "03-05-2024", "23-02-2057", "09-06-2033" };
            string formattedPercents[3] = { "53,87%", "89,32%", "0,45%" };

            bool checkGetters(Payment, int);
    public:
            UTPayment(){
                setID("Payment entity test");
                total = 1;
            }
            void runTests();
};


#endif // ENTITIES_TEST_PAYMENT_HPP_INCLUDED
