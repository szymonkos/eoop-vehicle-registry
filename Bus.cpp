#include "Bus.h"
Bus::Bus(int id,string manufacturer,string vin, string model,int passenger_capacity, string registration_plate) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->vin = vin;
    this->model = model;
    this->passenger_capacity = passenger_capacity;
    this->registration_plate = registration_plate;
}

Bus::~Bus() {

}

void Bus::print() {
    cout << "Bus info: ";
    Vehicle::print();
    cout << ", Model: " << model << ", VIN: " << vin << ", Passenger Capacity: " << passenger_capacity << ", Registration: " << registration_plate << endl;
}
