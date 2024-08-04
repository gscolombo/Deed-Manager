#ifndef VIEW_HEADER_HPP_INCLUDED
#define VIEW_HEADER_HPP_INCLUDED

#include "presentation_logic/window.hpp"
#include <string>

#define DEFAULT_INFO "Faça login/cadastro para utilizar o sistema."

using namespace std;

/**
 * @class Header
 * @brief Represents the header of the interface.
 * 
 * This class inherits from the `Window` class and is used to represent the header
 * of the user interface, which displays relevant information to the user.
 */
class Header: public Window {
    private:
        /**
         * @brief The information displayed in the header.
         * 
         * The default information is \b "Faça login/cadastro para utilizar o sistema."
         */
        const char* info = DEFAULT_INFO;
        /**
         * @brief The window handle for the header.
         *
         * This is the handle to the `WINDOW` object that represents the header
         * window in the ncurses interface.
         */
        WINDOW* window;
    public:
        /**
         * @brief Constructs a new `Header` object.
         * 
         * Initializes the header at the top of the screen with the dimensions 4 rows
         * and COLS columns (the number of columns in the screen). Sets the cursor
         * visibility to 0 (invisible) and refreshes the window.
         */
        Header() : Window({0,0}, {4, COLS})
        {
            window = getWindow();
            curs_set(0);
            refreshWindow();
        };
        
        /**
         * @brief Updates the information displayed in the header.
         * 
         * Updates the information displayed in the header with the given string.
         * If no string is provided, the default information is used.
         * @param info The information to be displayed in the header.
         */
        void updateInfo(const char* info = DEFAULT_INFO);
        /**
         * @brief Refreshes the window.
         * 
         * Refreshes the window by redrawing the information displayed in the header.
         * This function is overridden from the `Window` class.
         */
        void refreshWindow() override;
};

#endif // VIEW_HEADER_HPP_INCLUDED
