#include <fstream>
#include <vector>
#include <iostream>

#include "City.h"
#include "Country.h"
#include "Geography.h"

extern vector<Country*> Countries;
extern vector<City*> GarageCities;
extern vector<City*> NoGarageCities;

City::City(string CityName, string InCountry, double Lat, double Lon, Garage::GarageType GarageType)
    : garageType(GarageType), Name(CityName), CountryName(InCountry), Latitude(Lat), Longitude(Lon)
{
    if (garageType != Garage::GarageType::None)
    {
        DistanceFromGarage = 0;
    }

    for(Country* c : Countries)
    {
        if (InCountry == c->Name)
        {
            return;
        }
    }
    throw "Country not found!";
};

void City::AddToVector(vector<City*>& InVector)
{

    for (uint i = 0; i < InVector.size(); i++)
    {
        if((InVector[i]->Name == Name) && (InVector[i]->CountryName == CountryName))
        {
            return;
        }
    }
    InVector.push_back(this);
};

void City::CalculateNearestGarageDistance()
{
    for (City* c : GarageCities)
    {
        if(Geography::GetDistance(*this, *c) < DistanceFromGarage)
        {
            DistanceFromGarage = Geography::GetDistance(*this, *c);
            closestGarageCity = c;
        }
    }
};

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
    while (!validRequest)
    {

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
            UpdateGarageVectors();
            //TODO: Change the distance to the function call to get Distances from garages;
            DistanceFromGarage = 200000;
            break;
        case 3:
            cout << "Garage type in " << Name << " now Tiny" << endl;
            validRequest = true;
            garageType = Garage::GarageType::Tiny;
            UpdateGarageVectors();
            DistanceFromGarage = 0;
            break;
        case 4:
            cout << "Garage type in " << Name << " now Small" << endl;
            validRequest = true;
            garageType = Garage::GarageType::Small;
            UpdateGarageVectors();
            DistanceFromGarage = 0;
            break;
        case 5:
            cout << "Garage type in " << Name << " now Large" << endl;
            validRequest = true;
            garageType = Garage::GarageType::Large;
            UpdateGarageVectors();
            DistanceFromGarage = 0;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
};

void City::NotifyCountry()
{
    for(Country* c : Countries)
        if (CountryName == c->Name)
        {
            c->AddCity(this);
        }
};

void City::RemoveFromVector(vector<City*>& InVector)
{


    for (uint i = 0; i < InVector.size(); i++)
    {
        if((InVector[i]->Name == Name) && (InVector[i]->CountryName == CountryName))
        {
            InVector.erase(InVector.begin() + i);
            return;
        }
    }
};

void City::UpdateGarageVectors()
{
    switch(garageType)
    {
    case Garage::GarageType::NotAllowed:
        break;
    case Garage::GarageType::None:
        RemoveFromVector(GarageCities);
        AddToVector(NoGarageCities);
        break;
    case Garage::GarageType::Tiny:
    case Garage::GarageType::Small:
    case Garage::GarageType::Large:
        RemoveFromVector(NoGarageCities);
        AddToVector(GarageCities);
        break;
    }
};
