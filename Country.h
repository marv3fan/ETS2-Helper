#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED
#include <vector>

#include "City.h"
class City;

class Country
{
public:
    std::vector<City> CountryCities;
    const char* Name;

    void AddCity(City& InCity);
    Country(const char* CountryName)
        : Name(CountryName)
    {}
};
#endif // COUNTRY_H_INCLUDED
