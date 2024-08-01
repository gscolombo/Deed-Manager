#include "header.hpp"
#include "authentication/authentication_menu.hpp"
#include "operations/service_menu.hpp"

int main() {
    Header header;
    auth: AuthenticationMenu authMenu;

    if (!authMenu.killProgram) {
        ServicesMenu opMenu(&header);

        if (opMenu.logout) {
            header.updateInfo();
            goto auth;
        }

        if (opMenu.killProgram) goto kill;
    }

    kill: UI::getUI()->close();

    return 0;
}


