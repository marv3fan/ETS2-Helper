#ifndef ETS2HELPER_GARAGE_H
#define ETS2HELPER_GARAGE_H
namespace ets2helper {

class Garage {
  public:
    //types
    enum GarageType {
        NotAllowed = 1,
        None,
        Tiny,
        Small,
        Large
    };

    //constructors
    Garage(const Garage&) = delete; //Not copyable or movable

    //assignment operators
    Garage& operator=(const Garage&) = delete;  //Not copyable or movable

  private:
    //constructors
    Garage();
};

}  //namespace ets2helper
#endif
