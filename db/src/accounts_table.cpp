#include "accounts_table.hpp"

int AccountsTable::populate(void* data, int c, char** fields, char** columns) {
    list<Account>* accounts = static_cast<list<Account> *>(data);

    Account account(fields[0], fields[1], fields[2]);
    accounts->push_back(account);

    return 0;
}

void AccountsTable::add(map<string,string>& data) {
    result.accounts.clear();

    char sql[256];
    snprintf(sql, sizeof(sql),
             "INSERT INTO accounts VALUES ('%s', '%s', '%s');",
             data["CPF"].c_str(), data["Nome"].c_str(), data["Senha"].c_str());

    status = sqlite3_exec(connection, sql, nullptr, nullptr, &error);

    if (status == SQLITE_CONSTRAINT){
        log = "Conta já cadastrada! Faça login.";
        sqlite3_free(error);
    } else if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
    } else
        get(data);
}

void AccountsTable::update(map<string,string>& data) {
    string sql = "UPDATE accounts SET ";
    list<string> settings;

    for (auto const& [k, v] : data) {
        if (k == "Nome" && !v.empty()) settings.push_back("name = '" + v + "'");
        if (k == "Senha" && !v.empty()) settings.push_back("password = '" + v + "'");
    }

    list<string>::iterator it;
    for (it = settings.begin(); it != settings.end(); ++it) {
        sql += *it + (*it == settings.back() ? "" : ", ");
    }
    sql += " WHERE cpf = '" + data["cpf"] + "';";

    status = sqlite3_exec(connection, sql.c_str(), nullptr, nullptr, &error);

    if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
    } else {
        get(data);
    }
}

void AccountsTable::get(map<string,string>& data) {
    result.accounts.clear();

    string sql = "SELECT * FROM accounts";

    if (data.empty()) sql += ";";
    else {
        sql += " WHERE ";

        list<string> filters;
        for (auto const& [k, v] : data) {
            if (k == "Nome" && !v.empty()) filters.push_back("name = '" + v + "'");
            if (k == "Senha" && !v.empty()) filters.push_back("password = '" + v + "'");
        }

        list<string>::iterator it;
        for (it = filters.begin(); it != filters.end(); ++it) {
            sql += *it + (*it == filters.back() ? ";" : " AND ");
        }
    }

    status = sqlite3_exec(connection, sql.c_str(), this->populate, (&result.accounts), &error);

    if (status != SQLITE_OK){
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}

void AccountsTable::del(map<string,string>& data) {
    char sql[100];
    snprintf(sql, sizeof(sql), "DELETE FROM accounts WHERE cpf = '%s';", data["cpf"].c_str());

    status = sqlite3_exec(connection, sql, nullptr, nullptr, &error);

    if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}
