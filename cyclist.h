#pragma once
#include "person.h"

class Cyclist : public Person {
public:
    Cyclist(int xmin, int ymin, int xmax, int ymax,
        Gender g = Gender::MALE,
        TernaryStatus child = TernaryStatus::YES,
        TernaryStatus glasses = TernaryStatus::YES,
        TernaryStatus beard = TernaryStatus::NO);

    void Print(std::ostream& os) const override;
}; 
