#ifndef GEOGRAPHY_H_INCLUDED
#define GEOGRAPHY_H_INCLUDED

#include "City.h"

class Geography
{
public:
    static double GetDistance(City&, City&);
private:
    // Disallow creating an instance of this object
    Geography() {}
};

#endif // GEOGRAPHY_H_INCLUDED
