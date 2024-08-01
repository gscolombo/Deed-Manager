#include "name.hpp"

void UTName::runTests() {
    Name names[10];

    auto toCapital = [](string& str) {
        for(char c: str.substr(1)) { c = tolower(c); };
        return (char)toupper(str[0]) + str.substr(1);
    };

    try {
        for (int i = 0; i < 10; i++) {
            names[i].setNames(validNames[i]);
        }
        passed++;
        report.push_back("Set valid names - SUCCESS");
    } catch(invalid_argument&) {
        report.push_back("Set valid names - FAILURE");
    }

    try {
        for (int i = 0; i < 10; i++) {
            vector<string> terms = split(validNames[i], " ");
            string firstName = toCapital(terms[0]);
            string secondName = terms[1] != "" ? toCapital(terms[1]) : terms[1];
            string fullName = terms[0] + " " + terms[1];

            if (names[i].getNames()[0] != firstName ||
                names[i].getNames()[1] != secondName ||
                names[i].getFullName() != fullName)
                throw 0;
        }
        passed++;
        report.push_back("Get valid names formatted - SUCCESS");
    } catch(...) {
        report.push_back("Get valid names formatted - FAILURE");
    }

    for (int i = 0; i < 10; i++) {
        try {
            names[i].setNames(invalidNames[i]);
            report.push_back("Throw \"invalid_argument\" error when setting invalid name - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throw \"invalid_argument\" error when setting invalid date - SUCCESS");
}
