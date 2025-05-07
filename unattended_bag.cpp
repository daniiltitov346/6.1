#pragma once
#include "unattended_bag.h"

UnattendedBag::UnattendedBag(int xmin, int ymin, int xmax, int ymax, unsigned int time)
    : DetectedObject(xmin, ymin, xmax, ymax), first_seen_time(time) {}

unsigned int UnattendedBag::getFirstSeenTime() const { return first_seen_time; }
void UnattendedBag::setFirstSeenTime(unsigned int time) { first_seen_time = time; }

void UnattendedBag::Print(std::ostream& os) const {
    DetectedObject::Print(os);
    unsigned int hours = first_seen_time / 3600;
    unsigned int minutes = (first_seen_time % 3600) / 60;
    unsigned int seconds = first_seen_time % 60;
    os << " Seen at: " << hours << ":" << minutes << ":" << seconds;
}