#include "authentication/authenticate_user.hpp"

bool AuthenticateUser::authenticate(map<string,string>& data) {
    CPF cpf;
    Password password;

    if (validateCredentials(cpf, password, data)) {
        IQuery->get(data);
        if (IQuery->getStatus() == SQLITE_OK) {
            list<Account> v = IQuery->getResult().accounts;
            if (v.size()) {
                account = v.front();
                return true;
            } else info = "Conta não encontrada!";
        } else info = IQuery->getLog();
    }
    return false;
}

bool AuthenticateUser::validateCredentials(CPF& cpf, Password& password, map<string,string>& data) {
    try {
        cpf.setCPF(data["CPF"]);
    } catch (invalid_argument& e) {
        info = "CPF inválido!";
        return false;
    }

    try {
        password.setPassword(data["Senha"]);
    } catch (invalid_argument& e) {
        info = "Senha inválida!";
        return false;
    }

    return true;
}
