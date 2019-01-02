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
        const double Latitude;
        const double Longitude;

        City(const char* CityName, Country &InCountry, double Lat, double Lon)
            : Name(CityName), CityCountry(InCountry), Latitude(Lat), Longitude(Lon)
            {}
};

#endif // CITY_H_INCLUDED
