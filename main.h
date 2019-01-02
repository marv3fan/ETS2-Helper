#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <vector>

#include "Country.h"
#include "City.h"
#include "Garage.h"

std::vector<Country> Countries;
std::vector<City> Cities;

bool PrintMenu();
void PopulateCountries();
void PopulateCities();
void CreateCity(const char*, const char*, double, double);
void CreateCity(const char*, const char*, double, double, Garage::GarageType);
#endif // MAIN_H_INCLUDED
