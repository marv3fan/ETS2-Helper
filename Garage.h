#ifndef ETS2HELPER_GARAGE_H
#define ETS2HELPER_GARAGE_H
namespace ets2helper {

class Garage {
  public:
    //Not copyable or movable
    Garage(const Garage&) = delete;
    Garage& operator=(const Garage&) = delete;

    enum GarageType {
        NotAllowed = 1,
        None,
        Tiny,
        Small,
        Large
    };

  private:
    Garage();
};

}  //namespace ets2helper
#endif
