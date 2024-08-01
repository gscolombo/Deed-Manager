#include "percent.hpp"

#include <iostream>

string Percent::getFormattedValue() const {
    if ((int) value == value) {
        return to_string((int) value) + "%";
    } else {
        string s = to_string(value);
        for (int i = s.size() - 1, n = 0; n < 4; n++, --i) {
            if (s[i] == '1')
                break;

            s.replace(i,1,"");
        }
        return s.replace(s.find("."), 1, ",") + "%";
    }
}
