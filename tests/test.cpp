// Domain unit tests
#include "domains/cpf.hpp"
#include "domains/date.hpp"
#include "domains/deed_code.hpp"
#include "domains/money.hpp"
#include "domains/name.hpp"
#include "domains/password.hpp"
#include "domains/payment_code.hpp"
#include "domains/percent.hpp"
#include "domains/sector.hpp"
#include "domains/status.hpp"

// Entity unit tests
#include "entities/deed.hpp"
#include "entities/account.hpp"
#include "entities/payment.hpp"

int main() {
    cout << "====================" << endl << "    DOMAINS TEST    " << endl << "====================" << endl << endl;

    UTCPF utCPF; utCPF.showReport(); // CPF
    UTDate utDate; utDate.showReport(); // Date
    UTDeedCode utDeedCode; utDeedCode.showReport(); // Deed code
    UTMoney utMoney; utMoney.showReport(); // Money
    UTName utName; utName.showReport(); // Name
    UTPassword utPassword; utPassword.showReport(); // Password
    UTPaymentCode utPaymentCode; utPaymentCode.showReport(); // Payment code
    UTPercent utPercent; utPercent.showReport(); // Percent
    UTSector utSector; utSector.showReport(); // Sector
    UTStatus utStatus; utStatus.showReport(); // Status

    cout << "=====================" << endl << "    ENTITIES TEST    " << endl << "=====================" << endl << endl;

    UTDeed utDeed; utDeed.showReport(); // Deed
    UTAccount utAccount; utAccount.showReport(); // Account
    UTPayment utPayment; utPayment.showReport(); // Payment

    cout << "END OF TEST" << endl;

    return 0;
}
