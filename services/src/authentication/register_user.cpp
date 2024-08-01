#include "authentication/register_user.hpp"

bool RegisterUser::createAccount(map<string,string>& data) {
    Name name;
    CPF cpf;
    Password password;

    if (validateInput(name, cpf, password, data)) {
        IQuery->add(data);
        int status = IQuery->getStatus();
        if (status == SQLITE_OK && status != SQLITE_CONSTRAINT_PRIMARYKEY) {
            account = IQuery->getResult().accounts.front();
            return true;
        } else info = IQuery->getLog();
    }
    return false;
}

bool RegisterUser::validateInput(Name& name, CPF& cpf, Password& password, map<string,string>& data) {
    try {
        if (data["Nome"] == "") throw invalid_argument("Insira um nome!");
        name.setNames(data["Nome"]);
    } catch (invalid_argument& e) {
        info = e.what();
        return false;
    }

    try {
        if (data["CPF"] == "") throw invalid_argument("Digite um CPF!");
        cpf.setCPF(data["CPF"]);
    } catch (invalid_argument& e) {
        info = e.what();
        return false;
    }

    try {
        if (data["Senha"] == "") throw invalid_argument("Digite uma senha!");
        password.setPassword(data["Senha"]);
    } catch (invalid_argument& e) {
        info = e.what();
        return false;
    }

    return true;
}
