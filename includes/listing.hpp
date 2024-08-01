#ifndef LISTING_HPP_INCLUDED
#define LISTING_HPP_INCLUDED

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * @class StringListing
 * Base class for listings.
*/
class StringListing {
    private:
            int index = -1;
    protected:
            vector<string> listing;
    public:
            /**
             * @public @memberof StringListing
             * @brief Set index of the listing vector.
             * @param index The index to be set.
             * @throw invalid_argument If index is out of bounds of list.
            */
            void setIndex(int);

            /**
             * @public @memberof StringListing
             * @brief Retrieve the list item corresponding to the setted index.
             * @return The item at the current index in the listing vector, or an empty string if the index is -1.
             */
            string getItem() const;

};
inline string StringListing::getItem() const {
    return index == -1 ? "" : listing[index];
}


#endif // LISTING_HPP_INCLUDED
