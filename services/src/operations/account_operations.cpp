#include "services/includes/operations/account_operations.hpp"

list<string> AccountOperations::read(Account& account) const {
    list<string> l;

    l.push_back("Nome: " + account.getName());
    l.push_back("CPF: " + account.getCPF());

    return l;
}

bool AccountOperations::update(Account& user, map<string,string>& data) {
    Name _name;
    Password _password;

    if (!data["Nome"].empty()) {
        if (data["Nome"] == user.getName()) {
            info = "Novo nome não pode ser igual ao nome atual.";
            return false;
        }

        try {
            _name.setNames(data["Nome"]);
        } catch (invalid_argument& e) {
            info = e.what();
            return false;
        }
    }

    if (!data["Senha"].empty()) {
        if (data["Senha"] == user.getPassword()) {
            info = "Nova senha não pode ser igual à senha atual.";
            return false;
        }

        try {
            _password.setPassword(data["Senha"]);
        } catch (invalid_argument& e) {
            info = e.what();
            return false;
        }
    }

    data["cpf"] = user.getCPFDomain().getCode();
    IQuery->update(data);
    if (IQuery->getStatus() != SQLITE_OK) {
        info = IQuery->getLog();
        return false;
    }

    account = IQuery->getResult().accounts.front();
    return true;
}

bool AccountOperations::del(Account& user) {
    map<string,string> pkData;
    pkData["cpf"] = user.getCPFDomain().getCode();

    IQuery->del(pkData);
    if (IQuery->getStatus() != SQLITE_OK) {
        info = IQuery->getLog();
        return false;
    }

    return true;
}
