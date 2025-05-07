#pragma once
#include <iostream>
#include <stdexcept>

class DetectedObject {
protected:
    int x_min, y_min, x_max, y_max;

public:
    DetectedObject(int xmin, int ymin, int xmax, int ymax);
    virtual ~DetectedObject();

    int getXmin() const;
    int getYmin() const;
    int getXmax() const;
    int getYmax() const;

    void setCoordinates(int xmin, int ymin, int xmax, int ymax);

    virtual void Print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const DetectedObject& obj);
}; 
