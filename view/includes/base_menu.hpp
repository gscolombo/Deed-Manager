#ifndef VIEW_BASE_MENU_HPP_INCLUDED
#define VIEW_BASE_MENU_HPP_INCLUDED

#include <memory>

#include "account.hpp"
#include "presentation_logic/menu.hpp"

/**
 * @class BaseMenu
 * @brief Base class for all menus.
 *
 * This class is designed to be inherited by all menus. It provides a common
 * interface for all menus and provides a way to get and set the user account.
 */
class BaseMenu {
    protected:
        /**
         * @brief The menu object that this menu is based on.
         */
        Menu menu;

        /**
         * @brief The static user account.
         *
         * This account is shared by all instances of BaseMenu and is used to
         * keep track of the user's information.
         */
        static Account user;

    public:
        /**
         * @brief Constructs a new BaseMenu object with the given options,
         *        positions, and dimensions.
         *
         * @param opt The options to be displayed in the menu.
         * @param p The positions of the options in the menu.
         * @param d The dimensions of the menu.
         */
        BaseMenu(vector<string> opt, array<int,2> p, array<int,2> d) : menu(opt, p, d) {};

        /**
         * @brief Virtual destructor.
         *
         * This destructor is virtual to allow for proper polymorphism.
         */
        virtual ~BaseMenu() {};

        /**
         * @brief Initializes the menu.
         *
         * This function is pure virtual and must be implemented by any
         * subclass of BaseMenu. It is called to
         * initialize the menu before it is displayed.
         */
        virtual void init() = 0;

        /**
         * @brief Gets the user account.
         *
         * @return The user account.
         */
        Account getUser();

        /**
         * @brief Sets the user account.
         *
         * @param user The user account to set.
         */
        void setUser(Account);
};

inline Account BaseMenu::getUser() {
    return user;
}

inline void BaseMenu::setUser(Account user) {
    this->user = user;
}

#endif // VIEW_BASE_MENU_HPP_INCLUDED
