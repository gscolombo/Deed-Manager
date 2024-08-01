#ifndef SERVICES_REGISTRATION_HPP_INCLUDED
#define SERVICES_REGISTRATION_HPP_INCLUDED

#include "authentication/registration.hpp"
#include "accounts_table.hpp"

class RegisterUser: public IRegistration {
    private:
        IQUeryDatabase* IQuery;
    public:
        RegisterUser()
        {
            IQUeryDatabase* p_IQuery = new AccountsTable();
            setQueryDBInterface(p_IQuery);
        }
        ~RegisterUser() { delete IQuery; };

        bool createAccount(map<string,string>&);
        bool validateInput(Name&, CPF&, Password&, map<string,string>&);

        void setQueryDBInterface(IQUeryDatabase*);
};

inline void RegisterUser::setQueryDBInterface(IQUeryDatabase* IQuery) {
    this->IQuery = IQuery;
}

#endif // SERVICES_REGISTRATION_HPP_INCLUDED
