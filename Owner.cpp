#include "Owner.h"

Owner::Owner(){
    this->id=0;
}


Owner::Owner(int id){
    this->id=id;
}

Owner::~Owner(){
    vehicles.clear();
}

void Owner::Print() {
    cout << "Owner ID: " << id << " ,vehicles owned(" << HowMany() << "):" << endl;
    if(this->HasVehicles()){
        for (int i = 0; i < vehicles.size(); i++)
        {
            cout << i+1 << ".";
            vehicles[i]->print();
        }
        cout << "*** End of list of vehicles owned by Owner ***" << endl;
    }else{
        cout << "No vehicles attached to this owner." << endl;
    }
}

void Owner::AddVehicle(Vehicle *vehicleToAdd) {
    vehicles.push_back(vehicleToAdd);
}

bool Owner::RemoveVehicle(Vehicle *vehicleToRemove) {
    if(this->HasVehicles()){
        for (int i = 0; i < vehicles.size(); i++)
        {
            if(vehicles[i] == vehicleToRemove){
                vehicles.erase( vehicles.begin()+i );
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool Owner::HasVehicles() {
    return (!vehicles.empty());
}

bool Owner::RemoveVehicle(int id){
    if(this->HasVehicles()){
        for (int i = 0; i < vehicles.size(); i++)
        {
            if(vehicles[i]->id==id){
                vehicles.erase( vehicles.begin()+i );
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool Owner::HasVehicle(int id){
    if(this->HasVehicles()){
        for (int i = 0; i < vehicles.size(); i++)
        {
            if(vehicles[i]->id == id){
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

int Owner::HowMany(){
    return vehicles.size();
}