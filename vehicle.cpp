#pragma once
#include "vehicle.h"

Vehicle::Vehicle(int xmin, int ymin, int xmax, int ymax,
    const unsigned char col[3], const char* plate)
    : DetectedObject(xmin, ymin, xmax, ymax), license_plate(nullptr) {
    memcpy(color, col, 3);
    setLicensePlate(plate);
}

Vehicle::Vehicle(const Vehicle& other) : DetectedObject(other) {
    memcpy(color, other.color, 3);
    license_plate = nullptr;
    setLicensePlate(other.license_plate);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        DetectedObject::operator=(other);
        memcpy(color, other.color, 3);
        setLicensePlate(other.license_plate);
    }
    return *this;
}

Vehicle::~Vehicle() {
    delete[] license_plate;
}

const unsigned char* Vehicle::getColor() const { return color; }
const char* Vehicle::getLicensePlate() const { return license_plate; }

void Vehicle::setColor(const unsigned char col[3]) {
    memcpy(color, col, 3);
}

void Vehicle::setLicensePlate(const char* plate) {
    delete[] license_plate;
    if (plate) {
        license_plate = new char[strlen(plate) + 1];
        strcpy_s(license_plate, strlen(plate) + 1, plate);
    }
    else {
        license_plate = nullptr;
    }
}

void Vehicle::Print(std::ostream& os) const {
    DetectedObject::Print(os);
    os << " Color: RGB(" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")";
    if (license_plate) {
        os << " Plate: " << license_plate;
    }
}