#include "cpf.hpp"

#include <iostream>

string getValidationCPFdigits(string code) {
    int d1 = 0;
    int d2 = 0;

    for (int i = 0; i < 9; i++) {
        d1 += (code[i] - '0') * (i + 1);
        d2 += (code[i] - '0') * i;
    }

    d1 = (d1 % 11) == 10 ? 0 : (d1 % 11);

    d2 = (d2 + (d1 * 9)) % 11;
    d2 = d2 == 10 ? 0 : d2;

    return to_string(d1) + to_string(d2);
}


void CPF::validate(string& cpf) const {
    if (cpf.size() != 11)
        throw invalid_argument("CPF deve conter exatamente 11 dígitos.");

    for (char d: cpf) {
        if (!isdigit(d))
            throw invalid_argument("CPF deve conter somente dígitos.");
    }

    string codeDigits = cpf.substr(0,9);
    string validationDigits = cpf.substr(9,2);
    if (validationDigits != getValidationCPFdigits(codeDigits))
        throw invalid_argument("CPF inválido.");
}

void CPF::setCPF(string& code) {
    validate(code);
    setCode(code);
}
