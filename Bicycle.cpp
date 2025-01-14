#include "Bicycle.h"

Bicycle::Bicycle(int id,string manufacturer,string frame_number, string model, string type) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->frame_number = frame_number;
    this->model = model;
    this->type = type;
}

Bicycle::~Bicycle() {

}

void Bicycle::print() {
    cout << "Bicycle info: ";
    Vehicle::print();
    cout << ", Model: " << model << ", Frame Number: " << frame_number << ", Type: " << type << endl;
}