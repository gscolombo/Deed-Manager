#include "presentation_logic/window.hpp"

Window::Window(array<int,2> p, array<int,2> d) {
    UI::getUI();

    position = p;
    dimensions = d;

    window = newwin(!dimensions.empty() ? dimensions[0] : getUI()->height,
                    !dimensions.empty() ? dimensions[1] : getUI()->width,
                    position[1], position[0]);
}
