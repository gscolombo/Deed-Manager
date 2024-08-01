#ifndef DOMAINS_TEST_DEED_CODE_HPP_INCLUDED
#define DOMAINS_TEST_DEED_CODE_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/deed_code.hpp"

class UTDeedCode : public UnitTest {
    private:
            vector<string> deedCodeTypes = { "CDB", "CRA", "CRI", "LCA", "LCI", "DEB" };
            string validDeedCodes[6] = {"1234ABCD", "31AC12GT", "9483AR32", "22321423", "KW13SXA1", "LL1W2XS1"};
            string formattedDeedCodes[6] = {"CDB1234ABCD", "CRA31AC12GT", "CRI9483AR32", "LCA22321423", "LCIKW13SXA1", "DEBLL1W2XS1"};
            string invalidDeedCodes[6] = {"aaaa", "0213", "AAAA", "23-232.23", "0.0001", "@@@ASD123"};
    public:
            UTDeedCode(){
                setID("Deed code domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_DEED_CODE_HPP_INCLUDED
