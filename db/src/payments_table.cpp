#include "payments_table.hpp"

typedef tuple<string,string> codeT;
typedef tuple<int,int,int> dateT;

int PaymentsTable::populate(void* data, int c, char** fields, char** columns) {
    list<Payment>* payments = static_cast<list<Payment> *>(data);

    vector<string> vd = split(fields[1], "-");
    dateT td = {stoi(vd[0]), stoi(vd[1]), stoi(vd[2])};

    string percentString = string(fields[2]);
    percentString.erase(percentString.end()-1);
    double percent = stod(percentString);

    Payment payment(fields[0], td, percent, stoi(fields[3]));
    payments->push_back(payment);

    return 0;
}

void PaymentsTable::get(map<string,string>& data) {
    result.payments.clear();

    string sql = "SELECT * FROM payments WHERE deed = '" + data["deed"] + "';";

    status = sqlite3_exec(connection, sql.c_str(), populate, (&result.payments), &error);

    if (status != SQLITE_OK){
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}

void PaymentsTable::add(map<string,string>& data) {
    char sql[256];
    snprintf(sql, sizeof(sql),
             "INSERT INTO payments VALUES ('%s', '%s', %s, %s, '%s');",
             data["code"].c_str(), data["date"].c_str(), data["percent"].c_str(),
             data["status"].c_str(), data["deed"].c_str());

    status = sqlite3_exec(connection, sql, nullptr, nullptr, &error);


    if (status == SQLITE_CONSTRAINT){
        log = "Pagamento já cadastrado para esse título!";
        sqlite3_free(error);
    } else if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
    }

    error = nullptr;
}

void PaymentsTable::update(map<string,string>& data) {
    string sql = "UPDATE payments SET ";
    list<string> settings;

    for(auto const& [k,v] : data) {
        if (k == "deed" || k == "code") continue;
        if (k == "percent" || k == "status") settings.push_back(k + "=" + v);
        else settings.push_back(k + "='" + v + "'");
    }

    list<string>::iterator it;
    for (it = settings.begin(); it != settings.end(); ++it) {
        sql += *it + (*it == settings.back() ? "" : ", ");
    }
    sql += " WHERE code = '" + data["code"] + "' AND deed = '" + data["deed"] + "';";

    status = sqlite3_exec(connection, sql.c_str(), nullptr, nullptr, &error);

    if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}

void PaymentsTable::del(map<string,string>& data) {
    char sql[100];
    snprintf(sql, sizeof(sql), "DELETE FROM payments WHERE deed = '%s' AND code = '%s';",
            data["deed"].c_str(), data["code"].c_str());

    status = sqlite3_exec(connection, sql, nullptr, nullptr, &error);

    if (status != SQLITE_OK) {
        log = error;
        sqlite3_free(error);
        error = nullptr;
    }
}
