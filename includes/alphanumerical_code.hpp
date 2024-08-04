#ifndef ALPHANUMERICAL_CODE_HPP_INCLUDED
#define ALPHANUMERICAL_CODE_HPP_INCLUDED

#include <string>
#include <stdexcept>
using namespace std;

/**
 * @class AlphanumericalCode
 * @brief Abstract class for alphanumerical codes.
*/
class AlphanumericalCode {
    private:
            /**
             * @private @memberof AlphanumericalCode
             * Alphanumerical code to be validated.
            */
            string code;
    protected:
            /**
             * @protected @memberof AlphanumericalCode
             * Custom validation of code to be implemented.
             *
             * @throw invalid_argument
            */
            virtual void validate(string&) const = 0;
            virtual ~AlphanumericalCode(){};
    public:
            /**
             * @brief Get the alphanumerical code.
             * 
             * @return The code string.
             */
            string getCode() const;

            /**
             * @brief Set the alphanumerical code.
             * 
             * @param code The code string to set.
             */
            void setCode(string&);

};

inline string AlphanumericalCode::getCode() const {
    return code;
}

inline void AlphanumericalCode::setCode(string& code) {
    this->code = code;
}

#endif // ALPHANUMERICAL_CODE_HPP_INCLUDED
