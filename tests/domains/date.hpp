#ifndef DOMAINS_TEST_DATE_HPP_INCLUDED
#define DOMAINS_TEST_DATE_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../domains/date.hpp"

class UTDate : public UnitTest {
    private:
            int validDates[5][3] = {
                {21, 3, 2000}, {14, 9, 2050}, {1, 12, 2074}, {31, 12, 2001}, {29, 2, 2024}
            };

            string formattedDates[5]= {
                "21-03-2000", "14-09-2050", "01-12-2074", "31-12-2001", "29-02-2024"
            };

            int invalidDates[5][3] = {
                {21, 3, 1932}, {-14, 9, 2050}, {1, 13, 2074}, {31, 2, 2001}, {29, 2, 2100}
            };
    public:
            UTDate() {
                setID("Date domain tests");
                total = 3;
            }
            void runTests();
};

#endif // DOMAINS_TEST_DATE_HPP_INCLUDED
