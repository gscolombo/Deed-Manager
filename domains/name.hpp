#ifndef DOMAINS_NAME_HPP_INCLUDED
#define DOMAINS_NAME_HPP_INCLUDED

#include <string>
#include <vector>
#include <stdexcept>
#include <regex>

#include "../utils.hpp"

using namespace std;
using namespace utils;

/**
 * @class Name
 * Class for name domain representation.
*/
class Name {
    private:
            string fullName;
            string firstName;
            string secondName; ///< Surname

            /**
             * @brief Format name to a capitalized string.
             * @param name Reference to string to be formatted.
             * @return _string_ Capitalized name.
            */
            string formatName(string&);

            /**
             * @brief Validate name based on length, number of terms and valid characters.
             * @param name Reference to string name to be validated.
             * @throw invalid_argument if name is invalid.
            */
            void validate(string&) const;
    public:
            /**
             * @brief Get name and surname formatted.
             * @return _string_ Name and surname capitalized and separated by a space.
            */
            string getFullName() const;

            /**
             * @brief Get name and surname.
             * @return _vector<*string*>_ Vector of string containing the name and surname.
            */
            vector<string> getNames() const;

            /**
             * @brief Set name, surname and full name attributes.
             * @param name Reference to string name to be set.
             * @throw invalid_argument If name or surname is invalid.
            */
            void setNames(string&);
};

inline string Name::getFullName() const {
    return fullName;
}

inline vector<string> Name::getNames() const {
    return {firstName, secondName};
}

#endif // DOMAINS_NAME_HPP_INCLUDED
