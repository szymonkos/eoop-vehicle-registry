#include "Truck.h"
Truck::Truck(int id,string manufacturer,string vin, string model,int cargo_capacity, string registration_plate) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->vin = vin;
    this->model = model;
    this->cargo_capacity = cargo_capacity;
    this->registration_plate = registration_plate;
}

Truck::~Truck() {

}

void Truck::print() {
    cout << "Truck info: ";
    Vehicle::print();
    cout << ", Model: " << model << ", VIN: " << vin << ", Cargo Capacity: " << cargo_capacity << ", Registration: " << registration_plate << endl;
}