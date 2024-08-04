#ifndef VIEW_SERVICE_MENU_HPP_INCLUDED
#define VIEW_SERVICE_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include "header.hpp"

#include "operations/account_menu.hpp"
#include "operations/deed_menu.hpp"
#include "operations/payment_menu.hpp"

/**
 * @class ServicesMenu
 * @brief The ServicesMenu class is a menu that provides access to various
 * services.
 *
 * This class inherits from the BaseMenu class and provides a way to navigate
 * through the different services available. These services are:
 *
 * - Account: Access to the user's account information and related operations.
 * 
 * - Deed: Access to the user's deeds and related operations.
 * 
 * - Payment: Access to the user's payment information and related operations.
 *
 * The user can also logout or terminate the program from this menu.
 */
class ServicesMenu: public BaseMenu {
    private:
        Header* header; ///< Pointer to the header object.

        /**
         * @brief Enumeration of the available services.
         */
        enum Option { ACCOUNT, DEED, PAYMENT, LOGOUT = 4, KILL };

        /**
         * @brief Initializes the menu.
         *
         * This function initializes the menu by setting the options and
         * registering the functions to be called when the user selects each
         * option.
         */
        void init();
    public:
        /**
         * @brief Constructs a new ServicesMenu object.
         *
         * @param header Pointer to the header object.
         */
        ServicesMenu(Header* header)
        : BaseMenu({"Conta", "Títulos", "Pagamentos", "", "Sair", "Encerrar programa"}, {0,5}, {8,COLS})
        {
            this->header = header;
            init();
        }

        bool killProgram = false; ///< Flag indicating whether the program should be terminated.
        bool logout = false;       ///< Flag indicating whether the user wants to log out.
};



#endif // VIEW_SERVICE_MENU_HPP_INCLUDED
