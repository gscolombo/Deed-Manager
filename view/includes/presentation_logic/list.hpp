#ifndef VIEW_LIST_HPP_INCLUDED
#define VIEW_LIST_HPP_INCLUDED

#include "window.hpp"
#include <list>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class List: public Window {
    private:
        list<T> items;

        string (*display)(T) = nullptr;
    public:
        List(list<T> items, array<int,2> p = {}, array<int,2> d = {},
            string (*fn)(T) = nullptr) : Window(p,d)
             {
                this->items = items;
                if (fn != nullptr)
                    this->display = fn;
                else
                    display = [](T t) -> string { return t; };

                curs_set(0);
             };

        void show() const {
            WINDOW* ol = getWindow();

            int i = 1;
            for (T const& li: items) {
                mvwprintw(ol, i++, 1, "%s", display(li).c_str());
            }

            box(ol,0,0);
            wrefresh(ol);
        };

        void hide() const {
            WINDOW* ol = getWindow();

            werase(ol);
            box(ol,0,0);
            wrefresh(ol);
        }
};

#endif // VIEW_LIST_HPP_INCLUDED
