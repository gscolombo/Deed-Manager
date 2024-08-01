#ifndef SERVICES_AUTHENTICATE_USER_HPP_INCLUDED
#define SERVICES_AUTHENTICATE_USER_HPP_INCLUDED

#include "authentication/authentication.hpp"
#include "accounts_table.hpp"

class AuthenticateUser: public IAuthentication {
    private:
        IQUeryDatabase* IQuery;
    public:
        AuthenticateUser()
        {
            IQUeryDatabase* p_IQuery = new AccountsTable();
            setQueryDBInterface(p_IQuery);
        }
        ~AuthenticateUser() { delete IQuery; };

        bool authenticate(map<string,string>&);
        bool validateCredentials(CPF&, Password&, map<string,string>&);

        void setQueryDBInterface(IQUeryDatabase*);
};

inline void AuthenticateUser::setQueryDBInterface(IQUeryDatabase* IQuery) {
    this->IQuery = IQuery;
}

#endif // SERVICES_AUTHENTICATE_USER_HPP_INCLUDED
