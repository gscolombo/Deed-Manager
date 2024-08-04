#ifndef VIEW_DEED_MENU_HPP_INCLUDED
#define VIEW_DEED_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include <list>
#include <tuple>
#include "utils.hpp"

#include "services/includes/operations/deed_operations.hpp"

#include "presentation_logic/form.hpp"
#include "presentation_logic/list.hpp"

/**
 * @class DeedMenu
 * @brief Menu class for deed operations.
 *
 * This class provides a menu for performing deed related operations.
 * It uses the IDeedOperations interface to interact with the services layer.
 * The supported operations are:
 * 
 * - Create a new deed.
 * 
 * - List and read all deeds.
 * 
 * - Update a deed.
 * 
 * - Delete a deed.
 */
class DeedMenu: public BaseMenu {
    private:
        string baseLog;
        IDeedOperations* operations;

        list<Deed> deeds;
        Deed* deedRead = nullptr;
        enum Action { CREATE, LIST, BACK = 5};

        /**
         * @brief Create a new deed.
         */
        void create();

        /**
         * @brief Update a deed.
         * @param editCode The code of the deed to be updated.
         * @param formData The data to update the deed.
         */
        void update(string& editCode, string& formData);

        /**
         * @brief Delete a deed.
         * @param editCode The code of the deed to be deleted.
         * @param formData Unused.
         */
        void del(string& editCode, string& formData);

        /**
         * @brief List all deeds.
         */
        void listing();

        /**
         * @brief Set the code of a deed.
         * @param data The data to be set.
         */
        void setCode(Data& data);

        /**
         * @brief Set the emitter of a deed.
         * @param data The data to be set.
         */
        void setEmitter(Data& data);

        /**
         * @brief Set the sector of a deed.
         * @param data The data to be set.
         */
        void setSector(Data& data);

        /**
         * @brief Set the date of a deed.
         * @param data The data to be set.
         * @param field The field to be set.
         */
        void setDate(Data& data, const string& field);

        /**
         * @brief Set the value of a deed.
         * @param data The data to be set.
         */
        void setValue(Data& data);

        /**
         * @brief Initialize the menu.
         */
        void init();
    public:
        DeedMenu()
        : BaseMenu({"Criar título", "Listar títulos", "", "", "", "Voltar"}, {0,5}, {8, COLS})
        {
            operations = new DeedOperations;
            init();
        }
        ~DeedMenu() { delete operations; }
};

#endif // VIEW_DEED_MENU_HPP_INCLUDED
