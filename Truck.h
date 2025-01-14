#ifndef CPP_PROJECT2019_TRUCK_H
#define CPP_PROJECT2019_TRUCK_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Truck : public Vehicle{
public:
    string vin;
    string model;
    int cargo_capacity;
    string registration_plate;
    Truck(int id,string manufacturer,string vin, string model,int cargo_capacity, string registration_plate);
    ~Truck();
    void print() override;
};
#endif //CPP_PROJECT2019_TRUCK_H
