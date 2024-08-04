#include "operations/deed_menu.hpp"

void DeedMenu::init() {
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
            list<Deed> deeds = operations->listing(user);
            if (deeds.size() >= 5)
                baseLog = "Conta já possui número máximo (5) de títulos.";
            else
                create();
        }
            goto i;
        case LIST:
        {
            werase(menu.getWindow());
            wrefresh(menu.getWindow());
            listing();
            goto i;
        }
    }

    deedRead = nullptr;
}

void DeedMenu::listing() {
    list<Deed> deeds = operations->listing(user);
    if (deeds.empty()) {
        baseLog = "Conta não possui títulos cadastrados.";
        return;
    }

    vector<string> deedCodeListing;

    for (const Deed& deed : deeds) {
        deedCodeListing.push_back(deed.getDeedCode());
    }

    deedCodeListing.push_back("");
    deedCodeListing.push_back("Fechar");

    Menu deedsListingMenu(deedCodeListing, {0, 5}, {(int) deedCodeListing.size() + 2,COLS/4});

    i:
    deedsListingMenu.start();

    int i = deedsListingMenu.getSelected();
    if (i < (int) deedCodeListing.size() - 1) {
        Deed deed = operations->get(deeds, i);
        list<string> details = operations->read(deed);
        deedRead = &deed;

        List deedDetails(details, {COLS/4, 5}, {7, 3*COLS/4 - 10});
        Menu commands({"Editar", "Deletar", "", "", "Voltar"}, {COLS - 10,5}, {7, 10});

        deedDetails.show();
        commands.start();

        switch(commands.getSelected()) {
            case 0:
            {
                string pk = deed.getDeedCode();
                string fk = user.getCPFDomain().getCode();
                update(pk, fk);
            }
            break;
            case 1:
            {
                string pk = deed.getDeedCode();
                string fk = user.getCPFDomain().getCode();
                del(pk, fk);
            }
            break;
            case 4:
                goto i;
        }
    }
}

void DeedMenu::del(string& pk, string& fk) {
    Data data;

    data["code"] = pk;
    data["cpf"] = fk;

    Window confirmation({0,13}, {5,COLS});
    mvwprintw(confirmation.getWindow(), 1, 1, "Você tem certeza que deseja deletar esse título?");
    mvwprintw(confirmation.getWindow(), 2, 1, "Todos os pagamentos associados a esse título também serão excluídos.");
    mvwprintw(confirmation.getWindow(), 3, 1, "Essa operação é irreversível.");
    box(confirmation.getWindow(), 0, 0);
    confirmation.refreshWindow();

    Menu confirm({"Deletar", "Cancelar"}, {0,18}, {4, 10});
    confirm.start();

    if (!confirm.getSelected()) {
        if (!operations->del(data))
            baseLog = operations->getInfo();
        else
            baseLog = "Título deletado com sucesso.";
    }
}

void DeedMenu::update(string& pk, string& fk) {
    Data data;
    string log;

    vector<string> options = { "Emissor", "Setor", "Data de emissão", "Data de vencimento", "Valor", "", "Salvar", "Voltar" };
    enum Option { EMITTER, SECTOR, EMISSION_DATE, EXPIRATION_DATE, VALUE, SAVE = 6, BACK };

    data["code"] = pk;
    data["cpf"] = fk;

    i:
    Window info({0,4},{1, COLS});
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    Window preSubmission({COLS/4,5}, {9, 3*COLS/4});
    mvwprintw(preSubmission.getWindow(), 1, 1, "Caso não deseje alterar um dado, deixe o campo em branco.");

    mvwprintw(preSubmission.getWindow(), 3, 1, "%s", ("Emissor: " + data["emitter"]).c_str());
    mvwprintw(preSubmission.getWindow(), 4, 1, "%s", ("Setor: " + data["sectorName"]).c_str());
    mvwprintw(preSubmission.getWindow(), 5, 1, "%s", ("Data de emissão: " + data["emissionDate"]).c_str());
    mvwprintw(preSubmission.getWindow(), 6, 1, "%s", ("Data de vencimento: " + data["expirationDate"]).c_str());
    mvwprintw(preSubmission.getWindow(), 7, 1, "%s", ("Valor: " + data["valueBRL"]).c_str());
    box(preSubmission.getWindow(), 0, 0);
    preSubmission.refreshWindow();

    Menu attributes(options, {0, 5}, {10,COLS/4});
    attributes.start();

    preSubmission.closeWindow();
    switch((Option) attributes.getSelected()) {
        case EMITTER:
            setEmitter(data);
            goto i;
        case SECTOR:
            setSector(data);
            goto i;
        case EMISSION_DATE:
            setDate(data, "emissionDate");
            goto i;
        case EXPIRATION_DATE:
            setDate(data, "expirationDate");
            goto i;
        case VALUE:
            setValue(data);
            goto i;
        case SAVE:
            {
                bool any = false;
                for (const char* s: {"emitter", "sector", "emissionDate", "expirationDate", "value"}) {
                    if (!data[s].empty()) {
                        any = true;
                        break;
                    }
                }
                if (any) {
                    if (!operations->update(user, data)) {
                        log = operations->getInfo();
                        goto i;
                    }
                    baseLog = "Título atualizado com sucesso!";
                    break;
                }
            }
            goto i;
        case BACK:
            break;
    }
}

void DeedMenu::create() {
    Data data;
    string log;

    vector<string> options = {"Código de título", "Emissor", "Setor", "Data de emissão", "Data de vencimento", "Valor", "", "Salvar", "Voltar"};
    enum Option { CODE, EMITTER, SECTOR, EMISSION_DATE, EXPIRATION_DATE, VALUE, SAVE = 7, BACK};

    i:
    Window info({0,4},{1, COLS});
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    Window preSubmission({COLS/4,5}, {10, 3*COLS/4});
    wattron(preSubmission.getWindow(), A_ITALIC);
    mvwprintw(preSubmission.getWindow(), 1, 1, "Novo título");
    wattroff(preSubmission.getWindow(), A_ITALIC);

    mvwprintw(preSubmission.getWindow(), 3, 1, "%s", ("Código de título: " + data["code"]).c_str());
    mvwprintw(preSubmission.getWindow(), 4, 1, "%s", ("Emissor: " + data["emitter"]).c_str());
    mvwprintw(preSubmission.getWindow(), 5, 1, "%s", ("Setor: " + data["sectorName"]).c_str());
    mvwprintw(preSubmission.getWindow(), 6, 1, "%s", ("Data de emissão: " + data["emissionDate"]).c_str());
    mvwprintw(preSubmission.getWindow(), 7, 1, "%s", ("Data de vencimento: " + data["expirationDate"]).c_str());
    mvwprintw(preSubmission.getWindow(), 8, 1, "%s", ("Valor: " + data["valueBRL"]).c_str());
    box(preSubmission.getWindow(), 0, 0);
    preSubmission.refreshWindow();

    Menu attributes(options, {0, 5}, {11,COLS/4});
    attributes.start();

    preSubmission.closeWindow();
    switch((Option) attributes.getSelected()) {
        case CODE:
            setCode(data);
            goto i;
        case EMITTER:
            setEmitter(data);
            goto i;
        case SECTOR:
            setSector(data);
            goto i;
        case EMISSION_DATE:
            setDate(data, "emissionDate");
            goto i;
        case EXPIRATION_DATE:
            setDate(data, "expirationDate");
            goto i;
        case VALUE:
            setValue(data);
            goto i;
        case SAVE:
            {
                bool fulfilled = true;
                for (const char* s: {"code", "emitter", "sector", "emissionDate", "expirationDate", "value"}) {
                    if (data[s].empty()) {
                        fulfilled = false;
                        break;
                    }
                }
                if (fulfilled) {
                    data["cpf"] = user.getCPFDomain().getCode();
                    if (!operations->create(user, data)) {
                        log = operations->getInfo();
                        goto i;
                    }
                    baseLog = "Título cadastrado com sucesso!";
                    break;
                }  else log = "Todos os campos são obrigatórios!";
            }
            goto i;
        case BACK:
            break;
    }
}

void DeedMenu::setCode(Data& data) {
    DeedCode code;
    string type;

    Window instruction({0, 16}, {1, COLS/4});
    mvwprintw(instruction.getWindow(), 0, 0, "Escolha um tipo.");
    instruction.refreshWindow();

    vector<string> options = DeedCode::types;
    options.push_back("");
    options.push_back("Voltar");

    Menu types(options, {COLS/4, 5}, {10, 8});
    i: types.start();

    int i = types.getSelected();
    if (i != (int) options.size() - 1) {
        type = options[i];

        string log;
        Window info({COLS/4,4},{1, COLS});
        Form deedCode({"Código"}, {COLS/4+8, 5}, {6, 3*COLS/4-8});

        mvwprintw(instruction.getWindow(), 0, 0, "Escreva o código.");
        instruction.refreshWindow();

        j:
        mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
        info.refreshWindow();

        deedCode.chooseField();
        if (deedCode.goBack) goto i;
        if (deedCode.submit && !deedCode.data["Código"].empty()) {
            try {
                code.setDeedCode(deedCode.data["Código"], type);
            } catch(invalid_argument& e) {
                log = e.what();
                goto j;
            }
            data["code"] = code.getDeedCode();
        }
    }
}

void DeedMenu::setEmitter(Data& data) {
    Window log({COLS/4,4},{1, COLS});
    Name name;
    Form emitter({"Nome"}, {COLS/4, 5}, {6, 3*COLS/4});
    string info;

    i:
    werase(log.getWindow());
    mvwprintw(log.getWindow(), 0, 0, "%s", info.c_str());
    log.refreshWindow();

    emitter.chooseField();

    if (emitter.submit && !emitter.data["Nome"].empty()) {
        try {
            name.setNames(emitter.data["Nome"]);
        } catch(invalid_argument& e) {
            info = e.what();
            goto i;
        }
        data["emitter"] = emitter.data["Nome"];
    }
}

void DeedMenu::setSector(Data& data) {
    Window info({0, 16}, {1, COLS/4});
    mvwprintw(info.getWindow(), 0, 0, "Escolha um setor.");
    info.refreshWindow();

    vector<string> options = Sector::sectors;
    options.push_back("");
    options.push_back("Voltar");

    Menu sectors(options, {COLS/4, 5}, {14, 3*COLS/4});
    sectors.start();

    int i = sectors.getSelected();
    if (i != (int) options.size() - 1) {
        data["sector"] = to_string(i);
        data["sectorName"] = options[i];
    }
}

void DeedMenu::setDate(Data& data, const string& key) {
    Date d1;
    string log;
    Window info({COLS/4,4},{1, COLS});
    Form date({"Dia", "Mês", "Ano"}, {COLS/4, 5}, {8, 3*COLS/4}, {2,2,4}, regex("[^0-9]"));

    i:
    werase(info.getWindow());
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    date.chooseField();

    if (date.goBack) return;
    if (date.submit &&
        !date.data["Dia"].empty() &&
        !date.data["Mês"].empty() &&
        !date.data["Ano"].empty())
        try {
            d1.setDate(stoi(date.data["Dia"]), stoi(date.data["Mês"]), stoi(date.data["Ano"]));
            Date d2;
            int d, m, y;
            vector<string> v;

            if (!data["expirationDate"].empty() || !data["emissionDate"].empty()) {
                v = utils::split(data[(key == "emissionDate" ? "expirationDate" : "emissionDate")],"-");
                d = stoi(v[0]); m = stoi(v[1]); y = stoi(v[2]);
                d2.setDate(d,m,y);

                if ((key == "emissionDate" && d2 < d1) || (key == "expirationDate" && d1 < d2)) {
                    throw logic_error("A data de emissão não pode ser após a data de validade!");
                }
            } else if (deedRead != nullptr) {
                v = utils::split((key == "emissionDate" ? deedRead->getExpirationDate() : deedRead->getEmissionDate()),"-");
                d = stoi(v[0]); m = stoi(v[1]); y = stoi(v[2]);
                d2.setDate(d,m,y);

                if ((key == "emissionDate" && d2 < d1) || (key == "expirationDate" && d1 < d2)) {
                    throw logic_error("A data de emissão não pode ser após a data de validade!");
                }
            }
            data[key] = d1.getDate();
            return;
        } catch (invalid_argument& e) {
            log = e.what();
        } catch (logic_error& e) {
            log = e.what();
        }
    goto i;
}

void DeedMenu::setValue(Data& data) {
    Money money;
    string log;
    Window info({COLS/4-1,4},{1, COLS});
    Form value({"Valor"}, {COLS/4, 5}, {6, 3*COLS/4}, {}, regex("[^0-9\\.]"));

    i:
    mvwprintw(info.getWindow(), 0, 1, "%s", log.c_str());
    info.refreshWindow();

    value.chooseField();

    if (value.goBack) return;
    if (value.submit && !value.data["Valor"].empty()) {
        try {
            double v = stod(value.data["Valor"]);
            money.setValue(v);
            data["valueBRL"] = money.getFormattedValue();
            data["value"] = to_string(money.getValue());
            return;
        } catch (invalid_argument& e) {
            log = e.what();
        }
    }

    goto i;
}
