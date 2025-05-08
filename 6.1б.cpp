#include "person.h"
#include "cyclist.h"
#include "motorcycle.h"
#include "car.h"
#include "unattended_bag.h"
#include <iomanip>

std::string genderToString(Gender gender) {
    switch (gender) {
    case Gender::MALE: return "M";
    case Gender::FEMALE: return "F";
    default: return "Undefined";
    }
}

std::string statusToString(TernaryStatus status) {
    switch (status) {
    case TernaryStatus::YES: return "Yes";
    case TernaryStatus::NO: return "No";
    default: return "Unknown";
    }
}

int main() {
    try {
        // Создание объектов
        Person person(10, 20, 50, 100, Gender::MALE,
            TernaryStatus::NO, TernaryStatus::YES, TernaryStatus::NO);
        Cyclist cyclist(30, 40, 80, 120, Gender::MALE,
            TernaryStatus::YES, TernaryStatus::NO, TernaryStatus::NO);

        unsigned char red[3] = { 255, 0, 0 };
        Motorcycle motorcycle(100, 100, 200, 180, red, "1234 AB-1");

        unsigned char blue[3] = { 0, 0, 255 };
        Car car(150, 80, 300, 200, blue, "5678 CD-2", true);

        UnattendedBag bag(200, 200, 220, 230, 36000); // 10:00:00

        std::cout << "=== Detected Objects ===\n";

        // Person
        std::cout << "Person\n";
        std::cout << "Coordinates: (" << person.getXmin() << ", " << person.getYmin()
            << ") - (" << person.getXmax() << ", " << person.getYmax() << ")\n";
        std::cout << "Gender: " << genderToString(person.getGender()) << "\n";
        std::cout << "Child: " << statusToString(person.isChild()) << "\n";
        std::cout << "Glasses: " << statusToString(person.hasGlasses()) << "\n";
        std::cout << "Beard: " << statusToString(person.hasBeard()) << "\n\n";

        // Cyclist
        std::cout << "Cyclist\n";
        std::cout << "Coordinates: (" << cyclist.getXmin() << ", " << cyclist.getYmin()
            << ") - (" << cyclist.getXmax() << ", " << cyclist.getYmax() << ")\n";
        std::cout << "Gender: " << genderToString(cyclist.getGender()) << "\n";
        std::cout << "Child: " << statusToString(cyclist.isChild()) << "\n";
        std::cout << "Glasses: " << statusToString(cyclist.hasGlasses()) << "\n";
        std::cout << "Beard: " << statusToString(cyclist.hasBeard()) << "\n\n";

        // Motorcycle
        std::cout << "Motorcycle\n";
        std::cout << "Coordinates: (" << motorcycle.getXmin() << ", " << motorcycle.getYmin()
            << ") - (" << motorcycle.getXmax() << ", " << motorcycle.getYmax() << ")\n";
        std::cout << "Color: RGB(" << (int)motorcycle.getColor()[0] << ", "
            << (int)motorcycle.getColor()[1] << ", " << (int)motorcycle.getColor()[2] << ")\n";
        std::cout << "Plate: " << motorcycle.getLicensePlate() << "\n\n";

        // Car
        std::cout << "Car\n";
        std::cout << "Coordinates: (" << car.getXmin() << ", " << car.getYmin()
            << ") - (" << car.getXmax() << ", " << car.getYmax() << ")\n";
        std::cout << "Color: RGB(" << (int)car.getColor()[0] << ", "
            << (int)car.getColor()[1] << ", " << (int)car.getColor()[2] << ")\n";
        std::cout << "Plate: " << car.getLicensePlate() << "\n";
        std::cout << "Taxi: " << (car.isTaxi() ? "Yes" : "No") << "\n\n";

        // Unattended Bag
        std::cout << "Unattended Bag\n";
        std::cout << "Coordinates: (" << bag.getXmin() << ", " << bag.getYmin()
            << ") - (" << bag.getXmax() << ", " << bag.getYmax() << ")\n";
        unsigned int hours = bag.getFirstSeenTime() / 3600;
        unsigned int minutes = (bag.getFirstSeenTime() % 3600) / 60;
        unsigned int seconds = bag.getFirstSeenTime() % 60;
        std::cout << "First seen: " << hours << ":"
            << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}