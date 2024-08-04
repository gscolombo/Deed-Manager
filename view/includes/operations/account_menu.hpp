#ifndef VIEW_ACCOUNT_MENU_HPP_INCLUDED
#define VIEW_ACCOUNT_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include "header.hpp"

#include "presentation_logic/list.hpp"
#include "presentation_logic/form.hpp"

#include "interfaces/operations/account_operations.hpp"
#include "services/includes/operations/account_operations.hpp"

/**
 * @class AccountMenu
 * @brief This class represents the account menu UI.
 *
 * This class is responsible for handling the account menu UI. It inherits from the
 * BaseMenu class and provides methods for displaying the account menu and performing
 * the corresponding actions.
 */
class AccountMenu: public BaseMenu {
    private:
        IAccountOperations* IAccountOp; /**< Pointer to the account operations interface. */
        Header* header; /**< Pointer to the header object. */

        /**
         * @brief Enumeration representing the different actions available in the account menu.
         */
        enum Action { READ, UPDATE, DELETE, BACK = 5 };

        /**
         * @brief Displays the account details.
         */
        void read();

        /**
         * @brief Allows the user to edit the account details.
         */
        void edit();

        /**
         * @brief Handles the deletion of the account.
         */
        void del();

        /**
         * @brief Initializes the account menu.
         */
        void init();

        /**
         * @brief Updates the header with the account details.
         */
        void updateHeader();
    public:
        /**
         * @brief Constructs an AccountMenu object.
         *
         * @param header A pointer to a `Header` object.
         */
        AccountMenu(Header* header)
        : BaseMenu({"Visualizar dados da conta", "Atualizar dados", "Deletar conta", "", "", "Fechar"}, {0,5}, {8, COLS})
        {
            this->header = header;

            IAccountOp = new AccountOperations();

            init();
        }

        /**
         * @brief Destructs an AccountMenu object.
         */
        ~AccountMenu()
        {
            delete IAccountOp;
            IAccountOp = nullptr;
        }

        bool userDeleted = false; /**< Flag indicating whether the user has deleted their account. */
};


#endif // VIEW_ACCOUNT_MENU_HPP_INCLUDED
