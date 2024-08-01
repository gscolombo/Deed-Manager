#include "account.hpp"

void UTAccount::runTests() {
    try {
        for (int i = 0; i < 3; i++) {
            Account account(cpfs[i], names[i], passwords[i]);
            if (account.getCPF() == formattedCPFs[i] &&
                account.getName() == names[i] &&
                account.getPassword() == passwords[i])
                continue;
            throw 0;
        }
        passed++;
        report.push_back("Instantiante account entity - SUCCESS");
    } catch(...) {
        report.push_back("Instantiante account entity - FAILURE");
    }
}
