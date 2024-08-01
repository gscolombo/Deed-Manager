#include "presentation_logic/menu.hpp"

void Menu::start() {
    selected = -1;
    int ch;

    refreshWindow();
    while (selected == -1) {
        clear();

        ch = wgetch(window);
        switch (ch) {
            case KEY_UP:
                highlight--;
                while(options[highlight-1] == "") highlight--;
                if (highlight < 1) highlight = (int) options.size();
                break;
            case KEY_DOWN:
                highlight++;
                while(options[highlight-1] == "") highlight++;
                if (highlight > (int) options.size()) highlight = 1;
                break;
            case 10:
                selected = highlight - 1;
                break;
        }

        refreshWindow();
    }
}

void Menu::refreshWindow() {
    for (int i = 0; i < (int) options.size(); i++) {
        if (highlight == i + 1)
            wattron(window, A_BOLD);
        mvwprintw(window, i+1, 1, "%s", options[i].c_str());
        wattroff(window, A_BOLD);
    }
    box(window, 0, 0);
    wrefresh(window);
}
