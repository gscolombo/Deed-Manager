#include "interval.hpp"

void Interval::validate(double& d) {
    if (d < MIN_LIMIT || d > MAX_LIMIT)
        throw invalid_argument("O valor está fora do intervalo ["
                                + to_string(int(MIN_LIMIT))
                                + ","
                                + to_string(int(MAX_LIMIT))
                                + "].");
}

void Interval::setValue(double d) {
    validate(d);
    value = d;
}
