#ifndef VIEW_AUTHENTICATION_MENU_HPP_INCLUDED
#define VIEW_AUTHENTICATION_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include "login.hpp"
#include "register.hpp"
#include "presentation_logic/menu.hpp"

/**
 * @class AuthenticationMenu
 * @brief The AuthenticationMenu class represents the main menu of the
 * application in the authentication step.
 *
 * It inherits from the BaseMenu class and provides the possibility to
 * navigate through the different options available for the user, such as
 * login, register and exit the program.
 */
class AuthenticationMenu: public BaseMenu {
    private:
        enum Option { LOGIN, REGISTER, KILL = 3 };
        /**
         * @brief Initializes the authentication menu.
         *
         * This function sets the correct position of the menu's cursor
         * and defines the options available for the user.
         */
        void init();
    public:
        /**
         * @brief Constructs a new AuthenticationMenu object.
         *
         * It initializes the menu with the available options and sets the
         * position of the cursor.
         */
        AuthenticationMenu()
        : BaseMenu({"Login", "Cadastro","","Encerrar programa"}, {0,5}, {6,COLS})
        { init(); };
        /**
         * @brief Destructs the AuthenticationMenu object.
         *
         * It closes the window of the menu when the object is deleted.
         */
        ~AuthenticationMenu()
        { menu.closeWindow(); }

        /**
         * @brief Indicates whether the program should exit or not.
         *
         * It is set to true when the user chooses to exit the program.
         */
        bool killProgram = false;
};

#endif // VIEW_AUTHENTICATION_MENU_HPP_INCLUDED
