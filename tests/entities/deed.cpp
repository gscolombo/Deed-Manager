#include "deed.hpp"

bool UTDeed::checkGetters(Deed deed, int i, bool fromType = false) {
    return  (fromType ?
                deed.getDeedCode() == get<1>(deedsFromType[i]) + get<0>(deedsFromType[i]) :
                deed.getDeedCode() == DeedCode::types[get<1>(deedsFromIndex[i])] + get<0>(deedsFromIndex[i])) &&
                deed.getEmitterName() == names[i] &&
                deed.getSector() == Sector::sectors[sectors[i]] &&
                deed.getEmissionDate() == formattedEmissionDates[i] &&
                deed.getExpirationDate() == formattedExpirationDates[i] &&
                deed.getValueInBRL() == formattedValues[i] &&
                deed.getValue() == values[i];
}

void UTDeed::runTests() {
    try {
        for (int i = 0; i < 3; i++) {
            Deed di(deedsFromIndex[i], names[i], sectors[i], emissionDates[i], expirationDates[i], values[i]);
            Deed dt(deedsFromType[i], names[i], sectors[i], emissionDates[i], expirationDates[i], values[i]);
            if (checkGetters(di, i) && checkGetters(dt, i, true))
                continue;
            throw 0;
        }
        passed++;
        report.push_back("Instantiante account entity - SUCCESS");
    } catch(...) {
        report.push_back("Instantiante account entity - FAILURE");
    }
}
