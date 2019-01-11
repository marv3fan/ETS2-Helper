#include "City.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "geography/Geography.h"
#include "Country.h"
#include "Vector.h"

namespace ets2helper {


City::City(std::string CityName, std::string InCountry, double Lat, double Lon, Garage::GarageType GarageType)
    : garageType(GarageType), CountryName(InCountry), Name(CityName) {
    Coordinates.Latitude = Lat;
    Coordinates.Longitude = Lon;

    if (garageType != Garage::GarageType::None) {
        DistanceFromGarage = 0;
    }

    for(Country* c : Vector::Instance()->GetAllCountries()) {
        if (InCountry == c->GetName()) {
            return;
        }
    }
    throw "Country not found!";
};

//TODO(12): Refactor this and RemoveFromVector into Vector class
void City::AddToVector(std::vector<City*>& InVector) {

    for (uint i = 0; i < InVector.size(); i++) {
        if((InVector[i]->Name == Name) && (InVector[i]->CountryName == CountryName)) {
            return;
        }
    }
    InVector.push_back(this);
};

void City::CalculateNearestGarageDistance() {
    for (City* c : Vector::Instance()->GetGarageCities()) {
        if(geography::GetDistance(Coordinates, c->Coordinates) < DistanceFromGarage) {
            DistanceFromGarage = geography::GetDistance(Coordinates, c->Coordinates);
            closestGarageCity = c;
        }
    }
};

void City::ChangeGarage() {
    std::cout << "Current garage in " << Name << ", " << CountryName << ": ";

    switch(garageType) {
    case Garage::GarageType::None:
        std::cout << "None" << std::endl;
        break;
    case Garage::GarageType::NotAllowed:
        std::cout << "Garage Not Allowed" << std::endl;
        std::cout << std::endl;
        std::cout << "You cannot change the garage in a city not allowed to have garages.";
        std::cout << std::endl;
        return;
    case Garage::GarageType::Tiny:
        std::cout << "Tiny" << std::endl;
        break;
    case Garage::GarageType::Small:
        std::cout << "Small" << std::endl;
        break;
    case Garage::GarageType::Large:
        std::cout << "Large" << std::endl;
        break;
    }

    bool validRequest = false;
    while (!validRequest) {
        std::cout << std::endl;
        std::cout << "(1) None" << std::endl;
        std::cout << "(2) Tiny" << std::endl;
        std::cout << "(3) Small" << std::endl;
        std::cout << "(4) Large" << std::endl;
        std::cout << std::endl;

        std::cout << "Choose which type of Garage:" << std::endl;
        int garageRequest = 99;

        std::cin >> garageRequest;
        switch(garageRequest + 1) {
        case 2:
            std::cout << "Removed garage from " << Name << std::endl;
            validRequest = true;
            garageType = Garage::GarageType::None;
            UpdateGarageVectors();
            DistanceFromGarage = 200000;
            break;
        case 3:
            std::cout << "Garage type in " << Name << " now Tiny" << std::endl;
            validRequest = true;
            garageType = Garage::GarageType::Tiny;
            UpdateGarageVectors();
            DistanceFromGarage = 0;
            break;
        case 4:
            std::cout << "Garage type in " << Name << " now Small" << std::endl;
            validRequest = true;
            garageType = Garage::GarageType::Small;
            UpdateGarageVectors();
            DistanceFromGarage = 0;
            break;
        case 5:
            std::cout << "Garage type in " << Name << " now Large" << std::endl;
            validRequest = true;
            garageType = Garage::GarageType::Large;
            UpdateGarageVectors();
            DistanceFromGarage = 0;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
};

int City::GetCityIndex(int country_index) {
    uint citychoice = 9999;
    while((citychoice < 1)| (citychoice > Vector::Instance()->GetAllCities().size())) {
        std::cout << std::endl;
        std::cout << "Cities in " << Vector::Instance()->GetAllCountries()[country_index]->GetName() << ":" << std::endl;
        std::cout << std::endl;

        for (uint i = 0; i < Vector::Instance()->GetAllCountries()[country_index]->GetCountryCities().size(); i++) {
            std::cout << "(" << i + 1 << ") " << Vector::Instance()->GetAllCountries()[country_index]->GetCountryCities()[i]->Name << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Please select a city: " << std::endl;

        std::cin >> citychoice;
    }

    std::cout << std::endl;
    std::cout << "You chose " << Vector::Instance()->GetAllCountries()[country_index]->GetCountryCities()[citychoice - 1]->Name << std::endl;
    std::cout << std::endl;

    return citychoice - 1;
}

void City::InitializeCities() {

    for (City* c : Vector::Instance()->GetAllCities()) {
        c->NotifyCountry();
        c->UpdateGarageVectors();
    }

    for (City* c : Vector::Instance()->GetNoGarageCities()) {
        c->CalculateNearestGarageDistance();
    }
}

void City::NotifyCountry() {
    for(Country* c : Vector::Instance()->GetAllCountries())
        if (CountryName == c->GetName()) {
            c->AddCity(this);
        }
};

void City::RemoveFromVector(std::vector<City*>& InVector) {


    for (uint i = 0; i < InVector.size(); i++) {
        if((InVector[i]->Name == Name) && (InVector[i]->CountryName == CountryName)) {
            InVector.erase(InVector.begin() + i);
            return;
        }
    }
};

void City::UpdateGarageVectors() {
    switch(garageType) {
    case Garage::GarageType::NotAllowed:
        break;
    case Garage::GarageType::None:
        RemoveFromVector(Vector::Instance()->GetGarageCities());
        AddToVector(Vector::Instance()->GetNoGarageCities());
        break;
    case Garage::GarageType::Tiny:
    case Garage::GarageType::Small:
    case Garage::GarageType::Large:
        RemoveFromVector(Vector::Instance()->GetNoGarageCities());
        AddToVector(Vector::Instance()->GetGarageCities());
        break;
    }
};

}  //namespace ets2helper
