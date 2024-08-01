#ifndef DOMAINS_TEST_PASSWORD_HPP_INCLUDED
#define DOMAINS_TEST_PASSWORD_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/password.hpp"

class UTPassword : public UnitTest {
    private:
            string validPasswords[5] = {
                "124356", "134287", "983521", "874592", "879032"
            };

            string invalidPasswords[5] = {
                "012312", "1231233", "111111", "123456", "654321"
            };
    public:
            UTPassword(){
                setID("Password domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_PASSWORD_HPP_INCLUDED
