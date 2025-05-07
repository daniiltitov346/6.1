#pragma once
#include "person.h"

Person::Person(int xmin, int ymin, int xmax, int ymax,
    Gender g, TernaryStatus child, TernaryStatus glasses, TernaryStatus beard)
    : DetectedObject(xmin, ymin, xmax, ymax),
    gender(g), is_child(child), has_glasses(glasses), has_beard(beard) {}

Gender Person::getGender() const { return gender; }
TernaryStatus Person::isChild() const { return is_child; }
TernaryStatus Person::hasGlasses() const { return has_glasses; }
TernaryStatus Person::hasBeard() const { return has_beard; }

void Person::setGender(Gender g) { gender = g; }
void Person::setIsChild(TernaryStatus child) { is_child = child; }
void Person::setHasGlasses(TernaryStatus glasses) { has_glasses = glasses; }
void Person::setHasBeard(TernaryStatus beard) { has_beard = beard; }

void Person::Print(std::ostream& os) const {
    DetectedObject::Print(os);
}