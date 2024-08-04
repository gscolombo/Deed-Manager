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

/**
 * @class PaymentMenu
 * @brief Menu class for payment operations.
 *
 * This class provides a menu for performing payment related operations.
 * It uses the IDeedOperations and IPaymentOperations interfaces to interact
 * with the services layer. The supported operations are:
 *
 * - Create a new payment.
 *
 * - List and read all payments of a deed.
 *
 * - Update a payment.
 *
 * - Delete a payment.
 */
class PaymentMenu: public BaseMenu {
    private:
        string baseLog;
        IDeedOperations* deedOperations;
        IPaymentOperations* paymentOperations;

        list<Payment> payments;
        list<Deed> deeds;
        int deedSelected;
        enum Action { CREATE, LIST, BACK = 5};

        /**
         * @brief Create a new payment.
         */
        void create();

        /**
         * @brief Update a payment.
         * @param editCode The code of the payment to be updated.
         * @param formData The data to update the payment.
         */
        void update(string&, string&);

        /**
         * @brief Delete a payment.
         * @param editCode The code of the payment to be deleted.
         * @param formData Unused.
         */
        void del(string&, string&);

        /**
         * @brief List all payments of a deed.
         */
        void listing();

        /**
         * @brief List all deeds.
         */
        void listDeeds();

        /**
         * @brief Set the code of a payment.
         * @param data The data to be set.
         */
        void setCode(Data&);

        /**
         * @brief Set the status of a payment.
         * @param data The data to be set.
         */
        void setStatus(Data&);

        /**
         * @brief Set the date of a payment.
         * @param data The data to be set.
         */
        void setDate(Data&);

        /**
         * @brief Set the percent of a payment.
         * @param data The data to be set.
         */
        void setPercent(Data&);

        /**
         * @brief Initialize the class.
         */
        void init();
    public:
        /**
         * @brief Construct a new PaymentMenu object.
         *
         * It initializes the menu with the given options and positions.
         */
        PaymentMenu()
        : BaseMenu({"Criar Pagamento", "Listar pagamentos por título", "", "", "", "Voltar"}, {0,5}, {8, COLS})
        {
            deedOperations = new DeedOperations;
            paymentOperations = new PaymentOperations;

            init();
        }

        /**
         * @brief Destructs the PaymentMenu object.
         *
         * It deletes the dynamically allocated memory.
         */
        ~PaymentMenu() {
            delete deedOperations;
            delete paymentOperations;
        }
};

#endif // VIEW_PAYMENT_MENU_HPP_INCLUDED
