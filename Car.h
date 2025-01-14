#ifndef CPP_PROJECT2019_CAR_H
#define CPP_PROJECT2019_CAR_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Car : public Vehicle{
public:
    string vin;
    string model;
    string color;
    string registration_plate;
    Car(int id,string manufacturer,string vin, string model, string color, string registration_plate);
    ~Car();
    void print() override;
};
#endif //CPP_PROJECT2019_CAR_H
