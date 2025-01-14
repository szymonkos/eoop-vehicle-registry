Szymon Kos 295816

# EOOP Project - Vehicle Registry

## Project Description

Purpose behind this project is to create universal and durable program to store data
about various vehicles. It allows us to ad entries about vehicles of various types and
properties to the lists. Program is also possible of storing some data about owners of
vehicles. The main functionality of this program is adding and extracting data about
vehicles. Program also stores data about logs, that is time of operation that take
place in this program or in other word vehicle history.

## Limitations

- Every vehicle and every owner have its own unique ID. If we try to create vehicle or
owner with already existing ID, program should avoid that and return information that
this operation is prohibited.

- In this program every vehicle has exactly one owner and when we try to attach
same vehicle to more than one owner program should avoid that and return
information that this operation is prohibited. If we want to transfer vehicle from one
owner to another we should use provided function Transfer.

## Functionality

Program contains following functionalities:
- Adding new vehicle (of various type) to the list of vehicles
- Removing vehicle from the list
- Adding new owners (of various type) to the list of owners
- Removing owners from the list
- Attaching vehicles to owners
- Detaching (freeing) vehicles from owners
- Printing data about vehicles
- Printing data about owners
- Printing list of logs
- Printing logs of given vehicle
- Finding owner of given vehicle
- Printing data about vehicle of given id
- Printing data about owner of given id
- Transferring vehicle between two owners

## Classes

Program contains 7 base classes and 9 derived classes so 16 classes in total.
The main class of the program is class VehicleRegistry.

### VehicleRegistry

This class contains of 3 list classes that is VehiceList, OwnerList and LogList.
In this class we have all methods that will be used by user when operating the
program.

```c++
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

bool AddCar(int id,string manufacturer,string vin, string model, string color, string registration_plate, string date);
/*adds car of given data to the list and adds appropriate log*/

bool AddPlane(int id,string manufacturer,string tail_code, string model,string date); //adds plane of given data to the list and adds appropriate log

bool AddHelicopter(int id,string manufacturer,string model,int weight, string tail_code, string date);
/*adds helicopter of given data to the list and adds appropriate log*/

bool AddMotorcycle(int id,string manufacturer,string vin, string model, string category, string registration_plate, string date);
/*adds motorcycle of given data to the list and adds appropriate log*/

bool AddBicycle(int id,string manufacturer,string frame_number, string model, string type, string date);
/*adds bicycle of given data to the list and adds appropriate log*/

bool AddTruck(int id,string manufacturer,string vin, string model, int cargo_capacity, string registration_plate, string date);
/*adds truck of given data to the list and adds appropriate log*/

bool AddBus(int id,string manufacturer,string vin, string model, int passenger_capacity, string registration_plate, string date);
/*adds bus of given data to the list and adds appropriate log*/

bool RemoveVehicle(int id, string date); //removes vehicle of given id from list, also removes vehicle from owner
void AddOwner(Owner* ownerToAdd); //adds owner to the list of owners
bool AddPerson(int id, string name, string surname, long int pesel); //adds person of given to the list of owners
bool AddCompany(int id, string name, int nip); //adds company of given data to the list of owners
bool RemoveOwner(int id, string date); //this method removes owner and adds logs about freeing his vehicles

bool AssignVehicleToOwner(int vehicle_id, int owner_id, string date);
/* this method assigns vehicle of given id to owner of given id and adds appropriate log (returns false when there is no such vehicle or owner etc)*/

bool IsOwned(int id); //checks if vehicle of given id is owned (assigned to owner)
bool FreeVehicle(int id, string date); //frees vehicle of given id from its owner (if no such vehicle or owner return false)

bool Transfer(int veh_id,int id_from,int id_to, string date);
/*moves vehicle from owner with id id_from to owner with id id_to (returns false if there is no such vehicle or owners etc.)*/

bool IsVehicleListEmpty(); //checks if vehicle list is empty
bool IsOwnerListEmpty(); //checks if owner list is empty
bool PrintLogs(int id); // prints logs of specific vehicle of given id (returns false when there is no such vehicle)
};
```

### Vehicle

This class stores data about specific vehicle that is its ID and name of its
manufacturer.

```c++
class Vehicle{
public:
    int id;
    string manufacturer;
    Vehicle();
    Vehicle(int id, string manufacturer);
    ~Vehicle();
    void print();
};
```

### Owner

This class stores data about specific owner of vehicles that is ID and list of owned
vehicles.

```c++
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
    bool RemoveVehicle(int id); //removes vehicle of given id from owner (if he doesnt have such vehicle method returns false)
    bool HasVehicles(); //checks if owner has any vehicles
    bool HasVehicle(int id); //checks if owner has got vehicle of given id
    int HowMany(); //returns number of cars owned by owner
};
```

### VehicleList

This class contains list of all elements of type Vehicle.

```c++
class VehicleList{
public:
    vector<Vehicle*> vehicles; //list of vehicles
    VehicleList(); //constructor
    ~VehicleList(); //destructor
    void Print(); //prints full list of vehicles
    void AddVehicle(Vehicle* vehicleToAdd); //adds given vehicle to the list
    bool RemoveVehicle(Vehicle* vehicleToRemove); //removes given vehicle from the list
    bool RemoveVehicle(int id); //removes vehicle of given id from the list
    bool IsEmpty(); //checks if list is empty
    bool HasVehicle(int id); //checks if vehicle of given id is in the list
    int HowMany(); //returns number of elements in the list
    void PrintOne(int id); //prints data about specific vehicle of given id
    Vehicle* ReturnVehicle(int vehicle_id); //returns pointer to vehicle of given id
};
```

### OwnerList

This class contains list of all elements of type Owner.

```c++
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
    int FindOwnerID(int vehicle_id); // returns id of owner of given vehicle
    void PrintOne(int id); //prints data about owner of given id
};
```

### Log

This class is a representation of log that is added to the list LogList after every
operation related to vehicles.

```c++
class Log{
public:
    string date; //date when log was added
    int vehicle_id; //id of vehicle that this log is about
    string log; //content of the log (description what happened at this date)
    Log(string date, int vehicle_id, string log); //constructor
    ~Log(); //destructor
    void Print(); //prints log
};
```

### LogList

This class contains list of all logs.

```c++
class LogList{
public:
    vector<Log*> logs; //list of logs
    LogList(); //constructor
    ~LogList(); //destructor
    bool IsEmpty(); //checks if list of logs is empty
    void Print(); //prints full list of logs
    void PrintOne(int vehicle_id); //prints logs related to vehicle of given id
    void AddLog(string date, int vehicle_id, string log); //adds log to the list
};
```

### Person

This class is derived from class Owner. It stores data about owner of type Person.

```c++
class Person : public Owner{
public:
    string name;
    string surname;
    long int pesel;
    Person();
    Person(int id, string name, string surname, long int pesel);
    ~Person();
    void Print() override;
};
```

### Company

This class is derived from class Owner. It stores data about owner of type Company.

```c++
class Company : public Owner{
public:
    string name;
    int nip;
    Company();
    Company(int id, string name, int nip);
    ~Company();
    void Print() override;
};
```

### Bicycle

This class is derived from class Vehicle. It stores data about vehicle of type Bicycle.

```c++
class Bicycle : public Vehicle{
public:
    string frame_number;
    string model;
    string type;
    Bicycle(int id,string manufacturer,string frame_number, string model,
    string type);
    ~Bicycle();
    void print() override;
};
```

### Bus

This class is derived from class Vehicle. It stores data about vehicle of type Bus.

```c++
class Bus : public Vehicle{
public:
    string vin;
    string model;
    int passenger_capacity;
    string registration_plate;
    Bus(int id,string manufacturer,string vin, string model,
    int passenger_capacity, string registration_plate);
    ~Bus();
    void print() override;
};
```

### Car

This class is derived from class Vehicle. It stores data about vehicle of type Car.

```c++
class Car : public Vehicle{
public:
    string vin;
    string model;
    string color;
    string registration_plate;
    Car(int id,string manufacturer,string vin, string model, string color,
    string registration_plate);
    ~Car();
    void print() override;
};
```

### Helicopter

This class is derived from class Vehicle. It stores data about vehicle of type
Helicopter.

```c++
class Helicopter : public Vehicle{
public:
    string model;
    string tail_code;
    int weight;
    Helicopter(int id,string manufacturer,string model,int weight ,
    string tail_code);
    ~Helicopter();
    void print() override;
};
```

### Motorcycle

This class is derived from class Vehicle. It stores data about vehicle of type
Motorcycle.

```c++
class Motorcycle : public Vehicle{
public:
    string vin;
    string model;
    string category;
    string registration_plate;
    Motorcycle(int id,string manufacturer,string vin, string model,
    string category, string registration_plate);
    ~Motorcycle();
    void print() override;
};
```

### Plane

This class is derived from class Vehicle. It stores data about vehicle of type Plane.

```c++
class Plane : public Vehicle{
public:
    string tail_code;
    string model;
    Plane(int id,string manufacturer,string tail_code, string model);
    ~Plane();
    void print();
};
```

### Truck

This class is derived from class Vehicle. It stores data about vehicle of type Truck.

```c++
class Truck : public Vehicle{
public:
    string vin;
    string model;
    int cargo_capacity;
    string registration_plate;
    Truck(int id,string manufacturer,string vin, string model,
    int cargo_capacity, string registration_plate);
    ~Truck();
    void print() override;
};
```

## Testing

Here we have example code that will perform various tests on all classes. That is use
methods in different scenarios and using methods against rules and checking
results of operations.

```c++
int main() {
VehicleRegistry vehicleregistry; //crating vehicleregistry and adding some vehicles and owners
vehicleregistry.PrintAll(); //testing printing empty lists
//adding some vehicles and owners without assigning
vehicleregistry.AddCar(100000,"Toyota","4T1B11HK6KU700665","Camry","red","WI 12345","13 april 2019 7:00");
vehicleregistry.AddCar(100001,"BMW","WBA5R12030AK72354","330i","black","WI 67890","13 april 2019 7:10");
vehicleregistry.AddCar(100002,"Mercedes","WMA5R12030AK72354","C220","white","WI 42112","13 april 2019 7:20");
vehicleregistry.AddCar(100003,"Honda","4BA5R12030AK72354","Accord","orange","WI 55555","13 april 2019 7:30");
vehicleregistry.AddCar(100004,"Bentley","SBA5R12030AK72354","Continental","silver","WI 77777","13 april 2019 7:40");
vehicleregistry.AddCar(100005,"Ford","1BA5R12030AK72354","Focus","green","WI 66666","13 april 2019 7:50");
vehicleregistry.AddCar(100006,"Fiat","7BA5R12030AK72354","500","yellow","WI 44444","13 april 2019 8:00");
vehicleregistry.AddCar(100007,"Peugeot","FBA5R12030AK72354","5008","blue","WI 11111","13 april 2019 8:10");
vehicleregistry.AddBicycle(100008,"Giant","34hrfdy5","Roam3","MTB","13 april 2019 8:20");
vehicleregistry.AddBus(100009,"Solaris","WAA5R12030AK72354","Urbion 18",40,"WI 00001","13 april 2019 8:30");
vehicleregistry.AddHelicopter(100010,"Sikorsky","UH-60",100,"SP-001","13 april 2019 8:40");
vehicleregistry.AddMotorcycle(100011,"Kawasaki","4KA5R12030AK72354","Vulcan","A","WI 10000","13 april 2019 8:50");
vehicleregistry.AddPlane(100012,"Cessna","SP-002","162 Skycatcher","13 april 2019 9:00");
vehicleregistry.AddTruck(100013,"DAF","WDA5R12030AK72354","XF105",50,"WI 00005","13 april 2019 9:10");
vehicleregistry.AddPerson(100,"Jan","Kowalski",90010108614);
vehicleregistry.AddPerson(200,"Karol","Nowak",9005120814);
vehicleregistry.AddCompany(300,"Global-Transport",55556456);
vehicleregistry.AddCompany(400,"Company2",44556456);
vehicleregistry.PrintAll(); //printing after adding some data but before assigning owners
//assigning some vehicles to owners
vehicleregistry.AssignVehicleToOwner(100000,100,"13 april 2019 9:20");
vehicleregistry.AssignVehicleToOwner(100008,100,"13 april 2019 9:30");
vehicleregistry.AssignVehicleToOwner(100011,200,"13 april 2019 9:40");
vehicleregistry.AssignVehicleToOwner(100001,200,"13 april 2019 9:41");
vehicleregistry.AssignVehicleToOwner(100002,200,"13 april 2019 9:42");
vehicleregistry.AssignVehicleToOwner(100012,200,"13 april 2019 9:43");
vehicleregistry.AssignVehicleToOwner(100013,300,"13 april 2019 9:44");
vehicleregistry.AssignVehicleToOwner(100010,300,"13 april 2019 9:45");
vehicleregistry.AssignVehicleToOwner(100009,300,"13 april 2019 9:46");
vehicleregistry.AssignVehicleToOwner(100004,400,"13 april 2019 9:47");
vehicleregistry.AssignVehicleToOwner(100007,400,"13 april 2019 9:48");
vehicleregistry.PrintAll(); //printing after assigning some vehicles
vehicleregistry.AddCar(100006,"Fiat","7BA5R12030AK72354","500","yellow","WI 44444","13 april 2019 8:00"); //testing adding vehicle with already existing id
vehicleregistry.AddCompany(400,"Company2",44556456); //testing adding owner with already existing id
vehicleregistry.PrintVehicle(10); //testing printing non-existent vehicle
vehicleregistry.PrintOwner(10); //testing printing non-existent owner
vehicleregistry.PrintLogs(10); //testing printing logs of non-existent vehicle
vehicleregistry.RemoveVehicle(10,"13 april 2019 8:00"); //testing removing non-existent vehicle
vehicleregistry.RemoveOwner(10,"13 april 2019 8:00"); //testing removing non-existent owner
vehicleregistry.FreeVehicle(10,"13 april 2019 8:00"); //testing freeing non-existent vehicle
vehicleregistry.Transfer(10,10,10,"13 april 2019 8:00"); //testing transferring non-existent vehicle
vehicleregistry.RemoveOwner(100,"13 april 2019 9:50"); //testing removing of owner (testing if logs about freeing owners vehicles were added)
vehicleregistry.PrintAll();
vehicleregistry.Transfer(100007,400,200,"13 april 2019 10:00"); //testing transferring vehicle between owners and checking logs after that
vehicleregistry.PrintAll();
vehicleregistry.RemoveVehicle(100007,"13 april 2019 10:10"); //testing removing vehicle and checking logs if it was also deleted from owner
vehicleregistry.PrintAll();
vehicleregistry.PrintLogs(100007);
return 0;
}
```
