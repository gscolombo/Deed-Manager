#ifndef VIEW_UI_HPP_INCLUDED
#define VIEW_UI_HPP_INCLUDED

#include <ncurses.h>
#include <clocale>

/**
 * @class UI
 * @brief Singleton class that holds the terminal UI.
 *
 * This class is a singleton that holds the terminal UI. It is responsible for
 * initializing and closing the terminal UI. It also has a static method to get
 * the instance of the UI singleton.
 *
 * All the public and protected members of this class are static and should be
 * accessed through the static `getUI()` method.
 */
class UI {
    protected:
        /**
         * Static instance of the UI singleton.
         */
        static UI* ui;

        /**
         * Private constructor to ensure that only one instance of UI is created.
         */
        UI();

        /**
         * Private destructor to ensure that the instance of UI is destroyed
         * only when it is no longer needed.
         */
        ~UI() {};

    public:
        /**
         * Deleted copy constructor to ensure that objects of UI cannot be
         * copied.
         */
        UI(const UI& obj) = delete;

        /**
         * Static method to get the instance of the UI singleton.
         *
         * @return The instance of the UI singleton.
         */
        static UI* getUI() {
            if (ui == nullptr) {
                ui = new UI();
            }
            return ui;
        }

        /**
         * Static method to close the terminal UI.
         *
         * This method closes the terminal UI by calling the endwin() function
         * from the ncurses library.
         */
        static void close();

        /**
         * Height of the terminal UI.
         */
        int height;

        /**
         * Width of the terminal UI.
         */
        int width;
};

inline void UI::close() {
    endwin();
}

#endif // VIEW_UI_HPP_INCLUDED
