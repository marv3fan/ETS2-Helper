#ifndef ETS2HELPER_CITY_H
#define ETS2HELPER_CITY_H

#include <fstream>
#include <string>
#include "Garage.h"
#include <vector>

using namespace std;

class City
{
private:
    Garage::GarageType garageType;
    City* closestGarageCity;
public:
    string Name;
    string CountryName;
    const double Latitude;
    const double Longitude;
    double DistanceFromGarage = 200000;

    City(string CityName, string InCountry, double Lat, double Lon, Garage::GarageType GarageType = Garage::GarageType::None);

    Garage::GarageType GarageType();
    void Serialize(ofstream&);
    void NotifyCountry();
    void ChangeGarage();
    void UpdateGarageVectors();
    void RemoveFromVector(vector<City*>*);
    void AddToVector(vector<City*>*);
    void CalculateNearestGarageDistance();
    void AnnounceClosestGarage();
};

#endif
