//#include <iostream>
//#include <cstring>
//#include <stdexcept>
//
//// Базовый абстрактный класс для всех обнаруженных объектов
//class DetectedObject {
//protected:
//    int x_min, y_min, x_max, y_max;
//
//public:
//    DetectedObject(int xmin, int ymin, int xmax, int ymax)
//        : x_min(xmin), y_min(ymin), x_max(xmax), y_max(ymax) {
//        if (xmin >= xmax || ymin >= ymax) {
//            throw std::invalid_argument("Invalid coordinates");
//        }
//    }
//
//    virtual ~DetectedObject() {}
//
//    int getXmin() const { return x_min; }
//    int getYmin() const { return y_min; }
//    int getXmax() const { return x_max; }
//    int getYmax() const { return y_max; }
//
//    void setCoordinates(int xmin, int ymin, int xmax, int ymax) {
//        if (xmin >= xmax || ymin >= ymax) {
//            throw std::invalid_argument("Invalid coordinates");
//        }
//        x_min = xmin;
//        y_min = ymin;
//        x_max = xmax;
//        y_max = ymax;
//    }
//
//    // Виртуальный метод для вывода информации
//    virtual void Print(std::ostream& os) const {
//        os << "Type: DetectedObject\n";
//        os << "Coordinates: (" << x_min << ", " << y_min << ") - ("
//            << x_max << ", " << y_max << ")\n";
//    }
//
//    // Оператор вывода
//    friend std::ostream& operator<<(std::ostream& os, const DetectedObject& obj) {
//        obj.Print(os);
//        return os;
//    }
//};
//
//// Перечисление для пола
//enum class Gender { MALE, FEMALE, UNDEFINED };
//
//// Перечисление для бинарных признаков
//enum class TernaryStatus { YES, NO, UNKNOWN };
//
//class Person : public DetectedObject {
//protected:
//    Gender gender;
//    TernaryStatus is_child;
//    TernaryStatus has_glasses;
//    TernaryStatus has_beard;
//
//public:
//    Person(int xmin, int ymin, int xmax, int ymax,
//        Gender g = Gender::UNDEFINED,
//        TernaryStatus child = TernaryStatus::UNKNOWN,
//        TernaryStatus glasses = TernaryStatus::UNKNOWN,
//        TernaryStatus beard = TernaryStatus::UNKNOWN)
//        : DetectedObject(xmin, ymin, xmax, ymax),
//        gender(g), is_child(child), has_glasses(glasses), has_beard(beard) {}
//
//    Gender getGender() const { return gender; }
//    TernaryStatus isChild() const { return is_child; }
//    TernaryStatus hasGlasses() const { return has_glasses; }
//    TernaryStatus hasBeard() const { return has_beard; }
//
//    void setGender(Gender g) { gender = g; }
//    void setIsChild(TernaryStatus child) { is_child = child; }
//    void setHasGlasses(TernaryStatus glasses) { has_glasses = glasses; }
//    void setHasBeard(TernaryStatus beard) { has_beard = beard; }
//
//    void Print(std::ostream& os) const override {
//        os << "Type: Person\n";
//        DetectedObject::Print(os);
//
//        os << "Gender: ";
//        switch (gender) {
//        case Gender::MALE: os << "Male"; break;
//        case Gender::FEMALE: os << "Female"; break;
//        default: os << "Undefined"; break;
//        }
//        os << "\n";
//
//        os << "Child: ";
//        switch (is_child) {
//        case TernaryStatus::YES: os << "Yes"; break;
//        case TernaryStatus::NO: os << "No"; break;
//        default: os << "Unknown"; break;
//        }
//        os << "\n";
//
//        os << "Glasses: ";
//        switch (has_glasses) {
//        case TernaryStatus::YES: os << "Yes"; break;
//        case TernaryStatus::NO: os << "No"; break;
//        default: os << "Unknown"; break;
//        }
//        os << "\n";
//
//        os << "Beard: ";
//        switch (has_beard) {
//        case TernaryStatus::YES: os << "Yes"; break;
//        case TernaryStatus::NO: os << "No"; break;
//        default: os << "Unknown"; break;
//        }
//        os << "\n";
//    }
//};
//
//class Cyclist : public Person {
//public:
//    Cyclist(int xmin, int ymin, int xmax, int ymax,
//        Gender g = Gender::UNDEFINED,
//        TernaryStatus child = TernaryStatus::UNKNOWN,
//        TernaryStatus glasses = TernaryStatus::UNKNOWN,
//        TernaryStatus beard = TernaryStatus::UNKNOWN)
//        : Person(xmin, ymin, xmax, ymax, g, child, glasses, beard) {}
//
//    void Print(std::ostream& os) const override {
//        os << "Type: Cyclist\n";
//        Person::Print(os);
//    }
//};
//
//// Абстрактный класс для транспортных средств
//class Vehicle : public DetectedObject {
//protected:
//    unsigned char color[3]; // RGB
//    char* license_plate;
//
//public:
//    Vehicle(int xmin, int ymin, int xmax, int ymax,
//        const unsigned char col[3], const char* plate)
//        : DetectedObject(xmin, ymin, xmax, ymax) {
//        memcpy(color, col, 3);
//
//        if (plate) {
//            license_plate = new char[strlen(plate) + 1];
//            strcpy_s(license_plate, strlen(license_plate) + 1, license_plate);
//        }
//        else {
//            license_plate = nullptr;
//        }
//    }
//
//    // Правило пяти
//    Vehicle(const Vehicle& other) : DetectedObject(other) {
//        memcpy(color, other.color, 3);
//
//        if (other.license_plate) {
//            license_plate = new char[strlen(other.license_plate) + 1];
//            strcpy_s(license_plate, strlen(other.license_plate) + 1, other.license_plate);
//        }
//        else {
//            license_plate = nullptr;
//        }
//    }
//
//    Vehicle& operator=(const Vehicle& other) {
//        if (this != &other) {
//            DetectedObject::operator=(other);
//            memcpy(color, other.color, 3);
//
//            delete[] license_plate;
//            if (other.license_plate) {
//                license_plate = new char[strlen(other.license_plate) + 1];
//                strcpy_s(license_plate, strlen(other.license_plate) + 1, other.license_plate);
//            }
//            else {
//                license_plate = nullptr;
//            }
//        }
//        return *this;
//    }
//
//    ~Vehicle() {
//        delete[] license_plate;
//    }
//
//    const unsigned char* getColor() const { return color; }
//    const char* getLicensePlate() const { return license_plate; }
//
//    void setColor(const unsigned char col[3]) {
//        memcpy(color, col, 3);
//    }
//
//    void setLicensePlate(const char* plate) {
//        delete[] license_plate;
//        if (plate) {
//            license_plate = new char[strlen(plate) + 1];
//            strcpy_s(license_plate, strlen(plate) + 1, plate);
//        }
//        else {
//            license_plate = nullptr;
//        }
//    }
//
//    void Print(std::ostream& os) const override {
//        os << "Type: Vehicle\n";
//        DetectedObject::Print(os);
//        os << "Color: RGB(" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")\n";
//        os << "License plate: " << (license_plate ? license_plate : "None") << "\n";
//    }
//};
//
//class Motorcycle : public Vehicle {
//public:
//    Motorcycle(int xmin, int ymin, int xmax, int ymax,
//        const unsigned char col[3], const char* plate)
//        : Vehicle(xmin, ymin, xmax, ymax, col, plate) {}
//
//    void Print(std::ostream& os) const override {
//        os << "Type: Motorcycle\n";
//        Vehicle::Print(os);
//    }
//};
//
//class Car : public Vehicle {
//private:
//    bool is_taxi;
//
//public:
//    Car(int xmin, int ymin, int xmax, int ymax,
//        const unsigned char col[3], const char* plate, bool taxi = false)
//        : Vehicle(xmin, ymin, xmax, ymax, col, plate), is_taxi(taxi) {}
//
//    bool isTaxi() const { return is_taxi; }
//
//    void setIsTaxi(bool taxi) { is_taxi = taxi; }
//
//    void Print(std::ostream& os) const override {
//        os << "Type: Car\n";
//        Vehicle::Print(os);
//        os << "Taxi: " << (is_taxi ? "Yes" : "No") << "\n";
//    }
//};
//
//class UnattendedBag : public DetectedObject {
//private:
//    unsigned int first_seen_time; // секунды после полуночи
//
//public:
//    UnattendedBag(int xmin, int ymin, int xmax, int ymax, unsigned int time = 0)
//        : DetectedObject(xmin, ymin, xmax, ymax), first_seen_time(time) {}
//
//    unsigned int getFirstSeenTime() const { return first_seen_time; }
//
//    void setFirstSeenTime(unsigned int time) { first_seen_time = time; }
//
//    void Print(std::ostream& os) const override {
//        os << "Type: Unattended Bag\n";
//        DetectedObject::Print(os);
//
//        unsigned int hours = first_seen_time / 3600;
//        unsigned int minutes = (first_seen_time % 3600) / 60;
//        unsigned int seconds = first_seen_time % 60;
//
//        os << "First seen time: " << hours << ":" << minutes << ":" << seconds << "\n";
//    }
//};
//
//// Тестирующая программа
//int main() {
//    try {
//        // Создаем различные объекты
//        Person person(10, 20, 50, 100, Gender::MALE, TernaryStatus::NO, TernaryStatus::YES, TernaryStatus::NO);
//        Cyclist cyclist(30, 40, 80, 120, Gender::FEMALE, TernaryStatus::UNKNOWN, TernaryStatus::NO, TernaryStatus::UNKNOWN);
//
//        unsigned char red[3] = { 255, 0, 0 };
//        Motorcycle motorcycle(100, 100, 200, 180, red, "1234 AB-1");
//
//        unsigned char blue[3] = { 0, 0, 255 };
//        Car car(150, 80, 300, 200, blue, "5678 CD-2", true);
//
//        UnattendedBag bag(200, 200, 220, 230, 36000); // 10:00:00
//
//        // Выводим информацию о всех объектах
//        std::cout << "=== Detected Objects ===\n";
//        std::cout << person << "\n";
//        std::cout << cyclist << "\n";
//        std::cout << motorcycle << "\n";
//        std::cout << car << "\n";
//        std::cout << bag << "\n";
//
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return 1;
//    }
//
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <stdexcept>

// Базовый абстрактный класс для всех обнаруженных объектов
class DetectedObject {
protected:
    int x_min, y_min, x_max, y_max;

public:
    DetectedObject(int xmin, int ymin, int xmax, int ymax)
        : x_min(xmin), y_min(ymin), x_max(xmax), y_max(ymax) {
        if (xmin >= xmax || ymin >= ymax) {
            throw std::invalid_argument("Invalid coordinates");
        }
    }

    virtual ~DetectedObject() {}

    int getXmin() const { return x_min; }
    int getYmin() const { return y_min; }
    int getXmax() const { return x_max; }
    int getYmax() const { return y_max; }

    void setCoordinates(int xmin, int ymin, int xmax, int ymax) {
        if (xmin >= xmax || ymin >= ymax) {
            throw std::invalid_argument("Invalid coordinates");
        }
        x_min = xmin;
        y_min = ymin;
        x_max = xmax;
        y_max = ymax;
    }

    virtual void Print(std::ostream& os) const {
        os << "Type: DetectedObject\n";
        os << "Coordinates: (" << x_min << ", " << y_min << ") - ("
            << x_max << ", " << y_max << ")\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const DetectedObject& obj) {
        obj.Print(os);
        return os;
    }
};

enum class Gender { MALE, FEMALE, UNDEFINED };
enum class TernaryStatus { YES, NO, UNKNOWN };

class Person : public DetectedObject {
protected:
    Gender gender;
    TernaryStatus is_child;
    TernaryStatus has_glasses;
    TernaryStatus has_beard;

public:
    Person(int xmin, int ymin, int xmax, int ymax,
        Gender g = Gender::UNDEFINED,
        TernaryStatus child = TernaryStatus::UNKNOWN,
        TernaryStatus glasses = TernaryStatus::UNKNOWN,
        TernaryStatus beard = TernaryStatus::UNKNOWN)
        : DetectedObject(xmin, ymin, xmax, ymax),
        gender(g), is_child(child), has_glasses(glasses), has_beard(beard) {}

    Gender getGender() const { return gender; }
    TernaryStatus isChild() const { return is_child; }
    TernaryStatus hasGlasses() const { return has_glasses; }
    TernaryStatus hasBeard() const { return has_beard; }

    void setGender(Gender g) { gender = g; }
    void setIsChild(TernaryStatus child) { is_child = child; }
    void setHasGlasses(TernaryStatus glasses) { has_glasses = glasses; }
    void setHasBeard(TernaryStatus beard) { has_beard = beard; }

    void Print(std::ostream& os) const override {
        os << "Type: Person\n";
        DetectedObject::Print(os);

        os << "Gender: ";
        switch (gender) {
        case Gender::MALE: os << "Male"; break;
        case Gender::FEMALE: os << "Female"; break;
        default: os << "Undefined"; break;
        }
        os << "\n";

        os << "Child: ";
        switch (is_child) {
        case TernaryStatus::YES: os << "Yes"; break;
        case TernaryStatus::NO: os << "No"; break;
        default: os << "Unknown"; break;
        }
        os << "\n";

        os << "Glasses: ";
        switch (has_glasses) {
        case TernaryStatus::YES: os << "Yes"; break;
        case TernaryStatus::NO: os << "No"; break;
        default: os << "Unknown"; break;
        }
        os << "\n";

        os << "Beard: ";
        switch (has_beard) {
        case TernaryStatus::YES: os << "Yes"; break;
        case TernaryStatus::NO: os << "No"; break;
        default: os << "Unknown"; break;
        }
        os << "\n";
    }
};

class Cyclist : public Person {
public:
    Cyclist(int xmin, int ymin, int xmax, int ymax,
        Gender g = Gender::UNDEFINED,
        TernaryStatus child = TernaryStatus::UNKNOWN,
        TernaryStatus glasses = TernaryStatus::UNKNOWN,
        TernaryStatus beard = TernaryStatus::UNKNOWN)
        : Person(xmin, ymin, xmax, ymax, g, child, glasses, beard) {}

    void Print(std::ostream& os) const override {
        os << "Type: Cyclist\n";
        Person::Print(os);
    }
};

class Vehicle : public DetectedObject {
protected:
    unsigned char color[3]; // RGB
    char* license_plate;

public:
    Vehicle(int xmin, int ymin, int xmax, int ymax,
        const unsigned char col[3], const char* plate)
        : DetectedObject(xmin, ymin, xmax, ymax), license_plate(nullptr) {
        memcpy(color, col, 3);
        setLicensePlate(plate);
    }

    Vehicle(const Vehicle& other) : DetectedObject(other) {
        memcpy(color, other.color, 3);
        license_plate = nullptr;
        setLicensePlate(other.license_plate);
    }

    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            DetectedObject::operator=(other);
            memcpy(color, other.color, 3);
            setLicensePlate(other.license_plate);
        }
        return *this;
    }

    ~Vehicle() {
        delete[] license_plate;
    }

    const unsigned char* getColor() const { return color; }
    const char* getLicensePlate() const { return license_plate; }

    void setColor(const unsigned char col[3]) {
        memcpy(color, col, 3);
    }

    void setLicensePlate(const char* plate) {
        delete[] license_plate;
        if (plate) {
            license_plate = new char[strlen(plate) + 1];
            strcpy_s(license_plate, strlen(plate) + 1, plate);
        }
        else {
            license_plate = nullptr;
        }
    }

    void Print(std::ostream& os) const override {
        os << "Type: Vehicle\n";
        DetectedObject::Print(os);
        os << "Color: RGB(" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")\n";
        os << "License plate: " << (license_plate ? license_plate : "None") << "\n";
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(int xmin, int ymin, int xmax, int ymax,
        const unsigned char col[3], const char* plate)
        : Vehicle(xmin, ymin, xmax, ymax, col, plate) {}

    void Print(std::ostream& os) const override {
        os << "Type: Motorcycle\n";
        Vehicle::Print(os);
    }
};

class Car : public Vehicle {
private:
    bool is_taxi;

public:
    Car(int xmin, int ymin, int xmax, int ymax,
        const unsigned char col[3], const char* plate, bool taxi = false)
        : Vehicle(xmin, ymin, xmax, ymax, col, plate), is_taxi(taxi) {}

    bool isTaxi() const { return is_taxi; }

    void setIsTaxi(bool taxi) { is_taxi = taxi; }

    void Print(std::ostream& os) const override {
        os << "Type: Car\n";
        Vehicle::Print(os);
        os << "Taxi: " << (is_taxi ? "Yes" : "No") << "\n";
    }
};

class UnattendedBag : public DetectedObject {
private:
    unsigned int first_seen_time; // секунды после полуночи

public:
    UnattendedBag(int xmin, int ymin, int xmax, int ymax, unsigned int time = 0)
        : DetectedObject(xmin, ymin, xmax, ymax), first_seen_time(time) {}

    unsigned int getFirstSeenTime() const { return first_seen_time; }

    void setFirstSeenTime(unsigned int time) { first_seen_time = time; }

    void Print(std::ostream& os) const override {
        os << "Type: Unattended Bag\n";
        DetectedObject::Print(os);
        unsigned int hours = first_seen_time / 3600;
        unsigned int minutes = (first_seen_time % 3600) / 60;
        unsigned int seconds = first_seen_time % 60;
        os << "First seen time: " << hours << ":" << minutes << ":" << seconds << "\n";
    }
};

// Тестирующая программа
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