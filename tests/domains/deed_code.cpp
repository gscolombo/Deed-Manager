#include "deed_code.hpp"

void UTDeedCode::runTests() {
    if (deedCodeTypes == DeedCode::types) {
        passed++;
        report.push_back("Deed code static types listing is valid - SUCCESS");
    } else {
        report.push_back("Deed code static types listing is valid - FAILURE");
    }

    try {
        for (int i = 0; i < 6; i++) {
            DeedCode deedCodeFromIndex;
            DeedCode deedCodeFromType;

            deedCodeFromIndex.setDeedCode(validDeedCodes[i], i);
            deedCodeFromType.setDeedCode(validDeedCodes[i], deedCodeTypes[i]);
        }
        passed++;
        report.push_back("Deed code can be instantiated by type and index - SUCCESS");
    } catch (invalid_argument&) {
        report.push_back("Deed code can be instantiated by type and index - FAILURE");
    }

    for (string code : invalidDeedCodes) {
        try {
            DeedCode deedCode;
            deedCode.setDeedCode(code, 0);
            report.push_back("Throw \"invalid_argument\" when setting invalid deed code - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }

    passed++;
    report.push_back("Throw \"invalid_argument\" when setting invalid deed code - SUCCESS");
}
