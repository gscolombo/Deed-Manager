#ifndef DOMAINS_CPF_HPP_INCLUDED
#define DOMAINS_CPF_HPP_INCLUDED

#include "../includes/alphanumerical_code.hpp"
#include "../utils.hpp"
using namespace utils;

#include <stdexcept>

/**
 * @class CPF
 * Class for CPF domain representation.
*/
class CPF : public AlphanumericalCode {
    private:
            /**
             * @private @memberof CPF
             * Validate code according to CPF standards and its validation digits.
             * Validation digits are calculated based on the explanation
             * at https://www.calculadorafacil.com.br/computacao/validar-cpf.
             *
             * @throw invalid_argument
            */
            void validate(string&) const;
    public:
            /**
             * @public @memberof CPF
             * @brief Set CPF if valid.
             * @param code Reference to code string to be set.
             * @throw invalid_argument If CPF is invalid.
            */
            void setCPF(string&);

            /**
             * @brief Retrieve CPF validation digits.
             * @return _string_ Validation digits.
            */
            string getValidationCode() const ;

            /**
             * @brief Retrieve CPF in standard format.
             * @return _string_ CPF in pattern XXX.XXX.XXX-CC
            */
            string getCPF() const;
};

inline string CPF::getValidationCode() const {
    return getCode().substr(9,2);
}

inline string CPF::getCPF() const {
    string c = getCode();
    return c.substr(0,3) + "." + c.substr(3,3) + "." + c.substr(6,3) + "-" + c.substr(9,2);
}

#endif // DOMAINS_CPF_HPP_INCLUDED
