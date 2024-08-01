#include "services/includes/operations/payment_operations.hpp"

Payment PaymentOperations::get(list<Payment>& l, int _i) const {
    list<Payment>::iterator it = l.begin();
    for (int i = 0; i < _i; i++) {
        it++;
    }
    return *it;
}

bool PaymentOperations::create(Deed& deed, map<string,string>& data) {
    data["deed"] = deed.getDeedCode();

    paymentsTable->add(data);
    if (paymentsTable->getStatus() != SQLITE_OK) {
        info = paymentsTable->getLog();
        return false;
    }

    return true;
}

list<string> PaymentOperations::read(Payment& payment) const {
    return  {
        "Código de pagamento: " + payment.getPaymentCode(),
        "Data: " + payment.getDate(),
        "Percentual: " + payment.getPercentual(),
        "Estado: " + payment.getStatus()
    };
}

bool PaymentOperations::update(Deed& deed, map<string,string>& data) {
    data.erase("statusName");
    data.erase("percentValue");

    list<string> toDeletion;

    for (auto const& [key,_] : data) {
        if (data[key].empty()) {
            toDeletion.push_back(key);
        }
    }

    for (const string& s : toDeletion) {
        data.erase(s);
    }

    paymentsTable->update(data);
    if (paymentsTable->getStatus() != SQLITE_OK) {
        info = paymentsTable->getLog();
        return false;
    }

    return true;
}

bool PaymentOperations::del(map<string,string>& data) {
    paymentsTable->del(data);
    if (paymentsTable->getStatus() != SQLITE_OK) {
        info = paymentsTable->getLog();
        return false;
    }

    return true;
}

list<Payment> PaymentOperations::listing(Deed& deed) {
    map<string,string> data;
    data["deed"] = deed.getDeedCode();

    paymentsTable->get(data);
    if (paymentsTable->getStatus() != SQLITE_OK) {
        info = paymentsTable->getLog();
        return {};
    }

    return paymentsTable->getResult().payments;
}
