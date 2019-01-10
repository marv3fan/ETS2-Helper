#ifndef ETS2HELPER_GEOGRAPHY_H
#define ETS2HELPER_GEOGRAPHY_H

#include "City.h"

namespace ets2helper
{

class Geography
{
public:
    static double GetDistance(City&, City&);
private:
    // Disallow creating an instance of this object
    Geography() {}
};

}  //namespace ets2helper
#endif
