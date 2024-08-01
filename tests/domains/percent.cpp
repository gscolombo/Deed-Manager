#include "percent.hpp"

void UTPercent::runTests() {
    Percent percents[10];

    try {
        for (int i = 0; i < 10; i++) {
            percents[i].setValue(validPercents[i]);
        }
        passed++;
        report.push_back("Set valid percents - SUCCESS");
    } catch(invalid_argument&) {
        report.push_back("Set valid percents - FAILURE");
    }

    try {
        for (int i = 0; i < 10; i++) {
            if (percents[i].getValue() != validPercents[i] ||
                percents[i].getFormattedValue() != formattedPercents[i])
                throw 0;
        }
        passed++;
        report.push_back("Get percents - SUCCESS   ");
    } catch (...) {
        report.push_back("Get percents - FAILURE");
    }

    for (int i = 0; i < 10; i++) {
        try {
            percents[i].setValue(invalidPercents[i]);
            report.push_back("Throws \"invalid_argument\" exception when saving invalid percent - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throws \"invalid_argument\" exception when saving invalid percent - SUCCESS");
}
