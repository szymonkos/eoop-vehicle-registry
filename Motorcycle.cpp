#include "Motorcycle.h"

Motorcycle::Motorcycle(int id, string manufacturer, string vin, string model, string category, string registration_plate) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->vin = vin;
    this->model = model;
    this->category = category;
    this->registration_plate = registration_plate;
}

Motorcycle::~Motorcycle() {

}

void Motorcycle::print() {
    cout << "Motorcycle info: ";
    Vehicle::print();
    cout << ", Model: " << model << ", VIN: " << vin << ", Category: " << category << ", Registration: " << registration_plate << endl;
}

