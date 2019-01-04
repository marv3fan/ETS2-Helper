#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <vector>

#include "Country.h"
#include "City.h"

class Garage;

std::vector<Country> Countries;
std::vector<City> Cities;

bool PrintMenu();
void PopulateCountries();
void PopulateCities();
void CreateCity(string, string, double, double);
void CreateCity(string, string, double, double, Garage::GarageType);
void Serialize();
void Deserialize();
#endif // MAIN_H_INCLUDED
