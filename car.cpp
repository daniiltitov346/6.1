#pragma once
#include "car.h"

Car::Car(int xmin, int ymin, int xmax, int ymax,
    const unsigned char col[3], const char* plate, bool taxi)
    : Vehicle(xmin, ymin, xmax, ymax, col, plate), is_taxi(taxi) {}

bool Car::isTaxi() const { return is_taxi; }
void Car::setIsTaxi(bool taxi) { is_taxi = taxi; }

void Car::Print(std::ostream& os) const {
    Vehicle::Print(os);
    if (is_taxi) {
        os << " (Taxi)";
    }
}
