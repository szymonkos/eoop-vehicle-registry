#ifndef CPP_PROJECT2019_MOTORCYCLE_H
#define CPP_PROJECT2019_MOTORCYCLE_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Motorcycle : public Vehicle{
public:
    string vin;
    string model;
    string category;
    string registration_plate;
    Motorcycle(int id,string manufacturer,string vin, string model, string category, string registration_plate);
    ~Motorcycle();
    void print() override;
};
#endif //CPP_PROJECT2019_MOTORCYCLE_H
