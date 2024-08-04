#ifndef VIEW_LIST_HPP_INCLUDED
#define VIEW_LIST_HPP_INCLUDED

#include "window.hpp"
#include <list>
#include <string>
#include <iostream>

using namespace std;

/**
 * @class List
 * @brief A class representing a List of items displayed in a ncurses window.
 *
 * This class is a template class that represents a list of items to be
 * displayed in a ncurses window. It takes a list of items of type T and
 * displays them in the window. It takes an optional display function that
 * converts the items to strings for display. If no display function is
 * provided, it uses the default conversion to string of the item.
 *
 * @tparam T The type of items in the list.
 */
template <typename T>
class List: public Window {
    private:
        /**
         * List of items to be displayed in the window.
         */
        list<T> items;

        /**
         * Function pointer to a function that converts the items to strings
         * for display.
         */
        string (*display)(T) = nullptr;
    public:
        /**
         * Constructor for List class.
         *
         * @param items List of items to be displayed.
         * @param p Position of the window.
         * @param d Dimensions of the window.
         * @param fn Pointer to a function that converts the items to strings.
         */
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

        /**
         * Display the items in the window.
         */
        void show() const {
            WINDOW* ol = getWindow();

            int i = 1;
            for (T const& li: items) {
                mvwprintw(ol, i++, 1, "%s", display(li).c_str());
            }

            box(ol,0,0);
            wrefresh(ol);
        };

        /**
         * Hide the window by erasing it and refreshing it.
         */
        void hide() const {
            WINDOW* ol = getWindow();

            werase(ol);
            box(ol,0,0);
            wrefresh(ol);
        }
};

#endif // VIEW_LIST_HPP_INCLUDED
