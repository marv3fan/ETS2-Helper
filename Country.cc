#include "Country.h"

namespace ets2helper
{

std::vector<Country*> Country::AllCountries;

void Country::PopulateCountries()
{
    AllCountries.push_back(new Country("Austria"));
    AllCountries.push_back(new Country("Belgium"));
    AllCountries.push_back(new Country("Czech Republic"));
    AllCountries.push_back(new Country("Denmark"));
    AllCountries.push_back(new Country("Estonia"));
    AllCountries.push_back(new Country("Finland"));
    AllCountries.push_back(new Country("France"));
    AllCountries.push_back(new Country("Germany"));
    AllCountries.push_back(new Country("Hungary"));
    AllCountries.push_back(new Country("Italy"));
    AllCountries.push_back(new Country("Latvia"));
    AllCountries.push_back(new Country("Lithuania"));
    AllCountries.push_back(new Country("Luxembourg"));
    AllCountries.push_back(new Country("Netherlands"));
    AllCountries.push_back(new Country("Norway"));
    AllCountries.push_back(new Country("Poland"));
    AllCountries.push_back(new Country("Russia"));
    AllCountries.push_back(new Country("Slovakia"));
    AllCountries.push_back(new Country("Sweden"));
    AllCountries.push_back(new Country("Switzerland"));
    AllCountries.push_back(new Country("United Kingdom"));
}

}  //namespace ets2helper
