#ifndef INTERVAL_HPP_INCLUDED
#define INTERVAL_HPP_INCLUDED

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @class Interval
 * Abstract class for intervals with defined bound.
*/
class Interval {
    private:
            double MIN_LIMIT;
            double MAX_LIMIT;
            /**
             * @private @memberof Interval
             * Validate that the value is in the allowed range
             *
             * @throw invalid_argument
            */
            void validate(double&);
    protected:
            double value;
    public:
            /**
             * Constructor for the Interval class. Initializes the minimum and maximum
             * values of the interval.
             *
             * @param min_value the minimum value of the interval
             * @param max_value the maximum value of the interval
             */
            Interval(double min_value, double max_value) {
                MIN_LIMIT = min_value;
                MAX_LIMIT = max_value;
            }
            void setValue(double value); ///< @brief Set value if it is in the allowed range
            double getValue() const; ///< @brief Retrieve value

            /// @brief Virtual function that returns a string representation of the value
            virtual string getFormattedValue() const = 0;
};

inline double Interval::getValue() const {
    return value;
}

#endif // INTERVAL_HPP_INCLUDED
