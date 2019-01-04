#ifndef COUNTRY_H_INCLUDED
#define COUNTRY_H_INCLUDED

#include <vector>
#include <string>
#include "City.h"

using namespace std;

class Country
{
public:
    vector<City> CountryCities;
    string Name;

    void AddCity(City& InCity);
    Country(string CountryName)
        : Name(CountryName)
    {}
};
#endif // COUNTRY_H_INCLUDED
