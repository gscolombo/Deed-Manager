#ifndef DOMAINS_PERCENT_HPP_INCLUDED
#define DOMAINS_PERCENT_HPP_INCLUDED

#include "../includes/interval.hpp"
#include "../utils.hpp"
using namespace utils;

#include <math.h>

/**
 * @class Percent
 * @brief Class for percent domain representation.
*/
class Percent : public Interval {
    public:
            /**
             * Constructor for the Percent class.
             *
             * Initializes the Percent object with a default value of 0 to 100,
             * representing a percentage interval.
             */
            Percent()
            : Interval(0, 100) {};

            /// @brief Get percent value formatted.
            /// @return _string_ Percent value with trailing "%" symbol.
            string getFormattedValue() const;
};

#endif // PERCENT_HPP_INCLUDED
