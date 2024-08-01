#include "services/includes/operations/deed_operations.hpp"

Deed DeedOperations::get(list<Deed>& l, int _i) const {
    list<Deed>::iterator it = l.begin();
    for (int i = 0; i < _i; i++) {
        it++;
    }
    return *it;
}

bool DeedOperations::create(Account& user, map<string,string>& data) {
    deedsTable->add(data);
    if (deedsTable->getStatus() != SQLITE_OK) {
        info = deedsTable->getLog();
        return false;
    }

    return true;
}

list<string> DeedOperations::read(Deed& deed) const {
    string emitter, sector, emissionDate, expirationDate, value;

    emitter = "Emissor: " +  deed.getEmitterName();
    sector = "Setor: " + deed.getSector();
    emissionDate = "Data de emissão: " + deed.getEmissionDate();
    expirationDate = "Data de validade: " + deed.getExpirationDate();
    value = "Valor: " + deed.getValueInBRL();

    return { emitter, sector, emissionDate, expirationDate, value };
}


bool DeedOperations::update(Account& user, map<string,string>& data) {
    data.erase("sectorName");
    data.erase("valueBRL");

    list<string> toDeletion;

    for (auto const& [key,_] : data) {
        if (data[key].empty()) {
            toDeletion.push_back(key);
        }
    }

    for (const string& s : toDeletion) {
        data.erase(s);
    }

    deedsTable->update(data);
    if (deedsTable->getStatus() != SQLITE_OK) {
        info = deedsTable->getLog();
        return false;
    }

    return true;
}

bool DeedOperations::del(map<string,string>& data) {
    deedsTable->del(data);
    if (deedsTable->getStatus() != SQLITE_OK) {
        info = deedsTable->getLog();
        return false;
    }

    return true;
}

list<Deed> DeedOperations::listing(Account& user) {
    map<string,string> data;
    data["cpf"] = user.getCPFDomain().getCode();

    deedsTable->get(data);
    if (deedsTable->getStatus() != SQLITE_OK) {
        info = deedsTable->getLog();
        return {};
    }

    return deedsTable->getResult().deeds;
}
