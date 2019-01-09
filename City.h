#ifndef ETS2HELPER_CITY_H
#define ETS2HELPER_CITY_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Garage.h"

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

    City(string, string, double, double, Garage::GarageType GarageType = Garage::GarageType::None);

    void AddToVector(vector<City*>&);
    void CalculateNearestGarageDistance();
    void ChangeGarage();
    void NotifyCountry();
    void RemoveFromVector(vector<City*>&);
    void UpdateGarageVectors();

    inline void AnnounceClosestGarage()
    {
        cout << endl;
        cout << "The closest garage to " << Name << " is the garage in " << closestGarageCity->Name << ", " << closestGarageCity->CountryName << " which is " << DistanceFromGarage << "km away." << endl;
        cout << endl;
    };

    inline Garage::GarageType GarageType()
    {
        return garageType;
    };

    inline void Serialize(ofstream& savefile)
    {
        savefile << Name << '\n';
        savefile << CountryName << '\n';
        savefile << Latitude << '\n';
        savefile << Longitude << '\n';
        savefile << garageType << '\n';
    };
};

#endif
