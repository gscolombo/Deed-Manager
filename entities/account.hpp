#ifndef ENTITIES_ACCOUNT_HPP_INCLUDED
#define ENTITIES_ACCOUNT_HPP_INCLUDED

#include "../domains/cpf.hpp"
#include "../domains/name.hpp"
#include "../domains/password.hpp"

/**
 * @class Account
 * @brief Class for account entity representation.
*/
class Account {
    private:
            CPF cpf;
            Name name;
            Password password;
        public:
            /**
             * Constructor for the Account class.
             *
             * @param cpf The CPF (Cadastro de Pessoa Física) number of the account holder.
             * @param name The name of the account holder.
             * @param password The password for the account.
             *
             * This constructor initializes the Account object with the provided CPF, name, and password.
             * It sets the CPF, name, and password domains using the corresponding setter methods.
             *
             * @throws None
             */
            Account(string cpf = "", string name = "", string password = "")
            {
                if (cpf != "") this->cpf.setCPF(cpf);
                if (name != "") this->name.setNames(name);
                if (password != "") this->password.setPassword(password);
            }

            CPF getCPFDomain() const; ///< @brief Retrieve the account holder's CPF object.
            string getCPF() const; ///< @brief Retrieve the account holder's CPF formatted string.
            string getName() const; ///< @brief Retrieve the account holder's name.
            string getPassword() const; ///< @brief Retrieve the account password.
};

inline CPF Account::getCPFDomain() const {
    return cpf;
}

inline string Account::getCPF() const {
    return cpf.getCPF();
}

inline string Account::getName() const {
    return name.getFullName();
}

inline string Account::getPassword() const {
    return password.getPassword();
}

#endif // ENTITIES_ACCOUNT_HPP_INCLUDED
