#ifndef ETS2HELPER_GARAGE_H
#define ETS2HELPER_GARAGE_H
namespace ets2helper
{

class Garage
{
public:
    enum GarageType
    {
        NotAllowed = 1,
        None,
        Tiny,
        Small,
        Large
    };
};

}  //namespace ets2helper
#endif
