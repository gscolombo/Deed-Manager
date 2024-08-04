#ifndef DOMAINS_STATUS_HPP_INCLUDED
#define DOMAINS_STATUS_HPP_INCLUDED

#include "../includes/listing.hpp"

/**
 * @class Status
 * @brief Class representing the status domain.
 */
class Status : public StringListing {
public:
    public:
            /**
             * @brief Constructor for Status.
             * Initializes the StringListing listing member with the status list.
            */
            Status() {
                listing = status;
            }

    /// @brief The status list.
    ///
    /// Holds the list of statuses.
    static const vector<string> status;
};

#endif // DOMAINS_STATUS_HPP_INCLUDED
