#ifndef VIEW_AUTHENTICATION_MENU_HPP_INCLUDED
#define VIEW_AUTHENTICATION_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include "login.hpp"
#include "register.hpp"
#include "presentation_logic/menu.hpp"

class AuthenticationMenu: public BaseMenu {
    private:
        enum Option { LOGIN, REGISTER, KILL = 3 };
        void init();
    public:
        AuthenticationMenu()
        : BaseMenu({"Login", "Cadastro","","Encerrar programa"}, {0,5}, {6,COLS})
        { init(); };
        ~AuthenticationMenu()
        { menu.closeWindow(); }

        bool killProgram = false;
};

#endif // VIEW_AUTHENTICATION_MENU_HPP_INCLUDED
