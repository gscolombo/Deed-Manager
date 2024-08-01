#include "utils.hpp"

#include <iostream>

namespace utils
{
    string trim(string &str, bool l, bool r) {

        if (str[0] != ' ' && *(str.end()-1) != ' ')
            return str;

        if (str[0] == ' ' && l) {
            str.erase(0, str.find_first_not_of(" "));
            if (!r)
                return str;
        }

        if (*(str.end()-1) == ' ' && r)
            str.erase(str.find_last_not_of(" ")+1);

        return str;
    }

    vector<string> split(string str, string del) {
        size_t pos = 0;
        size_t found;
        vector<string> terms;

        // Iterate over input string while the delimiter string is found
        while ((found = str.find(del, pos)) != string::npos) {
            // Push to output vector the substring before the last delimiter character found
            terms.push_back(str.substr(pos, found - pos));
            pos = found + del.size();
        }
        terms.push_back(str.substr(pos));
        return terms;
    }


    double toPrecision(double d, int precision) {
        double p = pow(10, -precision);
        return round(d / p) * p;
    }
}
