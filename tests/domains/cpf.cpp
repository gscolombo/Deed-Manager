#include "cpf.hpp"

#include <iostream>
using namespace std;

void UTCPF::runTests() {
    CPF cpf[7];

    try {
        for (int i = 0; i < 5; i++) {
            cpf[i].setCPF(validCPFs[i]);
        }
        passed++;
        report.push_back("Set valid CPF - SUCCESS");
    } catch (invalid_argument& e) {
        report.push_back("Set valid CPF - FAILURE");
    }

    try {
        for (int i = 0; i < 5; i++) {
            if (cpf[i].getCode() != validCPFs[i]
                || cpf[i].getValidationCode() != validCPFs[i].substr(9,2)
                || cpf[i].getCPF() != formattedCPFs[i])
                report[1] = {"get valid CPF - FAILURE"};
        }
        passed++;
        report.push_back("get valid CPF - SUCCESS");
    } catch (invalid_argument& e) {
        report.push_back("get valid CPF - FAILURE");
    }

    for (int i = 0; i < 7; i++) {
        try {
            cpf[i].setCPF(invalidCPFs[i]);
            report.push_back("Throw \"invalid_argument\" exception when setting invalid CPF - FAILURE");
            return;
        } catch (invalid_argument& e) {
            continue;
        }
    }
    passed++;
    report.push_back("Throw \"invalid_argument\" exception when setting invalid CPF - SUCCESS");
}

