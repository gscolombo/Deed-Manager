#ifndef VIEW_MENU_HPP_INCLUDED
#define VIEW_MENU_HPP_INCLUDED

#include "window.hpp"
#include <vector>
#include <array>
#include <string>

using namespace std;

class Menu : public Window {
    private:
        int highlight = 1;
        int selected;
        vector<string> options;
        WINDOW* window;
    public:
        Menu(vector<string> options,
             array<int,2> p = {},
             array<int,2> d = {}) : Window(p,d)
             {
                window = getWindow();
                this->options = options;

                keypad(window, TRUE);
                curs_set(0);
                refreshWindow();
             };

        void start();
        void refreshWindow() override;
        int getSelected() const;
};

inline int Menu::getSelected() const {
    return selected;
}

#endif // VIEW_MENU_HPP_INCLUDED
