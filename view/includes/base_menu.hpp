#ifndef VIEW_BASE_MENU_HPP_INCLUDED
#define VIEW_BASE_MENU_HPP_INCLUDED

#include <memory>

#include "account.hpp"
#include "presentation_logic/menu.hpp"

class BaseMenu {
    protected:
        Menu menu;
        static Account user;
    public:
        BaseMenu(vector<string> opt, array<int,2> p, array<int,2> d) : menu(opt, p, d) {};
        virtual ~BaseMenu() {};
        virtual void init() = 0;

        Account getUser();
        void setUser(Account);
};

inline Account BaseMenu::getUser() {
    return user;
}

inline void BaseMenu::setUser(Account user) {
    this->user = user;
}

#endif // VIEW_BASE_MENU_HPP_INCLUDED
