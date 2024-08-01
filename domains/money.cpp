#include "money.hpp"

string Money::getFormattedValue() const {
    double m = toPrecision(value, 2);
    string r = to_string(m);

    int integralTermLength = split(r, ".")[0].size();
    int i = integralTermLength%3 ?: 3; // Set index reference for dots

    r = r.replace(integralTermLength,1, ""); // Remove dot character for convenience

    if (integralTermLength > 3) {
        if (integralTermLength > 6) // The value can only be 1.000.000,00 in this case
            r = r.substr(0,1) + "." + r.substr(1,3) + "." + r.substr(4,3) + "," + r.substr(7,2);
        else
            r = r.substr(0,i) + "." + r.substr(i,3) + "," + r.substr(i+3,2); // The value contains only one dot
    } else if (integralTermLength > 1)
        r = r.substr(0,i) + "," + r.substr(i,2); // The value don't have any dot and is greater than or equal to 1
    else
        r = "0," + r.substr(1,2); // The value is a decimal, so it first character is a 0

    return "R$ " + r;
}
