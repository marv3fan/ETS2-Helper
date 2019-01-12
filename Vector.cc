#include "Vector.h"

namespace ets2helper {

Vector* Vector::vector_instance = NULL;

Vector* Vector::Instance() {
    if(!vector_instance)
        vector_instance = new Vector;

    return vector_instance;
}

}   //namespace ets2helper
