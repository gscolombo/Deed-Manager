#ifndef ENTITIES_DEED_HPP_INCLUDED
#define ENTITIES_DEED_HPP_INCLUDED

#include "../domains/deed_code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/sector.hpp"
#include "../domains/money.hpp"

#include <tuple>

/**
 * @class Deed
 * Class for deed entity representation.
*/
class Deed {
    private:
            DeedCode deed;
            Name emitter;
            Sector sector;
            Date emissionDate;
            Date expirationDate;
            Money value;
    public:
            /**
             * Constructor for the Deed class.
             * The tuple with deed code information (**deedInfo**) can only be of type <_string_,_int_> or <_string_,_string_>, to satisfy the
             * requirements of the DeedCode class.
             *
             * @param deedInfo tuple containing information for the deed (_index for deed type list_ or _deed type string_, _code string_)
             * to set the deed code
             * @param name name of the emitter
             * @param sector sector of the deed
             * @param emissionDate tuple representing the emission date (_day_, _month_, _year_)
             * @param expirationDate tuple representing the expiration date (_day_, _month_, _year_)
             * @param value value of the deed
             *
             * @throws None
             */
            template<typename T>
            Deed(tuple<string,T> deedInfo,
                 string name,
                 int sector,
                 tuple<int,int,int>emissionDate,
                 tuple<int,int,int>expirationDate,
                 double value
                 )
            {
                deed.setDeedCode(get<0>(deedInfo), get<1>(deedInfo));
                emitter.setNames(name);

                this->sector.setIndex(sector);

                this->emissionDate.setDate(get<0>(emissionDate), get<1>(emissionDate), get<2>(emissionDate));
                this->expirationDate.setDate(get<0>(expirationDate), get<1>(expirationDate), get<2>(expirationDate));

                this->value.setValue(value);
            }

            string getDeedCode() const; ///< @brief Retrieve deed code formatted.
            string getEmitterName() const; ///< @brief Retrieve emitter name formatted.
            string getSector() const; ///< @brief Retrieve sector name
            string getEmissionDate() const; ///< @brief Retrieve emission date formatted as DD-MM-YYYY
            string getExpirationDate() const; ///< @brief Retrieve expiration date formatted as DD-MM-YYYY
            string getValueInBRL() const; ///< @brief Retrieve value formatted in BRL pattern (R$ XX,XX)
            double getValue() const; ///< @brief Retrieve value
};

inline string Deed::getDeedCode() const {
    return deed.getDeedCode();
}

inline string Deed::getEmitterName() const {
    return emitter.getFullName();
}

inline string Deed::getSector() const {
    return sector.getItem();
}

inline string Deed::getEmissionDate() const {
    return emissionDate.getDate();
}

inline string Deed::getExpirationDate() const {
    return expirationDate.getDate();
}

inline string Deed::getValueInBRL() const {
    return value.getFormattedValue();
}

inline double Deed::getValue() const {
    return value.getValue();
}

#endif // ENTITIES_DEED_HPP_INCLUDED
