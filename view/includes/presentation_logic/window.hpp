#ifndef VIEW_WINDOW_HPP_INCLUDED
#define VIEW_WINDOW_HPP_INCLUDED

#include "ui.hpp"
#include <array>

using namespace std;

/**
 * @class Window
 * @brief Class representing a Window in the User Interface.
 *
 * This class represents a Window in the User Interface. It inherits from
 * the UI class and provides methods to create and manipulate windows.
 *
 * @var Window::window
 * The window handle.
 *
 * @var Window::position
 * The position of the window.
 *
 * @var Window::dimensions
 * The dimensions of the window.
 *
 * @fn Window::Window(const Window&)
 * Copy constructor.
 *
 * @fn Window::Window(array<int,2> p = {}, array<int,2> d = {})
 * Constructor. Creates a new window with the specified position and
 * dimensions. If not specified, the position is (0,0) and the dimensions
 * are the default window dimensions.
 *
 * @fn Window::~Window()
 * Destructor. Closes the window.
 *
 * @fn void Window::refreshWindow()
 * Refreshes the window.
 *
 * @fn void Window::closeWindow()
 * Closes the window.
 *
 * @fn WINDOW* Window::getWindow() const
 * Returns the window handle.
 *
 */
class Window : public UI {
    private:
        WINDOW* window;
    public:
        /**
         * @brief Constructor.
         * @param p The position of the window.
         * @param d The dimensions of the window.
         */
        Window(array<int,2> p = {}, array<int,2> d = {});
        /**
         * @brief Destructor.
         */
        virtual ~Window(){ closeWindow(); };

        /**
         * @brief Refreshes the window.
         */
        virtual void refreshWindow();
        /**
         * @brief Closes the window.
         */
        void closeWindow();
        /**
         * @brief Returns the window handle.
         * @return The window handle.
         */
        WINDOW* getWindow() const;

        array<int,2> position, dimensions;
};

inline void Window::closeWindow() {
    werase(window);
    wrefresh(window);
    delwin(window);
    window = nullptr;
}

inline WINDOW* Window::getWindow() const {
    return window;
}

inline void Window::refreshWindow() {
    wrefresh(window);
}

#endif // VIEW_WINDOW_HPP_INCLUDED
