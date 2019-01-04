#include "City.h"
#include <fstream>
#include <cstring>

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
