#include "listing.hpp"

#include <iostream>
using namespace std;

void StringListing::setIndex(int i) {
    if (i < 0 || i > (int) listing.size() - 1)
        throw invalid_argument("Index is out of bounds of list.");
    index = i;
}
