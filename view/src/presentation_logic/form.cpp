#include "presentation_logic/form.hpp"
#include <iostream>

void Form::refreshWindow() {
    int i = 1;
    for (const string& f : fields) {
        if (f == "Enviar" || f == "Voltar") {
            if (highlight.second == f)
                wattron(window, A_BOLD);
            mvwprintw(window, ++i, 1, "%s", f.c_str());
            wattroff(window, A_BOLD);
            continue;
        }

        string label = f + ":";

        if (!data.count(f))
            data[f] = "";

        if (highlight.first == i-1) {
            wattron(window, A_BOLD);
            mvwprintw(window, i, 1, "%s", label.c_str());
            wattroff(window, A_BOLD);
        } else {
            mvwprintw(window, i, 1, "%s", label.c_str());
        }
        i++;
    }

    box(window,0,0);
    wrefresh(window);
}

void Form::fillForm(int i) {
    string label = fields[i];

    refreshWindow();

    curs_set(1);
    wmove(window, i + 1, (int) (label + ":").size() + 2);
    wclrtoeol(window);
    box(window,0,0);

    string tmp = "";
    int ch;
    int base = (int) (label + ":").size() + 2;
    while ((ch = wgetch(window)) != 10) {
        if (ch == KEY_BACKSPACE && (int) tmp.size() > 0) {
            wclrtoeol(window);
            mvwdelch(window, i + 1, --base);
            tmp.pop_back();
            box(window,0,0);
            wrefresh(window);
        } else if (ch != KEY_BACKSPACE && (int) tmp.size() < maxChars[i] && !regex_match(string(1, ch), ignore)) {
            label == "Senha" ? waddch(window, '*') : waddch(window, ch);
            wrefresh(window);
            tmp += ch;
            base++;
        }
    }
    data[label] = tmp;

    refreshWindow();
}

void Form::chooseField() {
    i:
    keypad(window, TRUE);
    curs_set(0);
    int ch;

    selected = {-1,""}; submit = false; goBack = false;
    while (selected.first == -1) {
        switch((ch = wgetch(window))) {
            case KEY_UP:
                highlight.first--;
                if (highlight.first < 0) highlight.first = (int) fields.size() - 1;
                break;
            case KEY_DOWN:
                highlight.first++;
                if (highlight.first > (int) fields.size() - 1) highlight.first = 0;
                break;
            case 10:
                selected = highlight;
                if (highlight.second == "Enviar")
                    submit = true;
                else if (highlight.second == "Voltar")
                    goBack = true;
                else {
                    fillForm(selected.first);
                    goto i;
                }
                break;
        }
        highlight.second = fields[highlight.first];
        printw("%s", highlight.second.c_str());
        refreshWindow();
    }
}




