#include "OwnerList.h"

OwnerList::OwnerList() {

}

OwnerList::~OwnerList() {
    owners.clear();
}

void OwnerList::Print() {
    cout << endl <<"OwnerList:" << endl << endl;
    if(!IsEmpty()){
        for (int i = 0; i < owners.size(); i++)
        {
            cout << i+1 << ". Owner: " << endl;
            owners[i]->Print();
        }
        cout << endl <<"--- End of OwnerList ---" << endl;
    }else{
        cout << "No owners to print. OwnerList is empty." << endl;
    }
}

bool OwnerList::IsEmpty() {
    return owners.empty();
}

void OwnerList::AddOwner(Owner *ownerToAdd) {
    owners.push_back(ownerToAdd);
}

bool OwnerList::RemoveOwner(Owner *ownerToRemove) {
    if(!IsEmpty()){
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i] == ownerToRemove){
                owners.erase( owners.begin()+i );
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool OwnerList::RemoveOwner(int id) {
    if(!IsEmpty()){
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->id==id){
                owners.erase( owners.begin()+i );
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool OwnerList::HasOwner(int id) {
    if(!IsEmpty()){
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->id == id){
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

int OwnerList::HowMany() {
    return owners.size();
}

Owner* OwnerList::FindOwner(int vehicle_id) {
    if(IsEmpty()){
        return  NULL;
    } else{
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->HasVehicle(vehicle_id)){
                return owners[i];
            }
        }
        return NULL;
    }
}

int OwnerList::FindOwnerID(int vehicle_id) {
    if(IsEmpty()){
        return 0;
    } else{
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->HasVehicle(vehicle_id)){
                return owners[i]->id;
            }
        }
        return 0;
    }
}

void OwnerList::PrintOne(int id) {
    if(!IsEmpty()){
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->id == id){
                owners[i]->Print();
                return;
            }
        }
        cout << "Cant print, because no such owner found with ID: " << id << endl;
        return;
    } else {
        cout << "Cant print, because list is empty." << endl;
        return;
    }
}

bool OwnerList::HasVehicle(int id) {
    if(IsEmpty()){
        return false;
    } else{
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->HasVehicle(id)){
                return true;
            }
        }
        return false;
    }
}

Owner* OwnerList::ReturnOwner(int owner_id) {
    if(IsEmpty()){
        return  NULL;
    } else{
        for (int i = 0; i < owners.size(); i++)
        {
            if(owners[i]->id == owner_id){
                return owners[i];
            }
        }
        return NULL;
    }
}