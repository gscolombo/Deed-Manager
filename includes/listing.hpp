#ifndef LISTING_HPP_INCLUDED
#define LISTING_HPP_INCLUDED

#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * @class StringListing
 * @brief Base class for listings.
*/
class StringListing {
    private:
            /**
             * @private @memberof StringListing
             * @brief The current index of the listing vector.
             * @details If the index is set to -1, it means that no item is to be retrieved.
             */
            int index = -1;
    protected:
            /**
             * @protected @memberof StringListing
             * @brief The vector containing the list items.
             */
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
