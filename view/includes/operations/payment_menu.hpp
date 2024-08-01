#ifndef VIEW_PAYMENT_MENU_HPP_INCLUDED
#define VIEW_PAYMENT_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include <list>
#include <vector>

#include "payment.hpp"
#include "deed.hpp"

#include "presentation_logic/form.hpp"
#include "presentation_logic/list.hpp"

#include "services/includes/operations/deed_operations.hpp"
#include "services/includes/operations/payment_operations.hpp"

class PaymentMenu: public BaseMenu {
    private:
        string baseLog;
        IDeedOperations* deedOperations;
        IPaymentOperations* paymentOperations;

        list<Payment> payments;
        list<Deed> deeds;
        int deedSelected;
        enum Action { CREATE, LIST, BACK = 5};

        void create();
        void update(string&, string&);
        void del(string&, string&);
        void listing();
        void listDeeds();

        void setCode(Data&);
        void setStatus(Data&);
        void setDate(Data&);
        void setPercent(Data&);

        void init();
    public:
        PaymentMenu()
        : BaseMenu({"Criar Pagamento", "Listar pagamentos por título", "", "", "", "Voltar"}, {0,5}, {8, COLS})
        {
            deedOperations = new DeedOperations;
            paymentOperations = new PaymentOperations;

            init();
        }
        ~PaymentMenu() {
            delete deedOperations;
            delete paymentOperations;
        }
};

#endif // VIEW_PAYMENT_MENU_HPP_INCLUDED
