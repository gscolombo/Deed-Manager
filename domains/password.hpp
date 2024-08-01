#ifndef DOMAINS_PASSWORD_HPP_INCLUDED
#define DOMAINS_PASSWORD_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>
#include <algorithm>
using namespace std;

/**
 * @class Password
 * Class for password domain representation.
*/
class Password {
    private:
            string password;

            /**
             * @brief Check if password consists of six digits.
             * @param password String reference of password to be validated.
             * @throw invalid_argument If password is not six digits.
            */
            void validate(string&) const;
    public:
            /// @brief Retrieve password.
            string getPassword() const;

            /**
             * @brief Set password if valid.
             * @param password String of password.
             * @throw invalid_argument If password is invalid.
            */
            void setPassword(string);
};

inline string Password::getPassword() const {
    return password;
}

#endif // DOMAINS_PASSWORD_HPP_INCLUDED
