#pragma once
#include "detected_object.h"
#include <cstring>

class Vehicle : public DetectedObject {
protected:
    unsigned char color[3]; 
    char* license_plate;

public:
    Vehicle(int xmin, int ymin, int xmax, int ymax,
        const unsigned char col[3], const char* plate);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    virtual ~Vehicle();

    const unsigned char* getColor() const;
    const char* getLicensePlate() const;

    void setColor(const unsigned char col[3]);
    void setLicensePlate(const char* plate);

    void Print(std::ostream& os) const override;
}; 