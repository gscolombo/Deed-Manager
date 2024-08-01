#ifndef TESTS_HPP_INCLUDED
#define TESTS_HPP_INCLUDED

#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<string, int(*)()> TestCase;

class UnitTest {
    private:
            string id;
    protected:
            int passed = 0, total;
            vector<string> report;
    public:
            virtual void runTests() = 0;
            void setID(string);
            string getID() const;
            void showReport();
};

inline string UnitTest::getID() const {
    return id;
};


#endif // TESTS_HPP_INCLUDED
