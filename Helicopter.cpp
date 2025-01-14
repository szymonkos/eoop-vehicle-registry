#include "Helicopter.h"

Helicopter::Helicopter(int id,string manufacturer,string model,int weight ,string tail_code) {
    this->id = id;
    this->manufacturer = manufacturer;
    this->tail_code = tail_code;
    this->model = model;
    this->weight = weight;
}

Helicopter::~Helicopter() {

}

void Helicopter::print() {
    cout << "Helicopter info:";
    Vehicle::print();
    cout << ", Model: " << model << ", Tail-Code: " << tail_code << ", Weight: " << weight << endl;
}