#ifndef DOMAINS_TEST_NAME_HPP_INCLUDED
#define DOMAINS_TEST_NAME_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/name.hpp"

class UTName : public UnitTest {
    private:
            string validNames[10] = {
                "Gabriel Colombo", "Ana PAUla   ", "MariA AntONia", "   Samara", "   Fernando Antonio",
                "   Lucas alves ", "  roberto dantas   ", "luiz Nunes", "JoBSon CASTRO    ", "Roniel"
            };
            string invalidNames[10] = {
                "Jubiscleiton de Andrade", "Robisberto Roniscleitchon", "Shimishangas", "Dobibertoni Rocha", "Ra Ton",
                "00100101 111111", "愚蠢的外國人", "Ra Ta Tui", "Homem-Aranha", "R0B0C0P"
            };
    public:
            UTName(){
                setID("Name domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_NAME_HPP_INCLUDED
