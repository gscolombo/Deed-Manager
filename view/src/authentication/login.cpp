#include "authentication/login.hpp"

bool Login::authenticate(Data& d) {
    if (!IAuth->authenticate(d)) {
        updateInfo(IAuth->getInfo().c_str());
        return false;
    }
    response = IAuth->getAccount();
    return true;
}

void Login::updateInfo(const char* newInfo) const {
    werase(info);
    mvwprintw(info, 0, 0, "%s", newInfo);
    wrefresh(info);
}
