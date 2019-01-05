#include "City.h"
#include "Country.h"
#include <fstream>
#include <vector>

extern std::vector<Country*> Countries;

City::City(string CityName, string InCountry, double Lat, double Lon, Garage::GarageType GarageType)
        : garageType(GarageType), Name(CityName), CountryName(InCountry), Latitude(Lat), Longitude(Lon)
{
    for(Country* c : Countries)
        {
            if (InCountry == c->Name)
            {
                return;
            }
        }
    throw "Country not found!";
}


Garage::GarageType City::GarageType()
{
    return garageType;
}

void City::Serialize(ofstream& savefile)
{
    savefile << Name << '\n';
    savefile << CountryName << '\n';
    savefile << Latitude << '\n';
    savefile << Longitude << '\n';
    savefile << garageType << '\n';
}

void City::NotifyCountry()
{
    for(Country* c : Countries)
        if (CountryName == c->Name)
        {
            c->AddCity(this);
        }
}
