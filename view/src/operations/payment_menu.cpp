#include "operations/payment_menu.hpp"

void PaymentMenu::init() {
    Window info({0,4},{1, COLS});
    i:
    mvwprintw(info.getWindow(), 0, 1, "%s", baseLog.c_str());
    info.refreshWindow();
    baseLog.erase();

    menu.start();

    Action action = (Action) menu.getSelected();

    werase(info.getWindow());
    info.refreshWindow();

    switch (action) {
        case BACK: break;
        case CREATE:
        {
            werase(menu.getWindow());
            wrefresh(menu.getWindow());
            listDeeds();
            if (deedSelected < 0) goto i;
            Deed deed = deedOperations->get(deeds, deedSelected);
            list<Payment> payments = paymentOperations->listing(deed);
            if (payments.size() >= 10)
                baseLog = "Título já possui número máximo (10) de pagamentos.";
            else
                create();
        }
            goto i;
        case LIST:
        {
            werase(menu.getWindow());
            wrefresh(menu.getWindow());
            listDeeds();
            if (deedSelected < 0) goto i;
            listing();
            goto i;
        }
    }
}

void PaymentMenu::listDeeds() {
    deeds = deedOperations->listing(user);
    if (!deeds.size()) {
        baseLog = "Conta não possui títulos cadastrados!";
        return;
    }

    vector<string> options;

    for (const Deed& d: deeds) {
        options.push_back(d.getDeedCode());
    }

    options.push_back("");
    options.push_back("Voltar");

    Menu deedSelection(options, {0, 5}, {(int) options.size() + 2,COLS/4});

    deedSelection.start();

    int selected = deedSelection.getSelected();
    if (selected < (int) deeds.size())
        deedSelected = deedSelection.getSelected();
    else
        deedSelected = -1;
}

void PaymentMenu::listing() {
    Deed deed = deedOperations->get(deeds, deedSelected);

    list<Payment> payments = paymentOperations->listing(deed);
    if (payments.empty()) {
        baseLog = "Título não possui pagamentos cadastrados.";
        return;
    }

    vector<string> paymentCodeListing;

    for (const Payment& payment : payments) {
        paymentCodeListing.push_back(payment.getPaymentCode());
    }

    paymentCodeListing.push_back("");
    paymentCodeListing.push_back("Fechar");

    Menu paymentCodeMenu(paymentCodeListing, {0, 5}, {(int) paymentCodeListing.size() + 2,COLS/4-7});

    i:
    paymentCodeMenu.start();

    int i = paymentCodeMenu.getSelected();
    if (i < (int) paymentCodeListing.size() - 1) {
        Payment payment = paymentOperations->get(payments, i);
        list<string> details = paymentOperations->read(payment);

        List paymentDetails(details, {COLS/4-7, 5}, {6, 3*COLS/4 - 3});
        Menu commands({"Editar", "Deletar", "", "", "Voltar"}, {COLS - 10,5}, {7, 10});

        paymentDetails.show();
        commands.start();

        switch(commands.getSelected()) {
            case 0:
            {
                string pk = payment.getPaymentCode();
                string fk = deed.getDeedCode();
                update(pk, fk);
            }
            break;
            case 1:
            {
                string pk = payment.getPaymentCode();
                string fk = deed.getDeedCode();
                del(pk, fk);
            }
            break;
            case 4:
                goto i;
        }
    }
}

void PaymentMenu::update(string& pk, string& fk) {
    Deed deed = deedOperations->get(deeds, deedSelected);

    Data data;
    string log;

    vector<string> options = { "Data", "Percentual", "Estado", "", "Salvar", "Voltar" };
    enum Option { DATE, PERCENT, STATUS, SAVE = 4, BACK };

    data["code"] = pk;
    data["deed"] = fk;

    i:
    Window info({0,4},{1, COLS});
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    Window preSubmission({COLS/4+2,5}, {8, 3*COLS/4-2});
    mvwprintw(preSubmission.getWindow(), 1, 1, "Caso não deseje alterar um dado, deixe o campo em branco.");

    mvwprintw(preSubmission.getWindow(), 4, 1, "%s", ("Data: " + data["date"]).c_str());
    mvwprintw(preSubmission.getWindow(), 5, 1, "%s", ("Percentual: " + data["percentValue"]).c_str());
    mvwprintw(preSubmission.getWindow(), 6, 1, "%s", ("Estado: " + data["statusName"]).c_str());
    box(preSubmission.getWindow(), 0, 0);
    preSubmission.refreshWindow();

    Menu attributes(options, {0, 5}, {8,COLS/4 + 2});
    attributes.start();

    preSubmission.closeWindow();
    switch((Option) attributes.getSelected()) {
        case DATE:
            setDate(data);
            goto i;
        case PERCENT:
            setPercent(data);
            goto i;
        case STATUS:
            setStatus(data);
            goto i;
        case SAVE:
            {
                bool any = false;
                for (const char* s: {"date", "percent", "status"}) {
                    if (!data[s].empty()) {
                        any = true;
                        break;
                    }
                }
                if (any) {
                    if (!paymentOperations->update(deed, data)) {
                        log = paymentOperations->getInfo();
                        goto i;
                    }
                    baseLog = "Pagemento atualizado com sucesso!";
                    break;
                }
            }
            goto i;
        case BACK:
            break;
    }
}

void PaymentMenu::del(string& pk, string& fk) {
    Data data;

    data["code"] = pk;
    data["deed"] = fk;

    Window confirmation({0,12}, {5,COLS});
    mvwprintw(confirmation.getWindow(), 1, 1, "Você tem certeza que deseja deletar esse pagamento?");
    mvwprintw(confirmation.getWindow(), 2, 1, "Essa operação é irreversível.");
    box(confirmation.getWindow(), 0, 0);
    confirmation.refreshWindow();

    Menu confirm({"Deletar", "Cancelar"}, {0,17}, {4, 10});
    confirm.start();

    if (!confirm.getSelected()) {
        if (!paymentOperations->del(data))
            baseLog = paymentOperations->getInfo();
        else
            baseLog = "Pagamento deletado com sucesso.";
    }
}

void PaymentMenu::create() {
    Deed deed = deedOperations->get(deeds, deedSelected);

    Data data;
    string log;

    vector<string> options = { "Código de pagamento", "Data", "Percentual", "Estado", "", "Salvar", "Voltar" };
    enum Option { CODE, DATE, PERCENT, STATUS, SAVE = 5, BACK };

    i:
    Window info({0,4},{1, COLS});
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    string formHeader = "Novo pagamento para título " + deed.getDeedCode();

    Window preSubmission({COLS/4 + 2,5}, {8, 3*COLS/4 - 2});
    wattron(preSubmission.getWindow(), A_ITALIC);
    mvwprintw(preSubmission.getWindow(), 1, 1, "%s", formHeader.c_str());
    wattroff(preSubmission.getWindow(), A_ITALIC);

    mvwprintw(preSubmission.getWindow(), 3, 1, "%s", ("Código de pagamento: " + data["code"]).c_str());
    mvwprintw(preSubmission.getWindow(), 4, 1, "%s", ("Data: " + data["date"]).c_str());
    mvwprintw(preSubmission.getWindow(), 5, 1, "%s", ("Percentual: " + data["percentValue"]).c_str());
    mvwprintw(preSubmission.getWindow(), 6, 1, "%s", ("Estado: " + data["statusName"]).c_str());
    box(preSubmission.getWindow(), 0, 0);
    preSubmission.refreshWindow();

    Menu attributes(options, {0, 5}, {9,COLS/4 + 2});
    attributes.start();

    preSubmission.closeWindow();
    switch((Option) attributes.getSelected()) {
        case CODE:
            setCode(data);
            goto i;
        case DATE:
            setDate(data);
            goto i;
        case PERCENT:
            setPercent(data);
            goto i;
        case STATUS:
            setStatus(data);
            goto i;
        case SAVE:
            {
                bool fulfilled = true;
                for (const char* s: {"code", "date", "percent", "status"}) {
                    if (data[s].empty()) {
                        fulfilled = false;
                        break;
                    }
                }
                if (fulfilled) {
                    if (!paymentOperations->create(deed, data)) {
                        log = paymentOperations->getInfo();
                        goto i;
                    }
                    baseLog = "Pagamento criado com sucesso!";
                    break;
                } else {
                    log = "Todos os campos são obrigatórios!";
                    goto i;
                }
            }
            goto i;
        case BACK:
            break;
    }
}

void PaymentMenu::setCode(Data& data) {
    Window log({COLS/4 + 2,4},{1, COLS});
    PaymentCode code;
    Form paymentCode({"Código de pagamento"}, {COLS/4 + 2, 5}, {6, 3*COLS/4 - 2});
    string info;

    i:
    werase(log.getWindow());
    mvwprintw(log.getWindow(), 0, 0, "%s", info.c_str());
    log.refreshWindow();

    paymentCode.chooseField();

    if (paymentCode.goBack) return;

    if (paymentCode.submit && !paymentCode.data["Código de pagamento"].empty()) {
        try {
            code.setPaymentCode(paymentCode.data["Código de pagamento"]);
            data["code"] = code.getCode();
            return;
        } catch(invalid_argument& e) {
            info = e.what();
        }
    }

    goto i;
}

void PaymentMenu::setDate(Data& data) {
    Date date;
    string log;
    Window info({0,4},{1, COLS});
    Form dateForm({"Dia", "Mês", "Ano"}, {COLS/4 + 2, 5}, {8, 3*COLS/4 - 2}, {2,2,4}, regex("[^0-9]"));

    i:
    werase(info.getWindow());
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    dateForm.chooseField();

    if (dateForm.goBack) return;
    if (dateForm.submit &&
        !dateForm.data["Dia"].empty() &&
        !dateForm.data["Mês"].empty() &&
        !dateForm.data["Ano"].empty())
        try {
            date.setDate(stoi(dateForm.data["Dia"]), stoi(dateForm.data["Mês"]), stoi(dateForm.data["Ano"]));

            int d, m, y;
            Deed deed = deedOperations->get(deeds, deedSelected);

            string emissionDate = deed.getEmissionDate();
            string expirationDate = deed.getExpirationDate();

            Date emission;

            vector<string> v = utils::split(emissionDate, "-");
            d = stoi(v[0]); m = stoi(v[1]); y = stoi(v[2]);
            emission.setDate(d, m, y);

            if (date < emission)
                throw logic_error("A data de pagamento deve ser posterior à data de emissão do título (" + emissionDate + ").");

            Date expiration;

            v = utils::split(expirationDate, "-");
            d = stoi(v[0]); m = stoi(v[1]); y = stoi(v[2]);
            expiration.setDate(d, m, y);

            if (expiration < date)
                throw logic_error("A data de pagamento deve preceder a data de vencimento do título (" + expirationDate + ").");

            data["date"] = date.getDate();
            return;
        } catch (invalid_argument& e) {
            log = e.what();
        } catch (logic_error& e) {
            log = e.what();
        }
    goto i;
}

void PaymentMenu::setPercent(Data& data) {
    Percent percent;
    string log;
    Window info({COLS/4-1,4},{1, COLS});
    Form value({"Valor (%)"}, {COLS/4 + 2, 5}, {6, 3*COLS/4 - 2}, {}, regex("[^0-9\\.]"));

    i:
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    value.chooseField();

    if (value.goBack) return;
    if (value.submit && !value.data["Valor (%)"].empty()) {
        try {
            double v = stod(value.data["Valor (%)"]);
            percent.setValue(v);
            data["percentValue"] = percent.getFormattedValue();
            data["percent"] = to_string(percent.getValue());
            return;
        } catch (invalid_argument& e) {
            log = e.what();
        }
    }

    goto i;
}

void PaymentMenu::setStatus(Data& data) {
    Window info({0, 16}, {1, COLS/4});
    info.refreshWindow();

    vector<string> options = Status::status;
    options.push_back("");
    options.push_back("Voltar");

    Menu status(options, {COLS/4 + 2, 5}, {7, 3*COLS/4 - 2});
    status.start();

    int i = status.getSelected();
    if (i != (int) options.size() - 1) {
        data["status"] = to_string(i);
        data["statusName"] = options[i];
    }
}
