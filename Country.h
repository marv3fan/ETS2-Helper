#ifndef ETS2HELPER_COUNTRY_H
#define ETS2HELPER_COUNTRY_H

#include <vector>
#include <string>

using namespace std;
class City;
class Country
{
public:
    vector<City*> CountryCities;
    string Name;

    void AddCity(City* InCity);

    Country(string CountryName)
        : Name(CountryName)
    {}
};
#endif
