#include "deed_code.hpp"

// Definition of deed code types
const vector<string> DeedCode::types = { "CDB", "CRA", "CRI", "LCA", "LCI", "DEB" };

void DeedCode::validate(string& code) const {
    if (code.size() != 8)
        throw invalid_argument("Código de título deve ter 8 caracteres.");

    if (!regex_match(code, regex("\\b[A-Z0-9]+\\b")))
        throw invalid_argument("Caracteres inválidos em código de título.");
}

void DeedCode::setDeedCode(string& code, int type) {
    validate(code);
    setCode(code);
    setIndex(type);
}

void DeedCode::setDeedCode(string& code, string type) {
    validate(code);
    setCode(code);

    int index = find(types.begin(), types.end(), type) - types.begin();
    setIndex(index);
}
