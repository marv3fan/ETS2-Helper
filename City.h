#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include "Country.h"
class Country;

class City
{
    private:
    public:
        const char* Name;
        const Country &CityCountry;

        double Latitude = 0.0000000;
        double Longitude = 0.0000000;
        City(const char* CityName, Country &InCountry)
            : Name(CityName), CityCountry(InCountry)
            {}
};

#endif // CITY_H_INCLUDED
