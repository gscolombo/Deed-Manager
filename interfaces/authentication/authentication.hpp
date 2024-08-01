#ifndef INTERFACES_AUTHENTICATION_HPP_INCLUDED
#define INTERFACES_AUTHENTICATION_HPP_INCLUDED

#include "account.hpp"
#include <map>

class IAuthentication {
    public:
        virtual bool authenticate(map<string,string>&) = 0;
        virtual bool validateCredentials(CPF&, Password&, map<string,string>&) = 0;
        virtual ~IAuthentication() {};

        Account account;
        string info;
};

#endif // INTERFACES_AUTHENTICATION_HPP_INCLUDED
