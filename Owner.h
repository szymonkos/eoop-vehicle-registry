#ifndef CPP_PROJECT2019_OWNER_H
#define CPP_PROJECT2019_OWNER_H
#include "Vehicle.h"
#include <vector>
class Owner{
public:
    int id; //id of owner
    vector<Vehicle*> vehicles; //list of vehicles owned by owner
    Owner(); //constructor
    Owner(int id); //constructor
    ~Owner(); //destructor
    virtual void Print(); //prints data about owner
    void AddVehicle(Vehicle* vehicleToAdd); //adds vehicle to the owner
    bool RemoveVehicle(Vehicle* vehicleToRemove); //removes given vehicle from owner (if he doesnt have such vehicle method returns false)
    bool RemoveVehicle(int id);//removes vehicle of given id from owner (if he doesnt have such vehicle method returns false)
    bool HasVehicles(); //checks if owner has any vehicles
    bool HasVehicle(int id); //checks if owner has got vehicle of given id
    int HowMany(); //returns number of cars owned by owner

};
#endif //CPP_PROJECT2019_OWNER_H
