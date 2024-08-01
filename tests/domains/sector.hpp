#ifndef DOMAINS_TEST_SECTOR_HPP_INCLUDED
#define DOMAINS_TEST_SECTOR_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/sector.hpp"

#include <algorithm>

class UTSector : public UnitTest {
    private:
            const vector<string> l = {
                "Agricultura", "Construção Civil", "Energia",
                "Finanças", "Imobiliário", "Papel e celulose",
                "Pecuária", "Química e petroquímica",
                "Metalurgia e siderurgia", "Mineração"
            };
    public:
            UTSector() {
                setID("Sector domain test");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_SECTOR_HPP_INCLUDED
