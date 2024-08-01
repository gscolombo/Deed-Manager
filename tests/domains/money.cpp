#include "money.hpp"

void UTMoney::runTests() {
    Money money;
    default_random_engine generator;
    uniform_real_distribution<double> d1(0, 1000000);
    uniform_int_distribution<int> d2(1000001, 9999999);
    double n;

    try {
        for (int i = 0; i < 10; i++) {
            n = d1(generator);
            money.setValue(n);
        }
        passed++;
        report.push_back("Set valid money - SUCCESS");
    } catch (invalid_argument&) {
        report.push_back("Set valid money - FAILURE");
    }


    for (int i = 0; i < 10; i++) {
        try {
            n = d2(generator);
            money.setValue(n);
            report.push_back("Throw \"invalid_argument\" error when setting invalid value - FAILURE");
            break;
        } catch (invalid_argument& e) {
            continue;
        }
    }
    passed++;
    report.push_back("Throw \"invalid_argument\" error when setting invalid value - SUCCESS");

    try {
        for (pair<double, string> p: refs) {
            money.setValue(p.first);
            if (money.getFormattedValue() != p.second) {
                throw;
            }
        }
        passed++;
        report.push_back("Get formatted value - SUCCESS");
    } catch(...) {
        report.push_back("Get formatted value - FAILURE");
    }

}
