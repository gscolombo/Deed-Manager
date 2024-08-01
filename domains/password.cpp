#include "password.hpp"

void Password::validate(string& password) const{
    regex r("[0-9]+");
    if (password.size() != 6)
        throw invalid_argument("Senha deve conter exatamente 6 dígitos.");

    if (password[0] == '0')
        throw invalid_argument("O primeiro dígito da senha deve ser diferente de 0");

    string characters;
    for (char d : password) {
        if (!isdigit(d))
            throw invalid_argument("Senha deve conter somente dígitos.");

        if (find(characters.begin(), characters.end(), d) != characters.end())
            throw invalid_argument("Senha não deve conter dígitos repetidos.");
        characters += d;
    }

    sort(characters.begin(), characters.end());
    if (characters == password)
        throw invalid_argument("Senha não pode ser uma sequência crescente de dígitos.");

    auto gt = [](int a, int b) { return a > b; };
    sort(characters.begin(), characters.end(), gt);
    if (characters == password)
        throw invalid_argument("Senha não pode ser uma sequência decrescente de dígitos.");
}

void Password::setPassword(string password){
    validate(password);
    this->password = password;
}
