#ifndef ENTITIES_TEST_ACCOUNT_HPP_INCLUDED
#define ENTITIES_TEST_ACCOUNT_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../entities/account.hpp"

class UTAccount : public UnitTest {
    private:
            string cpfs[3] = { "66652842718", "27313385986", "71358564493" };
            string names[3] = { "Roberto Costa", "Daniela Moraes", "Bob Esponja" };
            string passwords[3] = { "124659", "543167", "764821" };
            string formattedCPFs[3] = { "666.528.427-18", "273.133.859-86", "713.585.644-93" };
    public:
            UTAccount(){
                setID("Account entity test");
                total = 1;
            }
            void runTests();
};

#endif // ENTITIES_TEST_ACCOUNT_HPP_INCLUDED
