#pragma once
#include "person.h"

class Cyclist : public Person {
public:
    Cyclist(int xmin, int ymin, int xmax, int ymax,
        Gender g = Gender::UNDEFINED,
        TernaryStatus child = TernaryStatus::UNKNOWN,
        TernaryStatus glasses = TernaryStatus::UNKNOWN,
        TernaryStatus beard = TernaryStatus::UNKNOWN);

    void Print(std::ostream& os) const override;
}; 
