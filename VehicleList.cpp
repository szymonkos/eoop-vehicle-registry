#include "VehicleList.h"

VehicleList::VehicleList() {

}

VehicleList::~VehicleList() {
    vehicles.clear();
}

void VehicleList::Print() {
    cout << endl << "VehicleList:" << endl;
    if(!IsEmpty()){
        for (int i = 0; i < vehicles.size(); i++)
        {
            cout << i+1 << ".";
            vehicles[i]->print();
        }
        cout << endl << "--- End of VehicleList ---" << endl;
    }else{
        cout <<"No vehicles to print. VehicleList is empty." << endl;
    }
}

bool VehicleList::IsEmpty() {
    return vehicles.empty();
}

void VehicleList::AddVehicle(Vehicle *vehicleToAdd) {
    vehicles.push_back(vehicleToAdd);
}

bool VehicleList::RemoveVehicle(Vehicle *vehicleToRemove) {
    if(!IsEmpty()){
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

bool VehicleList::RemoveVehicle(int id) {
    if(!IsEmpty()){
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

bool VehicleList::HasVehicle(int id) {
    if(!IsEmpty()){
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

int VehicleList::HowMany() {
    return vehicles.size();
}

void VehicleList::PrintOne(int id) {
    if(!IsEmpty()){
        for (int i = 0; i < vehicles.size(); i++)
        {
            if(vehicles[i]->id == id){
                vehicles[i]->print();
                return;
            }
        }
        cout << "Cant print, because no such vehicle found with ID: " << id << endl;
        return;
    } else {
        cout << "Cant print, because list is empty." << endl;
        return;
    }
}

Vehicle* VehicleList::ReturnVehicle(int vehicle_id) {
    if(IsEmpty()){
        return  NULL;
    } else{
        for (int i = 0; i < vehicles.size(); i++)
        {
            if(vehicles[i]->id == vehicle_id){
                return vehicles[i];
            }
        }
        return NULL;
    }
}