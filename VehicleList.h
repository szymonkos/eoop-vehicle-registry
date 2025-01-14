#ifndef CPP_PROJECT2019_VEHICLELIST_H
#define CPP_PROJECT2019_VEHICLELIST_H

#include "Owner.h"

class VehicleList{
public:
    vector<Vehicle*> vehicles; //list of vehicles
    VehicleList(); //constructor
    ~VehicleList(); //destructor
    void Print(); //prints full list of vehicles
    void AddVehicle(Vehicle* vehicleToAdd); // adds given vehicle to the list
    bool RemoveVehicle(Vehicle* vehicleToRemove); //removes given vehicle from the list
    bool RemoveVehicle(int id); //removes vehicle of given id from the list
    bool IsEmpty(); //checks if list is empty
    bool HasVehicle(int id); //checks if vehicle of given id is in the list
    int HowMany(); //returns number of elements in the list
    void PrintOne(int id); //prints data about specific vehicle of given id
    Vehicle* ReturnVehicle(int vehicle_id); //returns pointer to vehicle of given id
};

#endif //CPP_PROJECT2019_VEHICLELIST_H
