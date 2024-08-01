#include "presentation_logic/ui.hpp"

UI* UI::ui = nullptr;

UI::UI() {
    setlocale(LC_CTYPE, "");
    initscr();
    clear();
    noecho();
    cbreak();

    height = LINES;
    width = COLS;
}
