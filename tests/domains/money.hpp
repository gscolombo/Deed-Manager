#ifndef DOMAINS_TEST_MONEY_HPP_INCLUDED
#define DOMAINS_TEST_MONEY_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/money.hpp"

#include <random>
#include <utility>

using namespace std;

class UTMoney : public UnitTest {
    private:
            pair<double,string> refs[9] = {
                {50, "R$ 50,00"}, {230, "R$ 230,00"}, {57392, "R$ 57.392,00"},
                {23.10, "R$ 23,10"}, {8903.23, "R$ 8.903,23"}, {1000000, "R$ 1.000.000,00"},
                {394293.325, "R$ 394.293,33"}, {0.23, "R$ 0,23"}, {0.68924, "R$ 0,69"}
            };

    public:
            UTMoney(){
                setID("Money domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_MONEY_HPP_INCLUDED
