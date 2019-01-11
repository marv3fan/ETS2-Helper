#ifndef ETS2HELPER_VECTOR_H
#define ETS2HELPER_VECTOR_H

#include <vector>

class City;
class Country;

namespace ets2helper {

class Vector {
  public:
    //constructors
    Vector(const Vector&) = delete; //Not copyable or movable

    //assignment operators
    Vector& operator=(const Vector&) = delete; //Not copyable or movable

    //methods
    //singleton
    static Vector* Instance();

    //getters
    inline std::vector <City*>& GetAllCities() {
        return AllCities;
    };
    inline std::vector <City*>& GetGarageCities() {
        return GarageCities;
    };
    inline std::vector <City*>& GetNoGarageCities() {
        return NoGarageCities;
    };
    inline std::vector <Country*>& GetAllCountries() {
        return AllCountries;
    };

  private:
    //constructors
    Vector() {};

    //data members
    std::vector <City*> AllCities;
    std::vector <Country*> AllCountries;
    std::vector <City*> GarageCities;
    std::vector <City*> NoGarageCities;
    static Vector* vector_instance;
};

} //namespace ets2helper

#endif
