#ifndef CPP_PROJECT2019_BICYCLE_H
#define CPP_PROJECT2019_BICYCLE_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Bicycle : public Vehicle{
public:
    string frame_number;
    string model;
    string type;
    Bicycle(int id,string manufacturer,string frame_number, string model, string type);
    ~Bicycle();
    void print() override;
};
#endif //CPP_PROJECT2019_BICYCLE_H
