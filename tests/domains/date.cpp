#include "date.hpp"

void UTDate::runTests() {
    Date dates[5];

    try {
        for (int i = 0; i < 5;  i++) {
            int* date = validDates[i];
            dates[i].setDate(date[0], date[1], date[2]);
        }
        passed++;
        report.push_back("Set valid dates - SUCCESS");
    } catch (invalid_argument&) {
        report.push_back("Set valid dates - FAILURE");
    }

    try {
        for (int i = 0; i < 5; i++) {
            string date = dates[i].getDate();
            int day = dates[i].getDay();
            int month = dates[i].getMonth();
            int year = dates[i].getYear();

            if (date != formattedDates[i] || day  != validDates[i][0] ||
                month != validDates[i][1] || year != validDates[i][2])
                throw;
        }
        passed++;
        report.push_back("Get date in various formats - SUCCESS");
    } catch(...) {
        report.push_back("Get date in various formats - FAILURE");
    }

    for (int i = 0; i < 5; i++) {
        try {
            int* date = invalidDates[i];
            dates[i].setDate(date[0], date[1], date[2]);
            report.push_back("Throw \"invalid_argument\" error when setting invalid date - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throw \"invalid_argument\" error when setting invalid date - SUCCESS");
}

