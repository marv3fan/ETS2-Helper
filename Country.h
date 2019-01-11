#ifndef ETS2HELPER_COUNTRY_H
#define ETS2HELPER_COUNTRY_H

#include <string>
#include <vector>

#include "City.h"

namespace ets2helper {

class Country {
  private:
    std::vector<City*> CountryCities;
    std::string Name;

  public:
    static int GetCountryIndex();
    static void PopulateCountries();

    inline Country(std::string CountryName)
        : Name(CountryName)
    {}
    //Not copyable or movable
    Country(const Country&) = delete;
    Country& operator=(const Country&) = delete;


    inline void AddCity(City* InCity) {
        Country::CountryCities.push_back(InCity);
    };

    inline std::vector<City*> GetCountryCities() {
        return CountryCities;
    }

    inline std::string GetName() {
        return Name;
    }
};

}  //namespace ets2helper
#endif
