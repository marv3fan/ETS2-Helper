#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include "Country.h"
#include "Garage.h"
class Country;

class City
{
private:
    Garage::GarageType garageType;
public:
    const char* Name;
    const Country &CityCountry;
    const double Latitude;
    const double Longitude;

   City(const char* CityName, Country &InCountry, double Lat, double Lon, Garage::GarageType GarageType)
        : garageType(GarageType), Name(CityName), CityCountry(InCountry), Latitude(Lat), Longitude(Lon)
    {}

    Garage::GarageType GarageType();
};

#endif // CITY_H_INCLUDED
