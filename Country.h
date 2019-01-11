#ifndef ETS2HELPER_COUNTRY_H
#define ETS2HELPER_COUNTRY_H

#include <string>
#include <vector>

#include "City.h"

namespace ets2helper {

class Country {
  public:
    std::vector<City*> CountryCities;
    std::string Name;

    static int GetCountryIndex();
    static void PopulateCountries();

    Country(const Country&) = delete;
    Country& operator=(const Country&) = delete;

    inline Country(std::string CountryName)
        : Name(CountryName)
    {}

    inline void AddCity(City* InCity) {
        Country::CountryCities.push_back(InCity);
    };
};

}  //namespace ets2helper
#endif
