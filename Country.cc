#include "Country.h"

namespace ets2helper {

std::vector<Country*> Country::AllCountries;

int Country::GetCountryIndex() {
    uint countrychoice = 9999;
    while((countrychoice < 1)| (countrychoice > AllCountries.size())) {
        std::cout << std::endl;

        for (uint i = 0; i < AllCountries.size(); i++) {
            std::cout << "(" << i + 1 << ") " << AllCountries[i]->Name << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Please select a country: " << std::endl;

        std::cin >> countrychoice;
    }

    std::cout << std::endl;
    std::cout << "You chose " << AllCountries[countrychoice - 1]->Name << std::endl;
    std::cout << std::endl;

    return countrychoice - 1;
}

void Country::PopulateCountries() {
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
