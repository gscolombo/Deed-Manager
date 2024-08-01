#ifndef VIEW_ACCOUNT_MENU_HPP_INCLUDED
#define VIEW_ACCOUNT_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include "header.hpp"

#include "presentation_logic/list.hpp"
#include "presentation_logic/form.hpp"

#include "interfaces/operations/account_operations.hpp"
#include "services/includes/operations/account_operations.hpp"

class AccountMenu: public BaseMenu {
    private:
        IAccountOperations* IAccountOp;
        Header* header;

        enum Action { READ, UPDATE, DELETE, BACK = 5 };

        void read();
        void edit();
        void del();

        void init();

        void updateHeader();
    public:
        AccountMenu(Header* header)
        : BaseMenu({"Visualizar dados da conta", "Atualizar dados", "Deletar conta", "", "", "Fechar"}, {0,5}, {8, COLS})
        {
            this->header = header;

            IAccountOp = new AccountOperations();

            init();
        }
        ~AccountMenu()
        {
            delete IAccountOp;
            IAccountOp = nullptr;
        }

        bool userDeleted = false;
};


#endif // VIEW_ACCOUNT_MENU_HPP_INCLUDED
