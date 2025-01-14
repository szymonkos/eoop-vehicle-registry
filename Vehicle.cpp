#include "Vehicle.h"
Vehicle::Vehicle() {
    this->id = 0;
    this->manufacturer = "";
}
Vehicle::Vehicle(int id, string manufacturer) {
    this->id=id;
    this->manufacturer = manufacturer;
}

Vehicle::~Vehicle() {

}

void Vehicle::print() {
    cout << "Vehicle ID: " << id  << ", Manufacturer: " << manufacturer << " ";
}