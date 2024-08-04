#ifndef DOMAINS_DEED_CODE_HPP_INCLUDED
#define DOMAINS_DEED_CODE_HPP_INCLUDED

#include "../includes/alphanumerical_code.hpp"
#include "../includes/listing.hpp"

#include <regex>
#include <algorithm>

/**
 * @class DeedCode
 * @brief Class for deed code domain representation.
*/
class DeedCode : public AlphanumericalCode, public StringListing {
    private:
            /**
             * @private @memberof DeedCode
             * @brief Checks if code contains only valid characters and valid length.
             * @param code Reference to code string to be validated.
             * @throw invalid_argument if code is invalid.
            */
            void validate(string&) const;
    public:
            /**
             * @brief Constructor for class DeedCode.
             * Initializes the StringListing listing member with the deed code type list.
            */
            DeedCode() {
                listing = types;
            }

            /**
             * @public @memberof DeedCode
             * @brief Return deed code formatted.
             * @return _string_ Deed code type concatenated with deed code.
            */
            string getDeedCode() const;

            /**
             * @public @memberof DeedCode
             * @brief Set deed code.
             * @param code Reference to code string to be set.
             * @param type Index of deed code list item.
             * @throw invalid_argument if code is invalid or index not in types list.
            */
            void setDeedCode(string&, int);

            /**
             * @overload
             * @brief Set deed code with type input string, instead of index.
             * @param type Type string of deed code.
             * @throw invalid_argument if code is invalid or input type not in types list.
            */
            void setDeedCode(string&, string);

            /// @brief Deed code type list.
            static const vector<string> types;
};


inline string DeedCode::getDeedCode() const{
    return getItem() + getCode();
}

#endif // DOMAINS_DEED_CODE_HPP_INCLUDED
