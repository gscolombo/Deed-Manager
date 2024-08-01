#ifndef INTERFACES_REGISTRATION_HPP_INCLUDED
#define INTERFACES_REGISTRATION_HPP_INCLUDED

#include "account.hpp"
#include <map>

class IRegistration {
    public:
        virtual bool createAccount(map<string,string>&) = 0;
        virtual bool validateInput(Name&, CPF&, Password&, map<string,string>&) = 0;
        virtual ~IRegistration() {};

        Account account;
        string info;
};


#endif // INTERFACES_REGISTRATION_HPP_INCLUDED
