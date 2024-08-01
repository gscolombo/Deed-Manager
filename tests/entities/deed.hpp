#ifndef ENTITIES_TEST_DEED_HPP_INCLUDED
#define ENTITIES_TEST_DEED_HPP_INCLUDED

#include "../unittest.hpp"
#include "../../entities/deed.hpp"
#include "../../domains/sector.hpp"

class UTDeed : public UnitTest {
    private:
            // Class instantiation arguments
            tuple<string, int> deedsFromIndex[3] = {
                {"1234ABCD", 3}, {"KW13SXA1", 1}, {"9483AR32", 5},
            };

            tuple<string, string> deedsFromType[3] = {
                {"1234ABCD", DeedCode::types[3]}, {"KW13SXA1", DeedCode::types[1]}, {"9483AR32", DeedCode::types[5]},
            };

            string names[3] = { "Roberto Costa", "Daniela Moraes", "Bob Esponja" };
            int sectors[3] = {3, 1, 5};
            tuple<int,int,int> emissionDates[3] = { {3,5,2024}, {23,2,2057}, {9,6,2033} };
            tuple<int,int,int> expirationDates[3] = { {3,8,2074}, {16,5,2050}, {20,7,2089} };
            double values[3] = { 40.23, 90.10, 0.50 };

            // Getters models
            string formattedEmissionDates[3] = { "03-05-2024", "23-02-2057", "09-06-2033" };
            string formattedExpirationDates[3] = { "03-08-2074", "16-05-2050", "20-07-2089" };
            string formattedValues[3] = { "R$ 40,23", "R$ 90,10", "R$ 0,50" };

            bool checkGetters(Deed, int, bool);
    public:
            UTDeed(){
                setID("Deed entity test");
                total = 1;
            }
            void runTests();
};

#endif // ENTITIES_TEST_DEED_HPP_INCLUDED
