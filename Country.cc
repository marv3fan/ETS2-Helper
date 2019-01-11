#include "Country.h"
#include "Vector.h"

namespace ets2helper {

int Country::GetCountryIndex() {
    uint countrychoice = 9999;
    while((countrychoice < 1)| (countrychoice > Vector::Instance()->GetAllCountries().size())) {
        std::cout << std::endl;

        for (uint i = 0; i < Vector::Instance()->GetAllCountries().size(); i++) {
            std::cout << "(" << i + 1 << ") " << Vector::Instance()->GetAllCountries()[i]->Name << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Please select a country: " << std::endl;

        std::cin >> countrychoice;
    }

    std::cout << std::endl;
    std::cout << "You chose " << Vector::Instance()->GetAllCountries()[countrychoice - 1]->Name << std::endl;
    std::cout << std::endl;

    return countrychoice - 1;
}

void Country::PopulateCountries() {
    Vector::Instance()->GetAllCountries().push_back(new Country("Austria"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Belgium"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Czech Republic"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Denmark"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Estonia"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Finland"));
    Vector::Instance()->GetAllCountries().push_back(new Country("France"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Germany"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Hungary"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Italy"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Latvia"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Lithuania"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Luxembourg"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Netherlands"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Norway"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Poland"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Russia"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Slovakia"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Sweden"));
    Vector::Instance()->GetAllCountries().push_back(new Country("Switzerland"));
    Vector::Instance()->GetAllCountries().push_back(new Country("United Kingdom"));
}

}  //namespace ets2helper
