#include "payment_code.hpp"

void UTPaymentCode::runTests() {
    PaymentCode paymentCode[5];
    try {
        for (int i = 0; i < 5; i++) {
            paymentCode[i].setPaymentCode(validPaymentCodes[i]);
        }
        passed++;
        report.push_back("Set valid payment codes - SUCCESS");
    } catch(invalid_argument&) {
        report.push_back("Set valid payment codes - FAILURE");
    }

    try {
        for (int i = 0; i < 5; i++) {
            if (paymentCode[i].getCode() != validPaymentCodes[i])
                throw 0;
        }
        passed++;
        report.push_back("Get payment codes - SUCCESS");
    } catch (...) {
        report.push_back("Get payment codes - FAILURE");
    }

    for (int i = 0; i < 5; i++) {
        try {
            paymentCode[i].setPaymentCode(invalidPaymentCodes[i]);
            report.push_back("Throws \"invalid_argument\" exception when saving invalid payment code - FAILURE");
            return;
        } catch(invalid_argument&) {
            continue;
        }
    }
    passed++;
    report.push_back("Throws \"invalid_argument\" exception when saving invalid payment code - SUCCESS");
}
