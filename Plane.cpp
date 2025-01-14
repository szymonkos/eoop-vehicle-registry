#include "Plane.h"

Plane::Plane(int id, string manufacturer, string tail_code, string model) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->tail_code = tail_code;
    this->model = model;
}

Plane::~Plane() {

}

void Plane::print() {
    cout << "Plane info:";
    Vehicle::print();
    cout << ", Model: " << model << ", Tail-Code: " << tail_code << endl;
}