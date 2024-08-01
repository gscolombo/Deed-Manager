#ifndef VIEW_UI_HPP_INCLUDED
#define VIEW_UI_HPP_INCLUDED

#include <ncurses.h>
#include <clocale>

class UI {
    protected:
        static UI* ui;
        UI();
        ~UI() {};
    public:
        UI(const UI& obj) = delete;
        static UI* getUI() {
            if (ui == nullptr) {
                ui = new UI();
            }
            return ui;
        }
        static void close();
        int height, width;
};

inline void UI::close() {
    endwin();
}

#endif // VIEW_UI_HPP_INCLUDED
