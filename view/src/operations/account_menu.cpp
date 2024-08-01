#include "operations/account_menu.hpp"

void AccountMenu::init() {
    j: menu.start();
    Action action = (Action) menu.getSelected();

    switch (action) {
        case BACK: break;
        case READ:
            read();
            goto j;
        case UPDATE:
            edit();
            goto j;
        case DELETE:
            del();
            if (userDeleted) break;
            goto j;
    }
}

void AccountMenu::read() {
    list<string> items = IAccountOp->read(user);

    Menu closeButton({" Fechar"}, {0,17}, {3, 10});
    List<string> l(items, {0,13}, {4, COLS});

    l.show();
    closeButton.start();
    if (closeButton.getSelected() == 0) {
        closeButton.closeWindow();
        l.closeWindow();
    }
}

void AccountMenu::edit() {
    string name = user.getName();
    string password = user.getPassword();

    Window instructions({0,13}, {1, COLS});
    Window log({0,21}, {1,COLS});

    mvwprintw(instructions.getWindow(), 0, 1, "Caso não deseje alterar um dado, deixe o campo em branco.");
    instructions.refreshWindow();

    Form edit({"Nome", "Senha"}, {0,14}, {7,COLS});
    i: edit.chooseField();

    bool filled = !edit.data["Nome"].empty() || !edit.data["Senha"].empty();
    if (edit.submit && filled) {
        if (!IAccountOp->update(user, edit.data)) {
            werase(log.getWindow());
            mvwprintw(log.getWindow(), 0, 1, "%s", IAccountOp->info.c_str());
            log.refreshWindow();
            goto i;
        }
        setUser(IAccountOp->account);
        updateHeader();
    }
    else if (edit.goBack) return;
    else {
        edit.submit = false;
        goto i;
    }
}

void AccountMenu::del() {
    Window confirmation({0,13}, {4,COLS});
    mvwprintw(confirmation.getWindow(), 1, 1, "Você tem certeza que deseja deletar sua conta?");
    mvwprintw(confirmation.getWindow(), 2, 1, "Essa operação é irreversível.");
    box(confirmation.getWindow(), 0, 0);
    confirmation.refreshWindow();

    Menu confirm({"Deletar", "Cancelar"}, {0,17}, {4, 10});
    confirm.start();

    if (confirm.getSelected() == 0)
        userDeleted = IAccountOp->del(user);
}

void AccountMenu::updateHeader() {
    string welcome = "Olá, " + user.getName();
    header->updateInfo(welcome.c_str());
}
