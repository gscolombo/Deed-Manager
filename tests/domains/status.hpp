#ifndef DOMAINS_TEST_STATUS_HPP_INCLUDED
#define DOMAINS_TEST_STATUS_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/status.hpp"

#include <algorithm>

class UTStatus : public UnitTest {
    private:
            vector<string> l = { "Previsto", "Liquidado", "Inadimplente" };
    public:
            UTStatus(){
                setID("Status domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_STATUS_HPP_INCLUDED
