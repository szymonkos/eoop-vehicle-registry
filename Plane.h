#ifndef CPP_PROJECT2019_PLANE_H
#define CPP_PROJECT2019_PLANE_H
#include "Vehicle.h"
#include <string>
using namespace std;
class Plane : public Vehicle{
public:
    string tail_code;
    string model;
    Plane(int id,string manufacturer,string tail_code, string model);
    ~Plane();
    void print();
};
#endif //CPP_PROJECT2019_PLANE_H
