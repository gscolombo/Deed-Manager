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

/**
 * @class Form
 * @brief A class representing a form window.
 *
 * This class inherits from the `Window` class and represents a form window
 * in the view. It is used to display a set of fields and their corresponding
 * values to the user, and to allow the user to interact with these fields.
 */
class Form: public Window {
    private:
        vector<int> maxChars;  // Maximum number of characters allowed in each field
        regex ignore;         // Regex for invalid characters in fields
        vector<string> fields; // List of field names
        pair<int,string> selected, highlight; // Currently selected field and its name

        WINDOW* window; // Window object
        /**
         * @brief Refreshes the form window.
         *
         * This function refreshes the form window by redrawing all the fields
         * and their corresponding values. It is called automatically by the
         * constructor and whenever the window needs to be updated.
         */
        void refreshWindow() override;
    public:
        /**
         * @brief Constructs a Form object.
         *
         * This constructor initializes the form window with the given field names,
         * position, dimensions, maximum character limits, and invalid character regex.
         *
         * @param fields List of field names
         * @param p Position of the top-left corner of the window
         * @param d Dimensions of the window
         * @param maxChars Maximum number of characters allowed in each field
         * @param ignore Regex for invalid characters in fields
         */
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

        /**
         * @brief Fills the i-th field of the form.
         *
         * This function allows the user to enter values for the i-th field of the form.
         *
         * @param i Index of the field to be filled.
         */
        void fillForm(int i = 0);

        /**
         * @brief Allows the user to interact with the form.
         *
         * This function allows the user to interact with the form by selecting
         * fields.
         */
        void chooseField();

        bool submit, goBack; // Flags to indicate submit and back actions
        Data data; // Data entered by the user
};

#endif // VIEW_FORM_HPP_INCLUDED
