#ifndef ETS2HELPER_GEOGRAPHY_H
#define ETS2HELPER_GEOGRAPHY_H

namespace ETS2Helper
{
class City;

class Geography
{
public:
    static double GetDistance(City&, City&);
private:
    // Disallow creating an instance of this object
    Geography() {}
};
}
#endif
