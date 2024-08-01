#include "name.hpp"

#include <iostream>

void Name::validate(string &name) const {
    name = trim(name);

    // Check for invalid characters
    regex r("[A-Za-z\\s]+");
    if (!regex_match(name, r))
       throw invalid_argument("Caracteres inválidos em \"" + name + "\"");

    // Validate number of terms and length of each term in trimmed name
    vector<string> terms = split(name);
    if (terms.size() > 2)
        throw invalid_argument("Inclua somente dois termos separados por espaço (nome e sobrenome)");

    for (string t: terms) {
        if (t.length() < 3 || t.length() > 10)
            throw invalid_argument("\"" + t  +"\" com número inválidos de caracteres.");

    }
}

string Name::formatName(string &name) {
    string formatted;
    vector<string> terms = split(trim(name));

    // Set the first letter to uppercase and the rest to lowercase for each term
    int i = 0;
    for (string t: terms) {
        t[0] = toupper(t[0]);

        for (string::iterator it = t.begin() + 1; it != t.end(); ++it) {
            *it = tolower(*it);
        }
        formatted += t + (!i ? " " : "");
        i++;
    }

    return formatted;
}

void Name::setNames(string &name) {
    validate(name);
    name = formatName(name);
    vector<string> terms = split(name);
    this->fullName = name;
    this->firstName = terms[0];
    this->secondName = terms[1];
}
