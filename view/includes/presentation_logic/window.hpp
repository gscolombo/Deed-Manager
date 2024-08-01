#ifndef VIEW_WINDOW_HPP_INCLUDED
#define VIEW_WINDOW_HPP_INCLUDED

#include "ui.hpp"
#include <array>

using namespace std;

class Window : public UI {
    private:
        WINDOW* window;
    public:
        Window(const Window&);
        Window operator=(const Window&);
        Window(array<int,2> p = {}, array<int,2> d = {});
        virtual ~Window(){ closeWindow(); };

        virtual void refreshWindow();
        void closeWindow();
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
