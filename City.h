#ifndef ETS2HELPER_CITY_H
#define ETS2HELPER_CITY_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "geography/Coordinates.h"
#include "Garage.h"

namespace ets2helper {

class City {
  private:
    Garage::GarageType garageType;
    City* closestGarageCity;
  public:
    std::string Name;
    std::string CountryName;
    geography::Coordinates Coordinates;
    double DistanceFromGarage = 200000;

    City(std::string, std::string, double, double, Garage::GarageType GarageType = Garage::GarageType::None);

    void AddToVector(std::vector<City*>&);
    void CalculateNearestGarageDistance();
    void ChangeGarage();
    static int GetCityIndex(int);
    static void InitializeCities();
    void NotifyCountry();
    static void PopulateCities();
    void RemoveFromVector(std::vector<City*>&);
    void UpdateGarageVectors();

    inline void AnnounceClosestGarage() {
        std::cout << std::endl;
        std::cout << "The closest garage to " << Name << " is the garage in " << closestGarageCity->Name << ", " << closestGarageCity->CountryName << " which is " << DistanceFromGarage << "km away." << std::endl;
        std::cout << std::endl;
    };

    inline Garage::GarageType GarageType() {
        return garageType;
    };

    inline void Serialize(std::ofstream& savefile) {
        savefile << Name << '\n';
        savefile << CountryName << '\n';
        savefile << Coordinates.Latitude << '\n';
        savefile << Coordinates.Longitude << '\n';
        savefile << garageType << '\n';
    };
};

}  //namespace ets2helper
#endif
