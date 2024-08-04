#ifndef DOMAINS_SECTOR_HPP_INCLUDED
#define DOMAINS_SECTOR_HPP_INCLUDED

#include "../includes/listing.hpp"

/**
 * @class Sector
 * @brief Class for sector domain representation.
*/
class Sector : public StringListing {
    public:
            /**
             * @brief Constructor for Sector.
             * Initializes the StringListing listing member with the sector list.
            */
            Sector() {
                listing = sectors;
            }

            /// @brief Sector list.
            static const vector<string> sectors;
};

#endif // DOMAINS_SECTOR_HPP_INCLUDED
