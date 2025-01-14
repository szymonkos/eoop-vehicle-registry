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

### Vehicle

This class stores data about specific vehicle that is its ID and name of its
manufacturer.

### Owner

This class stores data about specific owner of vehicles that is ID and list of owned
vehicles.

### VehicleList

This class contains list of all elements of type Vehicle.

### OwnerList

This class contains list of all elements of type Owner.

### Log

This class is a representation of log that is added to the list LogList after every
operation related to vehicles.

### LogList

This class contains list of all logs.

### Person

This class is derived from class Owner. It stores data about owner of type Person.

### Company

This class is derived from class Owner. It stores data about owner of type Company.

### Bicycle

This class is derived from class Vehicle. It stores data about vehicle of type Bicycle.

### Bus

This class is derived from class Vehicle. It stores data about vehicle of type Bus.

### Car

This class is derived from class Vehicle. It stores data about vehicle of type Car.

### Helicopter

This class is derived from class Vehicle. It stores data about vehicle of type
Helicopter.

### Motorcycle

This class is derived from class Vehicle. It stores data about vehicle of type
Motorcycle.

### Plane

This class is derived from class Vehicle. It stores data about vehicle of type Plane.

### Truck

This class is derived from class Vehicle. It stores data about vehicle of type Truck.

## Testing

Here we have example code that will perform various tests on all classes. That is use
methods in different scenarios and using methods against rules and checking
results of operations.
