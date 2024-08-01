#ifndef UNIT_TEST_CPF_HPP_INCLUDED
#define UNIT_TEST_CPF_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/cpf.hpp"

class UTCPF : public UnitTest {
    private:
            string validCPFs[5] = {
                "24287393872", "32152807529", "55197662905", "87322898125", "67768438051"
            };

            string formattedCPFs[5] = {
                "242.873.938-72", "321.528.075-29", "551.976.629-05", "873.228.981-25", "677.684.380-51"
            };

            string invalidCPFs[7] = {
                "batata", "1231233", "11111111112", "1.1.1.1.1", "--1-1-1", "32152807523", "67768438011"
            };
    public:
            UTCPF() {
                setID("CPF domain test");
                total = 3;
            }
            void runTests();
};

#endif // UNIT_TEST_CPF_HPP_INCLUDED
