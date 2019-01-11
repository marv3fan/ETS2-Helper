#ifndef ETS2HELPER_VECTOR_H
#define ETS2HELPER_VECTOR_H

#include <vector>

class City;
class Country;

namespace ets2helper {

class Vector {
  public:
    //Not copyable or movable
    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    static Vector* Instance();

    //TODO(13) We need to go back to inlining these
    inline std::vector <City*>& GetAllCities() {
    return AllCities;
    };

    inline std::vector <Country*>& GetAllCountries() {
        return AllCountries;
    };

    inline std::vector <City*>& GetGarageCities() {
        return GarageCities;
    };

    inline std::vector <City*>& GetNoGarageCities() {
        return NoGarageCities;
    };

  private:
    std::vector <City*> AllCities;
    std::vector <Country*> AllCountries;
    std::vector <City*> GarageCities;
    std::vector <City*> NoGarageCities;
    static Vector* vector_instance;

    Vector() {};
};

} //namespace ets2helper

#endif
