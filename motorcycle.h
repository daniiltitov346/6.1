#pragma once
#include "vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(int xmin, int ymin, int xmax, int ymax,
        const unsigned char col[3], const char* plate);

    void Print(std::ostream& os) const override;
};
