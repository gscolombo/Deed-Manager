#include "sector.hpp"

void UTSector::runTests() {
    Sector sector;

    if (equal(Sector::sectors.begin(), Sector::sectors.end(), l.begin()) &&
        Sector::sectors.size() == 10) {
        passed++;
        report.push_back("Static listing of sectors - SUCCESS");
    } else {
        report.push_back("Static listing of sectors - FAILURE");
    }

    try {
        for (int i : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) {
            sector.setIndex(i);
            if (sector.getItem() != Sector::sectors[i])
                throw;
        }
        passed++;
        report.push_back("Set and get sector - SUCCESS");
    } catch(...) {
        report.push_back("Set and get sector - FAILURE");
    }

    for (int i: {10, 17, 40, 63, -1}) {
        try {
            sector.setIndex(i);
            report.push_back("Throws \"invalid_argument\" exception when setting invalid sector - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throws \"invalid_argument\" exception when setting invalid sector - SUCCESS");
}
