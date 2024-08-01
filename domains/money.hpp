#ifndef DOMAINS_MONEY_HPP_INCLUDED
#define DOMAINS_MONEY_HPP_INCLUDED

#include "../includes/interval.hpp"
#include "../utils.hpp"
using namespace utils;

/**
 * @class Money
 * Class for money domain representation.
*/
class Money : public Interval {
    public:
            /**
             * @brief Constructor for the Money class. 
             * Initializes the Money object with a default interval of [0, 1000000].
             */
            Money()
            : Interval(0, 1000000){};

            /**
             * @brief Retrieve formatted value.
             * @return _string_ Value formatted in BRL pattern (R$ XX,XX).
            */
            string getFormattedValue() const;
};

#endif // DOMAINS_MONEY_HPP_INCLUDED
