#ifndef DOMAINS_STATUS_HPP_INCLUDED
#define DOMAINS_STATUS_HPP_INCLUDED

#include "../includes/listing.hpp"

class Status : public StringListing {
    public:
            /**
             * @brief Constructor for Status.
             * Initializes the StringListing listing member with the status list.
            */
            Status() {
                listing = status;
            }

            /// @brief Status list.
            static const vector<string> status;
};

#endif // DOMAINS_STATUS_HPP_INCLUDED
