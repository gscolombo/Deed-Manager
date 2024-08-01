#ifndef DOMAINS_TEST_PERCENT_HPP_INCLUDED
#define DOMAINS_TEST_PERCENT_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/percent.hpp"

class UTPercent : public UnitTest {
    private:
            double validPercents[10] = {
                0, 0.00001, 54, 0.23, 100, 0.76, 45, 1.93, 0.89, 67
            };

            string formattedPercents[10] = {
                "0%", "0,00001%", "54%", "0,23%", "100%", "0,76%", "45%", "1,93%", "0,89%", "67%"
            };

            double invalidPercents[10] = {
                -1, -12, 1.7e+308, 100.00001, 1000, 7612, 10*1000, 0101010, 323.123, -1.7e-308
            };
    public:
            UTPercent(){
                setID("Percent domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_PERCENT_HPP_INCLUDED
