#ifndef CPP_PROJECT2019_VEHICLE_H
#define CPP_PROJECT2019_VEHICLE_H

#include <string>
#include <iostream>
using namespace std;

class Vehicle{
public:
    int id;
    string manufacturer;
    Vehicle();
    Vehicle(int id, string manufacturer);
    ~Vehicle();
    virtual void print();

};

#endif //CPP_PROJECT2019_VEHICLE_H
