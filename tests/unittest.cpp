#include "unittest.hpp"

void UnitTest::setID(string s) {
    id = s;
};

void UnitTest::showReport() {
    cout << "/****************************************************************************/" << endl;
    cout << "// " << getID() << " //" << endl << endl;
    runTests();

    for(string entry: report){
        cout << "> " << entry << endl;
    }
    cout << endl << passed << " out of " << total << " tests passed." << endl << endl;
    cout << "/****************************************************************************/" << endl << endl;
}
