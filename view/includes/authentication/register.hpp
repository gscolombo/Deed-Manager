#ifndef VIEW_REGISTER_HPP_INCLUDED
#define VIEW_REGISTER_HPP_INCLUDED

#include "presentation_logic/form.hpp"
#include "account.hpp"
#include "authentication/register_user.hpp"

class Register {
    private:
        Account response;
        WINDOW* info;

        IRegistration* IRegister;
    public:
        Register() : form({"Nome", "CPF", "Senha"}, {0,5},{8,COLS})
        {
            IRegistration* p_IRegister = new RegisterUser;
            setRegistrationInterface(p_IRegister);

            info = newwin(1,COLS, 4, 0);
            mvwprintw(info, 0, 0, "Insira os dados para cadastro.");
            wrefresh(info);
        };
        ~Register()
        {
            updateInfo("");
            delwin(info);
            form.closeWindow();
            delete IRegister;
            IRegister = nullptr;
        }

        Account getResponse() const;
        Form form;
        void updateInfo(const char*) const;
        bool createAccount(Data&);
        void setRegistrationInterface(IRegistration*);
};

inline Account Register::getResponse() const {
    return response;
}

inline void Register::setRegistrationInterface(IRegistration* IRegister) {
    this->IRegister = IRegister;
}

#endif // VIEW_REGISTER_HPP_INCLUDED
