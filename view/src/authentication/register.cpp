#include "authentication/register.hpp"

bool Register::createAccount(Data& data) {
    if (!IRegister->createAccount(data)){
        updateInfo(IRegister->info.c_str());
        return false;
    }
    response = IRegister->account;
    return true;
}

void Register::updateInfo(const char* newInfo) const {
    werase(info);
    mvwprintw(info, 0, 0, "%s", newInfo);
    wrefresh(info);
}
