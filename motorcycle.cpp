#pragma once
#include "motorcycle.h"

Motorcycle::Motorcycle(int xmin, int ymin, int xmax, int ymax,
    const unsigned char col[3], const char* plate)
    : Vehicle(xmin, ymin, xmax, ymax, col, plate) {}

void Motorcycle::Print(std::ostream& os) const {
    Vehicle::Print(os);
}