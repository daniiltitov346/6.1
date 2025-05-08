#pragma once
#include "detected_object.h"

class UnattendedBag : public DetectedObject {
private:
    unsigned int first_seen_time; 

public:
    UnattendedBag(int xmin, int ymin, int xmax, int ymax, unsigned int time = 0);
    UnattendedBag* clone() const override {
        return new UnattendedBag(*this);
    }
    unsigned int getFirstSeenTime() const;
    void setFirstSeenTime(unsigned int time);

    void Print(std::ostream& os) const override;
};
