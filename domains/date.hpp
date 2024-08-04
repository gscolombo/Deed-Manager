#ifndef DOMAINS_DATE_HPP_INCLUDED
#define DOMAINS_DATE_HPP_INCLUDED

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

/**
 * @class Date
 * @brief Class for date domain representation.
*/
class Date {
    private:
            int day;
            int month;
            int year;
            string date;

            /**
             * @brief Validates date.
             * @param day Day value in range [1, 31].
             * @param month Month value in range [1, 12].
             * @param year Year value in range [2000, 2100].
             * @throw invalid_argument If day, month or year are invalid.
            */
            void validate(int day, int month, int year) const;

            /**
             * @brief Format date.
             * @param day Day value in range [1, 31].
             * @param month Month value in range [1, 12].
             * @param year Year value in range [2000, 2100].
             * @return Formatted date in pattern DD-MM-YYYY
            */
            string formatDate(int day, int month, int year);
    public:
            int getDay() const; ///< @brief Return date day
            int getMonth() const; ///< @brief Return date month
            int getYear() const; ///< @brief Return date year

            /**
             * @brief Retrieve date as string.
             * @return Date formatted in pattern DD-MM-YYYY.
            */
            string getDate() const;

            /**
             * @brief Set date day.
             * @param day Day value in range [1, 31].
            */
            void setDay(int);

            /**
             * @brief Set date month.
             * @param month Month value in range [1, 12].
            */
            void setMonth(int);

            /**
             * @brief Set date year.
             * @param year Year value in range [2000, 2100].
            */
            void setYear(int);

            /**
             * @brief Set date.
             * @param day Day value in range [1, 31].
             * @param month Month value in range [1, 12].
             * @param year Year value in range [2000, 2100].
             * @throw invalid_argument If date parameters are invalid.
            */
            void setDate(int day, int month, int year);

            bool operator<(Date&);
};

inline int Date::getDay() const {
    return day;
};

inline int Date::getMonth() const {
    return month;
};

inline int Date::getYear() const {
    return year;
};

inline string Date::getDate() const {
    return date;
}

#endif // DOMAINS_DATE_HPP_INCLUDED
