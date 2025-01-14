#include "Car.h"
Car::Car(int id, string manufacturer, string vin, string model, string color, string registration_plate) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->vin = vin;
    this->model = model;
    this->color = color;
    this->registration_plate = registration_plate;
}

Car::~Car() {

}

void Car::print() {
    cout << "Car info: ";
    Vehicle::print();
    cout << ", Model: " << model << ", VIN: " << vin << ", Color: " << color << ", Registration: " << registration_plate << endl;
}
