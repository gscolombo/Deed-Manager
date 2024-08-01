#include "header.hpp"

void Header::updateInfo(const char* info) {
    this->info = info;

    mvwprintw(window, 1,0, "%s", info);
    refreshWindow();
}

void Header::refreshWindow()  {
    werase(window);

    wattron(window, A_BOLD);
    mvwprintw(window, 1,1, "Administrador de Títulos");
    wattroff(window, A_BOLD);

    mvwprintw(window, 2,1, "%s", info);
    box(window,0,0);
    wrefresh(window);
}
