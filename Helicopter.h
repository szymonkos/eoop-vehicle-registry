#ifndef CPP_PROJECT2019_HELICOPTER_H
#define CPP_PROJECT2019_HELICOPTER_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Helicopter : public Vehicle{
public:
    string model;
    string tail_code;
    int weight;
    Helicopter(int id,string manufacturer,string model,int weight ,string tail_code);
    ~Helicopter();
    void print() override;
};
#endif //CPP_PROJECT2019_HELICOPTER_H
