#include "deeds_table.hpp"

typedef tuple<string,string> codeT;
typedef tuple<int,int,int> dateT;

int DeedsTable::populate(void* data, int c, char** fields, char** columns) {
    list<Deed>* deeds = static_cast<list<Deed> *>(data);

    codeT deedCode;
    string type = string(fields[0]).substr(0,3);
    string code = string(fields[0]).substr(3);
    deedCode = {code, type};

    string emitter = fields[1];
    int sector = stoi(fields[2]);

    vector<string> d1 = split(fields[3], "-");
    vector<string> d2 = split(fields[4], "-");

    dateT emissionDate = {stoi(d1[0]), stoi(d1[1]), stoi(d1[2])};
    dateT expirationDate = {stoi(d2[0]), stoi(d2[1]), stoi(d2[2])};

    double value = stod(fields[5]);

    Deed deed(deedCode, emitter, sector, emissionDate, expirationDate, value);
    deeds->push_back(deed);

    return 0;
}

void DeedsTable::get(map<string,string>& data) {
    result.deeds.clear();

    string sql = "SELECT * FROM deeds WHERE cpf = '" + data["cpf"] + "';";

    status = sqlite3_exec(connection, sql.c_str(), populate, (&result.deeds), &error);

    if (status != SQLITE_OK){
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}

void DeedsTable::add(map<string,string>& data) {
    char sql[256];
    snprintf(sql, sizeof(sql),
             "INSERT INTO deeds VALUES ('%s', '%s', %s, '%s', '%s', %s, '%s');",
             data["code"].c_str(), data["emitter"].c_str(), data["sector"].c_str(),
             data["emissionDate"].c_str(), data["expirationDate"].c_str(),
             data["value"].c_str(), data["cpf"].c_str());

    status = sqlite3_exec(connection, sql, nullptr, nullptr, &error);


    if (status == SQLITE_CONSTRAINT){
        log = "Título já foi cadastrado!";
        sqlite3_free(error);
    } else if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
    }

    error = nullptr;
}

void DeedsTable::update(map<string,string>& data) {
    string sql = "UPDATE deeds SET ";
    list<string> settings;

    for(auto const& [k,v] : data) {
        if (k == "cpf" || k == "code") continue;
        if (k == "sector" || k == "value") settings.push_back(k + "=" + v);
        else settings.push_back(k + "='" + v + "'");
    }

    list<string>::iterator it;
    for (it = settings.begin(); it != settings.end(); ++it) {
        sql += *it + (*it == settings.back() ? "" : ", ");
    }
    sql += " WHERE code = '" + data["code"] + "' AND cpf = '" + data["cpf"] + "';";

    status = sqlite3_exec(connection, sql.c_str(), nullptr, nullptr, &error);

    if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}

void DeedsTable::del(map<string,string>& data) {
    char sql[100];
    snprintf(sql, sizeof(sql), "DELETE FROM deeds WHERE cpf = '%s' AND code = '%s';",
            data["cpf"].c_str(), data["code"].c_str());

    status = sqlite3_exec(connection, sql, nullptr, nullptr, &error);

    if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}
