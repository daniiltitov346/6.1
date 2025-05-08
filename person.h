#pragma once
#include "detected_object.h"

enum class Gender { MALE, FEMALE, UNDEFINED };
enum class TernaryStatus { YES, NO, UNKNOWN };

class Person : public DetectedObject {
protected:
    Gender gender;
    TernaryStatus is_child;
    TernaryStatus has_glasses;
    TernaryStatus has_beard;

public:
    Person* clone() const override {
        return new Person(*this); // Использует конструктор копирования
    }
    Person(int xmin, int ymin, int xmax, int ymax,
        Gender g = Gender::UNDEFINED,
        TernaryStatus child = TernaryStatus::UNKNOWN,
        TernaryStatus glasses = TernaryStatus::UNKNOWN,
        TernaryStatus beard = TernaryStatus::UNKNOWN);

    Gender getGender() const;
    TernaryStatus isChild() const;
    TernaryStatus hasGlasses() const;
    TernaryStatus hasBeard() const;

    void setGender(Gender g);
    void setIsChild(TernaryStatus child);
    void setHasGlasses(TernaryStatus glasses);
    void setHasBeard(TernaryStatus beard);

    void Print(std::ostream& os) const override;
}; 
