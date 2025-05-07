#pragma once
#include "vehicle.h"

class Car : public Vehicle {
private:
    bool is_taxi;

public:
    Car(int xmin, int ymin, int xmax, int ymax,
        const unsigned char col[3], const char* plate, bool taxi = false);

    bool isTaxi() const;
    void setIsTaxi(bool taxi);

    void Print(std::ostream& os) const override;
};