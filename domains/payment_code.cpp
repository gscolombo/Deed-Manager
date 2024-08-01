#include "payment_code.hpp"

void PaymentCode::validate(string& code) const {
    if (code.size() != 8)
        throw invalid_argument("Código deve ter 8 dígitos.");

    for (char d: code) {
        if (!isdigit(d))
            throw invalid_argument("Código deve conter somente dígitos.");
    }

    if (code[0] == '0')
        throw invalid_argument("Primeiro dígito do código deve ser diferente de 0.");
}

void PaymentCode::setPaymentCode(string& code) {
    validate(code);
    setCode(code);
}
