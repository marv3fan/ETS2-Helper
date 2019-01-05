#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include <fstream>
#include <string>
#include "Garage.h"

using namespace std;

class City
{
private:
    Garage::GarageType garageType;
public:
    string Name;
    string CountryName;
    const double Latitude;
    const double Longitude;

    City(string CityName, string InCountry, double Lat, double Lon, Garage::GarageType GarageType = Garage::GarageType::None);

    Garage::GarageType GarageType();
    void Serialize(ofstream&);
    void NotifyCountry();
};

#endif // CITY_H_INCLUDED
