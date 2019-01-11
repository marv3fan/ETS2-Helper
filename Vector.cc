#include "Vector.h"

namespace ets2helper {
Vector* Vector::vector_instance = NULL;

Vector* Vector::Instance() {
    if(!vector_instance)
        vector_instance = new Vector;

    return vector_instance;
}

std::vector <City*>& Vector::GetAllCities() {
    return AllCities;
};

std::vector <Country*>& Vector::GetAllCountries() {
    return AllCountries;
};

std::vector <City*>& Vector::GetGarageCities() {
    return GarageCities;
};

std::vector <City*>& Vector::GetNoGarageCities() {
    return NoGarageCities;
};

}   //namespace ets2helper
