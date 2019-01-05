#include "City.h"
#include "Country.h"
#include <fstream>
#include <vector>
#include <iostream>

extern std::vector<Country*> Countries;

City::City(string CityName, string InCountry, double Lat, double Lon, Garage::GarageType GarageType)
    : garageType(GarageType), Name(CityName), CountryName(InCountry), Latitude(Lat), Longitude(Lon)
{
    if (garageType != Garage::GarageType::None)
    {
        DistanceFromGarage = 0;
    }

    //TODO we need a vector of cities with garages.
    //TODO we need a vector of cities without garages.

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

void City::ChangeGarage()
{
    cout << "Current garage in " << Name << ", " << CountryName << ": ";

    switch(garageType)
    {
    case Garage::GarageType::None:
        cout << "None" << endl;
        break;
    case Garage::GarageType::NotAllowed:
        cout << "Garage Not Allowed" << endl;
        cout << endl;
        cout << "You cannot change the garage in a city not allowed to have garages.";
        cout << endl;
        return;
    case Garage::GarageType::Tiny:
        cout << "Tiny" << endl;
        break;
    case Garage::GarageType::Small:
        cout << "Small" << endl;
        break;
    case Garage::GarageType::Large:
        cout << "Large" << endl;
        break;
    }

    bool validRequest = false;
    while (!validRequest){

    cout << endl;
    cout << "(1) None" << endl;
    cout << "(2) Tiny" << endl;
    cout << "(3) Small" << endl;
    cout << "(4) Large" << endl;
    cout << endl;

    cout << "Choose which type of Garage:" << endl;
    int garageRequest = 99;

    cin >> garageRequest;
    switch(garageRequest + 1)
        {
        case 2:
            cout << "Removed garage from " << Name << endl;
            validRequest = true;
            garageType = Garage::GarageType::None;
            DistanceFromGarage = 200000;
            break;
        case 3:
            cout << "Garage type in " << Name << " now Tiny" << endl;
            validRequest = true;
            garageType = Garage::GarageType::Tiny;
            DistanceFromGarage = 0;
            break;
        case 4:
            cout << "Garage type in " << Name << " now Small" << endl;
            validRequest = true;
            garageType = Garage::GarageType::Small;
            DistanceFromGarage = 0;
            break;
        case 5:
            cout << "Garage type in " << Name << " now Large" << endl;
            validRequest = true;
            garageType = Garage::GarageType::Large;
            DistanceFromGarage = 0;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

