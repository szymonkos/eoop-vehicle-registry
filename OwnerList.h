#ifndef CPP_PROJECT2019_OWNERLIST_H
#define CPP_PROJECT2019_OWNERLIST_H

#include "Owner.h"

class OwnerList{
public:
    vector<Owner*> owners; //list of owners
    OwnerList(); //constructor
    ~OwnerList(); //destructor
    void Print(); //prints full list of owners and their data
    void AddOwner(Owner* ownerToAdd); //adds given owner to the list
    bool RemoveOwner(Owner* ownerToRemove); //removes given owner from the list
    bool RemoveOwner(int id); //remove owner of given id from the list
    bool IsEmpty(); //checks if list is empty
    bool HasOwner(int id); //checks if there is owner of given id in the list
    bool HasVehicle(int id); //check if there is vehicle of given id of any owner
    int HowMany(); //returns number of elements in the list
    Owner* FindOwner(int vehicle_id); //returns owner of given vehicle
    Owner* ReturnOwner(int owner_id); //returns owner of given id
    int FindOwnerID(int vehicle_id);// returns id of owner of given vehicle
    void PrintOne(int id); //prints data about owner of given id
};

#endif //CPP_PROJECT2019_OWNERLIST_H
