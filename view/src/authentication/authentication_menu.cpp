#include "authentication/authentication_menu.hpp"

void AuthenticationMenu::init() {
    i: menu.start();

    switch((Option) menu.getSelected()) {
        case LOGIN:
        {
            Login login;
            l: login.form.chooseField();

            if (login.form.submit)
                if (login.authenticate(login.form.data)) {
                    setUser(login.getResponse());
                    break;
                }
            if (login.form.goBack) goto i;
            goto l;
        }
        break;
        case REGISTER:
        {
            Register reg;
            r: reg.form.chooseField();

            if (reg.form.submit)
                if (reg.createAccount(reg.form.data)) {
                    setUser(reg.getResponse());
                    break;
                }
            if (reg.form.goBack) goto i;
            goto r;
        }
        break;
        case KILL:
            killProgram = true;
        break;
    }
}
