#ifndef ETS2HELPER_COUNTRY_H
#define ETS2HELPER_COUNTRY_H

#include <string>
#include <vector>

#include "City.h"

namespace ets2helper {

class Country {
  public:
    //constructors
    inline Country(std::string CountryName)
        : Name(CountryName)
    {}
    Country(const Country&) = delete;   //Not copyable or movable

    //assignment operators
    Country& operator=(const Country&) = delete;    //Not copyable or movable

    //methods
    //getters
    inline std::string GetName() {
        return Name;
    }
    inline std::vector<City*> GetCountryCities() {
        return CountryCities;
    }

    //other methods
    inline void AddCity(City* InCity) {
        Country::CountryCities.push_back(InCity);
    };

    //data members
    static int GetCountryIndex();
    static void PopulateCountries();

  private:
    //data members
    std::vector<City*> CountryCities;
    std::string Name;
};

}  //namespace ets2helper
#endif
