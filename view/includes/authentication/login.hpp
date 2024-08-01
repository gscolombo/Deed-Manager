#ifndef VIEW_LOGIN_HPP_INCLUDED
#define VIEW_LOGIN_HPP_INCLUDED

#include "account.hpp"
#include "presentation_logic/form.hpp"
#include "authentication/authenticate_user.hpp"

class Login {
    private:
        Account response;
        WINDOW* info;

        IAuthentication* IAuth;
    public:
        Login() : form({"CPF", "Senha"}, {0,5},{7,COLS})
        {
            IAuthentication* p_IAuth = new AuthenticateUser;
            setAuthenticationInterface(p_IAuth);

            info = newwin(1,COLS, 4, 0);
            mvwprintw(info, 0, 0, "Insira os dados de login.");
            wrefresh(info);
        };
        ~Login()
        {
            updateInfo("");
            delwin(info);
            form.closeWindow();
            delete IAuth;
            IAuth = nullptr;
        }

        Form form;
        Account getResponse() const;
        void updateInfo(const char*) const;
        bool authenticate(Data&);
        void setAuthenticationInterface(IAuthentication*);
};

inline Account Login::getResponse() const {
    return response;
}

inline void Login::setAuthenticationInterface(IAuthentication* IAuth) {
    this->IAuth = IAuth;
}

#endif // VIEW_LOGIN_HPP_INCLUDED
