#ifndef ETS2HELPER_GEOGRAPHY_H
#define ETS2HELPER_GEOGRAPHY_H

class City;

class Geography
{
public:
    static double GetDistance(City&, City&);
private:
    // Disallow creating an instance of this object
    Geography() {}
};

#endif
