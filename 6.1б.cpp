#include "person.h"
#include "cyclist.h"
#include "motorcycle.h"
#include "car.h"
#include "unattended_bag.h"

int main() {
    try {
        Person person(10, 20, 50, 100, Gender::MALE, TernaryStatus::NO, TernaryStatus::YES, TernaryStatus::NO);
        Cyclist cyclist(30, 40, 80, 120, Gender::FEMALE, TernaryStatus::UNKNOWN, TernaryStatus::NO, TernaryStatus::UNKNOWN);

        unsigned char red[3] = { 255, 0, 0 };
        Motorcycle motorcycle(100, 100, 200, 180, red, "1234 AB-1");

        unsigned char blue[3] = { 0, 0, 255 };
        Car car(150, 80, 300, 200, blue, "5678 CD-2", true);

        UnattendedBag bag(200, 200, 220, 230, 36000); // 10:00:00

        std::cout << "=== Detected Objects ===\n";
        std::cout << person << "\n";
        std::cout << cyclist << "\n";
        std::cout << motorcycle << "\n";
        std::cout << car << "\n";
        std::cout << bag << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}