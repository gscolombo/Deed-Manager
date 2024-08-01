#ifndef VIEW_HEADER_HPP_INCLUDED
#define VIEW_HEADER_HPP_INCLUDED

#include "presentation_logic/window.hpp"
#include <string>

#define DEFAULT_INFO "Faça login/cadastro para utilizar o sistema."

using namespace std;

class Header: public Window {
    private:
        const char* info = DEFAULT_INFO;
        WINDOW* window;
    public:
        Header() : Window({0,0}, {4, COLS})
        {
            window = getWindow();
            curs_set(0);
            refreshWindow();
        };
        Header operator=(const Header&);

        void updateInfo(const char* info = DEFAULT_INFO);
        void refreshWindow() override;
};

#endif // VIEW_HEADER_HPP_INCLUDED
