#include "password.hpp"

void UTPassword::runTests() {
    Password passwords[5];

    try {
        for (int i = 0; i < 5; i++) {
            passwords[i].setPassword(validPasswords[i]);
        }
        passed++;
        report.push_back("Save valid passwords - SUCCESS");
    } catch(invalid_argument&) {
        report.push_back("Save valid passwords - FAILURE");
    }

    try {
        for (int i = 0; i < 5; i++) {
            if (passwords[i].getPassword() != validPasswords[i])
                throw 0;
        }
        passed++;
        report.push_back("Get passwords - SUCCESS");
    } catch(...) {
        report.push_back("Get passwords - FAILURE");
    }

    for (int i = 0; i < 5; i++) {
        try {
            passwords[i].setPassword(invalidPasswords[i]);
            report.push_back("Throws \"invalid_argument\" exception when saving invalid passwords - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throws \"invalid_argument\" exception when saving invalid passwords - SUCCESS");
}
