#include "payment.hpp"

bool UTPayment::checkGetters(Payment payment, int i) {
    return  payment.getPaymentCode() == codes[i] &&
            payment.getDate() == formattedDates[i] &&
            payment.getStatus() == Status::status[status[i]] &&
            payment.getPercentual() == formattedPercents[i] &&
            payment.getPercentualValue() == percents[i];
}

void UTPayment::runTests() {
    try {
        for (int i = 0; i < 3; i++) {
            Payment p(codes[i], dates[i], percents[i], status[i]);
            if (checkGetters(p, i))
                continue;
            throw 0;
        }
        passed++;
        report.push_back("Instantiante payment entity - SUCCESS");
    } catch(...) {
        report.push_back("Instantiante payment entity - FAILURE");
    }
}
