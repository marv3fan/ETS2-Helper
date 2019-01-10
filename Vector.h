#ifndef ETS2HELPER_VECTOR_H
#define ETS2HELPER_VECTOR_H

#include <vector>

class City;
class Country;

namespace ets2helper{

class Vector{
public:
    static Vector* Instance();
    std::vector <City*> GarageCities;
    std::vector <City*> NoGarageCities;
    std::vector <City*> AllCities;
    std::vector <Country*> AllCountries;

private:
    Vector(){};
    static Vector* vector_instance;
};

} //namespace ets2helper

#endif
