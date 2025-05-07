#include "cyclist.h"

Cyclist::Cyclist(int xmin, int ymin, int xmax, int ymax,
    Gender g, TernaryStatus child, TernaryStatus glasses, TernaryStatus beard)
    : Person(xmin, ymin, xmax, ymax, g, child, glasses, beard) {}

void Cyclist::Print(std::ostream& os) const {
    Person::Print(os);
}