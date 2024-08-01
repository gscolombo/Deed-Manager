#ifndef VIEW_DEED_MENU_HPP_INCLUDED
#define VIEW_DEED_MENU_HPP_INCLUDED

#include "base_menu.hpp"
#include <list>
#include <tuple>
#include "utils.hpp"

#include "services/includes/operations/deed_operations.hpp"

#include "presentation_logic/form.hpp"
#include "presentation_logic/list.hpp"

class DeedMenu: public BaseMenu {
    private:
        string baseLog;
        IDeedOperations* operations;

        list<Deed> deeds;
        Deed* deedRead = nullptr;
        enum Action { CREATE, LIST, BACK = 5};

        void create();
        void update(string&, string&);
        void del(string&, string&);
        void listing();

        void setCode(Data&);
        void setEmitter(Data&);
        void setSector(Data&);
        void setDate(Data&, const string&);
        void setValue(Data&);

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
