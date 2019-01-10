#ifndef ETS2HELPER_COUNTRY_H
#define ETS2HELPER_COUNTRY_H

#include <string>
#include <vector>

#include "City.h"

namespace ets2helper
{

class Country
{
public:
    static std::vector<Country*> AllCountries;
    std::vector<City*> CountryCities;
    std::string Name;

    static void PopulateCountries();

    inline Country(std::string CountryName)
        : Name(CountryName)
    {}

    inline void AddCity(City* InCity)
    {
        Country::CountryCities.push_back(InCity);
    };
};

}  //namespace ets2helper
#endif
