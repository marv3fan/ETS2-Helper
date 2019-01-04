#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include <fstream>
#include <string>
#include "Country.h"
#include "Garage.h"

using namespace std;

class Country;

class City
{
private:
    Garage::GarageType garageType;
public:
    string Name;
    const Country &CityCountry;
    const double Latitude;
    const double Longitude;

    City(string CityName, Country &InCountry, double Lat, double Lon, Garage::GarageType GarageType)
        : garageType(GarageType), Name(CityName), CityCountry(InCountry), Latitude(Lat), Longitude(Lon)
    {}

    Garage::GarageType GarageType();
    void Serialize(ofstream&);
};

#endif // CITY_H_INCLUDED
