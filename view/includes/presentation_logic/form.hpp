#ifndef VIEW_FORM_HPP_INCLUDED
#define VIEW_FORM_HPP_INCLUDED

#include "window.hpp"
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <regex>
#include <limits>

typedef map<string,string> Data;

class Form: public Window {
    private:
        vector<int> maxChars;
        regex ignore;
        vector<string> fields;
        pair<int,string> selected, highlight;

        WINDOW* window;
        void refreshWindow() override;
    public:
        Form(vector<string> fields,
             array<int,2> p = {},
             array<int,2> d = {},
             vector<int> maxChars = {},
             regex ignore = regex("[^A-Za-z0-9\\s]"))
        : Window(p,d)
        {
            window = getWindow();

            if (maxChars.empty()) {
                for (int i = 0; i < (int) fields.size(); i++) {
                    this->maxChars.push_back(numeric_limits<int>::max());
                }
            } else this->maxChars = maxChars;

            this->ignore = ignore;
            this->fields = fields;
            this->submit = submit;

            this->fields.push_back("Enviar");
            this->fields.push_back("Voltar");
            highlight = {0, fields[0]};

            refreshWindow();
        };

        void fillForm(int);
        void chooseField();

        bool submit, goBack;
        Data data;
};

#endif // VIEW_FORM_HPP_INCLUDED
