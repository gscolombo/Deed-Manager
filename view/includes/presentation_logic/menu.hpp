#ifndef VIEW_MENU_HPP_INCLUDED
#define VIEW_MENU_HPP_INCLUDED

#include "window.hpp"
#include <vector>
#include <array>
#include <string>

using namespace std;

/**
 * @class Menu
 * @brief A class representing a menu window.
 *
 * This class represents a menu window that displays a list of options
 * and allows the user to select one.
 */
class Menu : public Window {
    public:
        /// @brief Constructs a Menu object.
        ///
        /// Constructs a Menu object with the given options, position, and dimensions.
        ///
        /// @param options The list of options to display in the menu.
        /// @param p The position of the menu window. Default: {0,0}.
        /// @param d The dimensions of the menu window. Default: {4, COLS}.
        Menu(vector<string> options,
             array<int,2> p = {},
             array<int,2> d = {}) : Window(p,d)
        {
            // Set the window of the Menu object.
            window = getWindow();
            // Set the options of the Menu object.
            this->options = options;

            // Enable keypad input for the menu window.
            keypad(window, TRUE);
            // Hide the cursor.
            curs_set(0);
            // Refresh the menu window.
            refreshWindow();
        };

        /// @brief Starts the menu.
        ///
        /// Starts the menu and waits for the user to select an option.
        void start();

        /// @brief Refreshes the menu window.
        ///
        /// Refreshes the menu window with the current options and highlight.
        void refreshWindow() override;

        /// @brief Returns the selected option.
        ///
        /// Returns the index of the currently selected option.
        ///
        /// @return The index of the currently selected option.
        int getSelected() const;

    private:
        /// The index of the currently highlighted option.
        int highlight = 1;
        /// The index of the currently selected option.
        int selected;
        /// The list of options to display in the menu.
        vector<string> options;
        /// The window of the Menu object.
        WINDOW* window;
};

inline int Menu::getSelected() const {
    return selected;
}

#endif // VIEW_MENU_HPP_INCLUDED
