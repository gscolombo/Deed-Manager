#ifndef VIEW_SERVICE_MENU_HPP_INCLUDED
#define VIEW_SERVICE_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include "header.hpp"

#include "operations/account_menu.hpp"
#include "operations/deed_menu.hpp"
#include "operations/payment_menu.hpp"

class ServicesMenu: public BaseMenu {
    private:
        Header* header;
        enum Option { ACCOUNT, DEED, PAYMENT, LOGOUT = 4, KILL };
        void init();
    public:
        ServicesMenu(Header* header)
        : BaseMenu({"Conta", "Títulos", "Pagamentos", "", "Sair", "Encerrar programa"}, {0,5}, {8,COLS})
        {
            this->header = header;
            init();
        }

        bool killProgram = false;
        bool logout = false;
};



#endif // VIEW_SERVICE_MENU_HPP_INCLUDED
