#include "VehicleRegistry.h"

VehicleRegistry::VehicleRegistry(){

}

VehicleRegistry::~VehicleRegistry(){
    loglist.logs.clear();
    vehiclelist.vehicles.clear();
    ownerlist.owners.clear();
}

void VehicleRegistry::PrintAll(){
    cout << endl << " VehicleRegistry: " << endl;
    cout << "Number of Vehicles Registered: " << vehiclelist.HowMany() << endl;
    cout << "Number of Owners Registered: " << ownerlist.HowMany() << endl;
    cout << "Number of Logs Registered: " << loglist.logs.size() << endl;
    ownerlist.Print();
    vehiclelist.Print();
    loglist.Print();
    cout << endl << "------- End of PrintAll of VehicleRegistry -------" << endl;
}

void VehicleRegistry::PrintAllOwners(){
    ownerlist.Print();
}

void VehicleRegistry::PrintAllVehicles(){
    vehiclelist.Print();
}

void VehicleRegistry::PrintAllLogs(){
    loglist.Print();
}

void VehicleRegistry::PrintOwner(int id){
    ownerlist.PrintOne(id);
}

void VehicleRegistry::PrintVehicle(int id){
    vehiclelist.PrintOne(id);
}

void VehicleRegistry::AddVehicle(Vehicle* vehicleToAdd, string date){
    vehiclelist.AddVehicle(vehicleToAdd);
    loglist.AddLog(date,vehicleToAdd->id, "New Vehicle added to the list.");
}

bool VehicleRegistry::RemoveVehicle(int id, string date){

    if(!vehiclelist.HasVehicle(id)){
        cout << "Cant remove vehicle with ID: " << id << ", because such vehicle doesnt exist." << endl;
        return false;
    } else{
        vehiclelist.RemoveVehicle(id);
        if( ownerlist.FindOwner(id) != NULL ){
            ownerlist.FindOwner(id)->RemoveVehicle(id);
        }
        loglist.AddLog(date, id, "Vehicle has been deleted.");
        return true;
    }
}

void VehicleRegistry::AddOwner(Owner *ownerToAdd) {
    ownerlist.AddOwner(ownerToAdd);
}

bool VehicleRegistry::IsOwnerListEmpty() {
    return ownerlist.IsEmpty();
}

bool VehicleRegistry::IsVehicleListEmpty() {
    return vehiclelist.IsEmpty();
}

bool VehicleRegistry::IsOwned(int id) {
    return ownerlist.HasVehicle(id);
}

bool VehicleRegistry::AssignVehicleToOwner(int vehicle_id, int owner_id, string date) {
    if(!vehiclelist.HasVehicle(vehicle_id)){
        cout << "Cant assign vehicle to owner, because vehicle with ID: " << vehicle_id << " doesnt exist." << endl;
        return false;
    } else{
        if(!ownerlist.HasOwner(owner_id)){
            cout << "Cant assign vehicle to owner, because owner with ID: " << owner_id << " doesnt exist." << endl;
            return false;
        } else{
            if(IsOwned(vehicle_id)) {
                cout << "Cant assign vehicle to owner, because vehicle with ID: " << vehicle_id << " is already assigned." << endl;
                return false;
            } else{
                ownerlist.ReturnOwner(owner_id)->AddVehicle(vehiclelist.ReturnVehicle(vehicle_id));
                loglist.AddLog(date,vehicle_id,"Vehicle was assigned to owner with ID: "+ to_string(owner_id));
            }
        }
    }
}

bool VehicleRegistry::FreeVehicle(int id, string date) {
    if(!vehiclelist.HasVehicle(id)){
        cout << "Cant free vehicle, because vehicle with ID: " << id << " doesnt exist." << endl;
        return false;
    } else{
        if(!ownerlist.HasVehicle(id)){
            cout << "Cant free vehicle, because vehicle with ID: " << id << " is already free (has no owner)." << endl;
            return false;
        } else{
            ownerlist.FindOwner(id)->RemoveVehicle(id);
            loglist.AddLog(date,id,"Vehicle was freed from owner with ID: " + to_string(ownerlist.FindOwnerID(id)));
        }
    }
}

bool VehicleRegistry::AddCar(int id, string manufacturer, string vin, string model, string color, string registration_plate, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Car with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Car(id, manufacturer, vin, model, color, registration_plate));
        loglist.AddLog(date,id,"New Vehicle(Car) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddPlane(int id, string manufacturer, string tail_code, string model, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Plane with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Plane(id, manufacturer, tail_code, model));
        loglist.AddLog(date,id,"New Vehicle(Plane) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddHelicopter(int id, string manufacturer, string model, int weight, string tail_code, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Helicopter with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Helicopter( id,  manufacturer, model,  weight, tail_code));
        loglist.AddLog(date,id,"New Vehicle(Helicopter) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddMotorcycle(int id, string manufacturer, string vin, string model, string category, string registration_plate, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Motorcycle with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Motorcycle( id,  manufacturer, vin,  model, category,registration_plate));
        loglist.AddLog(date,id,"New Vehicle(Motorcycle) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddBicycle(int id, string manufacturer, string frame_number, string model, string type, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Bicycle with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Bicycle( id,  manufacturer, frame_number,  model, type));
        loglist.AddLog(date,id,"New Vehicle(Bicycle) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddTruck(int id, string manufacturer, string vin, string model, int cargo_capacity, string registration_plate, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Truck with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Truck( id,  manufacturer, vin,  model, cargo_capacity, registration_plate));
        loglist.AddLog(date,id,"New Vehicle(Truck) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddBus(int id, string manufacturer, string vin, string model, int passenger_capacity, string registration_plate, string date) {
    if(vehiclelist.HasVehicle(id)){
        cout << "Cant add Bus with ID: " << id << ", because vehicle with such ID already exists." << endl;
        return false;
    } else{
        vehiclelist.AddVehicle(new Bus( id,  manufacturer, vin,  model, passenger_capacity, registration_plate));
        loglist.AddLog(date,id,"New Vehicle(Bus) added to the list.");
        return true;
    }
}

bool VehicleRegistry::AddPerson(int id, string name, string surname, long int pesel) {
    if(ownerlist.HasOwner(id)){
        cout << "Cant add Person with ID: " << id << ", because owner with such ID already exists." << endl;
        return false;
    } else {
        ownerlist.AddOwner(new Person(id, name, surname, pesel));
        return true;
    }
}

bool VehicleRegistry::AddCompany(int id, string name, int nip) {
    if(ownerlist.HasOwner(id)){
        cout << "Cant add Company with ID: " << id << ", because owner with such ID already exists." << endl;
        return false;
    } else {
        ownerlist.AddOwner(new Company(id, name, nip));
        return true;
    }
}

bool VehicleRegistry::RemoveOwner(int id, string date) {
    if(!ownerlist.HasOwner(id)){
        cout << "Cant remove owner, because Owner with ID: " << id << " doesnt exist." << endl;
        return false;
    } else {
        if(ownerlist.ReturnOwner(id)->HasVehicles()){
            for (int i = 0; i < ownerlist.ReturnOwner(id)->vehicles.size(); i++)
            {
                ownerlist.ReturnOwner(id)->vehicles[i]->id;
                loglist.AddLog(date,ownerlist.ReturnOwner(id)->vehicles[i]->id,"Vehicle was freed from owner with ID: " + to_string(id));
            }
            return true;
        }else{
            return true;
        }
    }
}

bool VehicleRegistry::Transfer(int veh_id, int id_from, int id_to, string date) {
    if(!vehiclelist.HasVehicle(veh_id)){
        cout << "Cant transfer vehicle with ID: " << veh_id << ", because such vehicle doesnt exist." << endl;
        return false;
    } else{
        if(!IsOwned(veh_id)){
            cout << "Cant transfer vehicle with ID: " << veh_id << ", because such vehicle doesnt have owner." << endl;
            return false;
        } else{
            if(!ownerlist.HasOwner(id_from)){
                cout << "Cant transfer vehicle, because owner with ID: " << id_from << " doesnt exist." << endl;
                return false;
            } else {
                if(!ownerlist.HasOwner(id_to)){
                    cout << "Cant transfer vehicle, because owner with ID: " << id_to << " doesnt exist." << endl;
                    return false;
                } else{
                    if(ownerlist.FindOwnerID(veh_id)!=id_from){
                        cout << "Cant transfer vehicle, because ID of vehicle to transfer doesnt match. " << endl;
                        return false;
                    } else{
                        ownerlist.FindOwner(veh_id)->RemoveVehicle(veh_id);
                        ownerlist.ReturnOwner(id_to)->AddVehicle(vehiclelist.ReturnVehicle(veh_id));
                        string log = "Vehicle was transferred from owner with ID: " + to_string(id_from) + " to owner with ID: " + to_string(id_to);
                        loglist.AddLog(date,veh_id,log);
                    }
                }
            }
        }
    }
}

bool VehicleRegistry::PrintLogs(int id) {
    if(!vehiclelist.HasVehicle(id)){
        cout << "Cant print logs, because vehicle with ID: " << id << " doesnt exist." << endl;
        return false;
    } else{
        loglist.PrintOne(id);
        return true;
    }
}

