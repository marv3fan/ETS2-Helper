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

    std::vector <City*>& GetAllCities();
    std::vector <Country*>& GetAllCountries();
    std::vector <City*>& GetGarageCities();
    std::vector <City*>& GetNoGarageCities();

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
