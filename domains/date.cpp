#include "date.hpp"

void Date::validate(int day, int month, int year) const {
    if (year < 2000 || year > 2100)
        throw invalid_argument("O ano deve estar entre 2000 e 2100!");
    if (month < 1 || month > 12)
        throw invalid_argument("O mês deve estar entre 1 e 12!");


    bool gt30 = ((month % 2 == 0 && month < 8) || (month >= 8 && month % 2 != 0)) && day > 30;
    bool isLeapYear = !(year % 4) && year != 2100; // Assumes that "year" is between 2000 and 2100

    if (day < 0 || day > 31)
        throw invalid_argument("O dia deve estar entre 1 e 31");
    else if (isLeapYear && month == 2 && (day > 29))
        throw invalid_argument("Em fevereiro e em anos bissextos, o dia deve estar entre 1 e 29");
    else if (month == 2 && day > 28 && !isLeapYear)
        throw invalid_argument("Em fevereiro, o dia deve estar entre 1 e 28");
    else if (gt30)
        throw invalid_argument("O mês definido possui somente 30 dias.");
}

string Date::formatDate(int day, int month, int year) {
    auto format = [](int n) { return n >= 10 ? to_string(n) : "0" + to_string(n);};
    return format(day) + "-" + format(month) + "-" + to_string(year);
}

void Date::setDay(int day) {
    this -> day = day;
}

void Date::setMonth(int month) {
    this -> month = month;
}

void Date::setYear(int year) {
    this -> year = year;
}

void Date::setDate(int day, int month, int year) {
    validate(day, month, year);
    setDay(day); setMonth(month); setYear(year);
    date = formatDate(day, month, year);
}

bool Date::operator<(Date& d2) {
    if (this->getYear() < d2.getYear()) return true;
    else if (this->getYear() > d2.getYear()) return false;

    if (this->getMonth() < d2.getMonth()) return true;
    else if (this->getMonth() > d2.getMonth()) return false;

    if (this->getDay() < d2.getDay()) return true;
    return false;
}
