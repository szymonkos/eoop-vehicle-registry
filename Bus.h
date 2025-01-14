#ifndef CPP_PROJECT2019_BUS_H
#define CPP_PROJECT2019_BUS_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Bus : public Vehicle{
public:
    string vin;
    string model;
    int passenger_capacity;
    string registration_plate;
    Bus(int id,string manufacturer,string vin, string model,int passenger_capacity, string registration_plate);
    ~Bus();
    void print() override;
};
#endif //CPP_PROJECT2019_BUS_H
