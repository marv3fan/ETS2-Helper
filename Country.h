#ifndef ETS2HELPER_COUNTRY_H
#define ETS2HELPER_COUNTRY_H

#include <string>
#include <vector>

#include "City.h"

using namespace std;

class Country
{
public:
    vector<City*> CountryCities;
    string Name;

    inline Country(string CountryName)
        : Name(CountryName)
    {}

    inline void AddCity(City* InCity)
    {
        CountryCities.push_back(InCity);
    };
};
#endif
