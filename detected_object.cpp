#include "detected_object.h"

DetectedObject::DetectedObject(int xmin, int ymin, int xmax, int ymax)
    : x_min(xmin), y_min(ymin), x_max(xmax), y_max(ymax) {
    if (xmin >= xmax || ymin >= ymax) {
        throw std::invalid_argument("Invalid coordinates");
    }
}

DetectedObject::~DetectedObject() {}

int DetectedObject::getXmin() const { return x_min; }
int DetectedObject::getYmin() const { return y_min; }
int DetectedObject::getXmax() const { return x_max; }
int DetectedObject::getYmax() const { return y_max; }

void DetectedObject::setCoordinates(int xmin, int ymin, int xmax, int ymax) {
    if (xmin >= xmax || ymin >= ymax) {
        throw std::invalid_argument("Invalid coordinates");
    }
    x_min = xmin;
    y_min = ymin;
    x_max = xmax;
    y_max = ymax;
}

void DetectedObject::Print(std::ostream& os) const {
    os << "Coordinates: (" << x_min << ", " << y_min << ") - ("
        << x_max << ", " << y_max << ")";
}

std::ostream& operator<<(std::ostream& os, const DetectedObject& obj) {
    obj.Print(os);
    return os;
}