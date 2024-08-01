#include "operations/service_menu.hpp"

void ServicesMenu::init() {
    string username = user.getName();
    string welcome = "Olá, " + username;
    header->updateInfo(welcome.c_str());

    i: menu.start();

    switch((Option) menu.getSelected()) {
        case ACCOUNT:
        {
            AccountMenu submenu(header);
            logout = submenu.userDeleted;
            if (logout) break;
        }
        goto i;
        case DEED:
        {
            DeedMenu submenu;
        }
        goto i;
        case PAYMENT:
        {
            PaymentMenu submenu;
        }
        goto i;
        case LOGOUT:
            logout = true;
            break;
        case KILL:
            killProgram = true;
            break;
    }
}
