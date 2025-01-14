#ifndef CPP_PROJECT2019_VEHICLEREGISTRY_H
#define CPP_PROJECT2019_VEHICLEREGISTRY_H

#include "OwnerList.h"
#include "Person.h"
#include "Company.h"
#include "VehicleList.h"
#include "Car.h"
#include "Plane.h"
#include "Helicopter.h"
#include "Motorcycle.h"
#include "Bicycle.h"
#include "Truck.h"
#include "Bus.h"
#include "LogList.h"

class VehicleRegistry{
private:
    OwnerList ownerlist; //this class stores data about owners
    VehicleList vehiclelist; //this class stores data about vehicles
    LogList loglist; //this class stores data about logs
public:
    VehicleRegistry(); //constructor
    ~VehicleRegistry(); //destructor
    void PrintAll(); //prints all data regarding VehicleRegistry
    void PrintAllOwners(); //prints list of all owners
    void PrintAllVehicles(); //prints list of all vehicles
    void PrintAllLogs(); //prints list of all logs
    void PrintOwner(int id); //prints data about specific owner
    void PrintVehicle(int id); //prints data about specific vehicle
    void AddVehicle(Vehicle* vehicleToAdd, string date); //adds vehicle to the list of vehicles and adds appropriate log
    bool AddCar(int id,string manufacturer,string vin, string model, string color, string registration_plate, string date);//adds car of given data to the list and adds appropriate log
    bool AddPlane(int id,string manufacturer,string tail_code, string model,string date);//adds plane of given data to the list and adds appropriate log
    bool AddHelicopter(int id,string manufacturer,string model,int weight ,string tail_code, string date);//adds helicopter of given data to the list and adds appropriate log
    bool AddMotorcycle(int id,string manufacturer,string vin, string model, string category, string registration_plate, string date);//adds motorcycle of given data to the list and adds appropriate log
    bool AddBicycle(int id,string manufacturer,string frame_number, string model, string type, string date);//adds bicycle of given data to the list and adds appropriate log
    bool AddTruck(int id,string manufacturer,string vin, string model,int cargo_capacity, string registration_plate, string date);//adds truck of given data to the list and adds appropriate log
    bool AddBus(int id,string manufacturer,string vin, string model,int passenger_capacity, string registration_plate, string date);//adds bus of given data to the list and adds appropriate log
    bool RemoveVehicle(int id, string date); //removes vehicle of given id from list, it also removes such vehicle from owner
    void AddOwner(Owner* ownerToAdd); //adds owner to the list of owners
    bool AddPerson(int id, string name, string surname, long int pesel); //adds person of given to the list of owners
    bool AddCompany(int id, string name, int nip);//adds company of given data to the list of owners
    bool RemoveOwner(int id, string date); // this method removes owner and adds logs about freeing his vehicles
    bool AssignVehicleToOwner(int vehicle_id, int owner_id, string date); //this method assigns vehicle of given id to owner of given id and adds appropriate log (returns false when there is no such vehicle or owner etc.)
    bool IsOwned(int id); //checks if vehicle of given id is owned (assigned to owner)
    bool FreeVehicle(int id, string date); // frees vehicle of given id from its owner(if no such vehicle or owner return false)
    bool Transfer(int veh_id,int id_from,int id_to, string date); //moves vehicle from owner with id id_from to owner with id id_to (returns false if there is no such vehicle or owners etc.)
    bool IsVehicleListEmpty(); //checks if vehicle list is empty
    bool IsOwnerListEmpty(); //checks if owner list is empty
    bool PrintLogs(int id); // prints logs of specific vehicle of given id (returns false when there is no such vehicle)
};


#endif //CPP_PROJECT2019_VEHICLEREGISTRY_H

