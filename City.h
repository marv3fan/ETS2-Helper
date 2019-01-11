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
  public:

    //constructors
    City(std::string, std::string, double, double, Garage::GarageType GarageType = Garage::GarageType::None);
    City(const City&) = delete;    //Not copyable or movable

    //assignment operators
    City& operator=(const City&) = delete;  //Not copyable or movable

    //vector work see Issue #12
    void AddToVector(std::vector<City*>&);
    void RemoveFromVector(std::vector<City*>&);
    static int GetCityIndex(int);

    //methods
    //getters
    inline geography::Coordinates GetCoordinates() {
        return Coordinates;
    };
    inline double GetDistanceFromGarage() {
        return DistanceFromGarage;
    };
    inline Garage::GarageType GetGarageType() {
        return garageType;
    };
    inline std::string GetCountryName() {
        return CountryName;
    };
    inline std::string GetName() {
        return Name;
    }

    //other methods
    inline void AnnounceClosestGarage() {
        std::cout << std::endl;
        std::cout << "The closest garage to " << Name << " is the garage in " << closestGarageCity->Name << ", " << closestGarageCity->CountryName << " which is " << DistanceFromGarage << "km away." << std::endl;
        std::cout << std::endl;
    };
    void CalculateNearestGarageDistance();
    void ChangeGarage();
    void NotifyCountry();
    void UpdateGarageVectors();

    static void InitializeCities();
    static void PopulateCities();
    inline void Serialize(std::ofstream& savefile) {
        savefile << Name << '\n';
        savefile << CountryName << '\n';
        savefile << Coordinates.Latitude << '\n';
        savefile << Coordinates.Longitude << '\n';
        savefile << garageType << '\n';
    };


  private:
    //data members
    City* closestGarageCity;
    double DistanceFromGarage = 200000;
    geography::Coordinates Coordinates;
    Garage::GarageType garageType;
    std::string CountryName;
    std::string Name;
};

}  //namespace ets2helper
#endif
