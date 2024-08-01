#include "status.hpp"

void UTStatus::runTests() {
    Status status;

    if (equal(Status::status.begin(), Status::status.end(), l.begin()) &&
        Status::status.size() == 3) {
        passed++;
        report.push_back("Static listing of status - SUCCESS");
    } else {
        report.push_back("Static listing of status - FAILURE");
    }

    try {
        for (int i : {0, 1, 2}) {
            status.setIndex(i);
            if (status.getItem() != Status::status[i])
                throw;
        }
        passed++;
        report.push_back("Set and get status - SUCCESS");
    } catch(...) {
        report.push_back("Set and get status - FAILURE");
    }

    for (int i: {10, 17, 40, 63, -1}) {
        try {
            status.setIndex(i);
            report.push_back("Throws \"invalid_argument\" exception when setting invalid status - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throws \"invalid_argument\" exception when setting invalid status - SUCCESS");
}
