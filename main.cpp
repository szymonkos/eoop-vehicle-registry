#include "VehicleRegistry.h"


int main() {
    VehicleRegistry vehicleregistry; //crating vehicleregistry and adding some vehicles and owners
    vehicleregistry.PrintAll(); //testing printing empty lists
    //adding some vehicles and owners without assigning
    vehicleregistry.AddCar(100000,"Toyota","4T1B11HK6KU700665","Camry","red","WI 12345","13 april 2019 7:00");
    vehicleregistry.AddCar(100001,"BMW","WBA5R12030AK72354","330i","black", "WI 67890","13 april 2019 7:10");
    vehicleregistry.AddCar(100002,"Mercedes","WMA5R12030AK72354","C 220","white", "WI 42112","13 april 2019 7:20");
    vehicleregistry.AddCar(100003,"Honda","4BA5R12030AK72354","Accord","orange", "WI 55555","13 april 2019 7:30");
    vehicleregistry.AddCar(100004,"Bentley","SBA5R12030AK72354","Continental","silver", "WI 77777","13 april 2019 7:40");
    vehicleregistry.AddCar(100005,"Ford","1BA5R12030AK72354","Focus","green", "WI 66666","13 april 2019 7:50");
    vehicleregistry.AddCar(100006,"Fiat","7BA5R12030AK72354","500","yellow", "WI 44444","13 april 2019 8:00");
    vehicleregistry.AddCar(100007,"Peugeot","FBA5R12030AK72354","5008","blue", "WI 11111","13 april 2019 8:10");
    vehicleregistry.AddBicycle(100008,"Giant","34hrfdy5","Roam3","MTB","13 april 2019 8:20");
    vehicleregistry.AddBus(100009,"Solaris","WAA5R12030AK72354","Urbion 18", 40 ,"WI 00001","13 april 2019 8:30");
    vehicleregistry.AddHelicopter(100010,"Sikorsky","UH-60",100,"SP-001","13 april 2019 8:40");
    vehicleregistry.AddMotorcycle(100011,"Kawasaki","4KA5R12030AK72354","Vulcan","A","WI 10000","13 april 2019 8:50");
    vehicleregistry.AddPlane(100012,"Cessna","SP-002","162 Skycatcher","13 april 2019 9:00");
    vehicleregistry.AddTruck(100013,"DAF","WDA5R12030AK72354","XF105",50,"WI 00005","13 april 2019 9:10");

    vehicleregistry.AddPerson(100,"Jan","Kowalski",90010108614);
    vehicleregistry.AddPerson(200,"Karol","Nowak",9005120814);
    vehicleregistry.AddCompany(300,"Global-Transport",55556456);
    vehicleregistry.AddCompany(400,"Company2",44556456);

    vehicleregistry.PrintAll(); //printing after adding some data but before assigning owners

    //assigning some vehicles to owners
    vehicleregistry.AssignVehicleToOwner(100000,100,"13 april 2019 9:20");
    vehicleregistry.AssignVehicleToOwner(100008,100,"13 april 2019 9:30");

    vehicleregistry.AssignVehicleToOwner(100011,200,"13 april 2019 9:40");
    vehicleregistry.AssignVehicleToOwner(100001,200,"13 april 2019 9:41");
    vehicleregistry.AssignVehicleToOwner(100002,200,"13 april 2019 9:42");
    vehicleregistry.AssignVehicleToOwner(100012,200,"13 april 2019 9:43");

    vehicleregistry.AssignVehicleToOwner(100013,300,"13 april 2019 9:44");
    vehicleregistry.AssignVehicleToOwner(100010,300,"13 april 2019 9:45");
    vehicleregistry.AssignVehicleToOwner(100009,300,"13 april 2019 9:46");

    vehicleregistry.AssignVehicleToOwner(100004,400,"13 april 2019 9:47");
    vehicleregistry.AssignVehicleToOwner(100007,400,"13 april 2019 9:48");

    vehicleregistry.PrintAll(); //printing after assigning some vehicles

    vehicleregistry.AddCar(100006,"Fiat","7BA5R12030AK72354","500","yellow", "WI 44444","13 april 2019 8:00"); //testing adding vehicle with already existing id
    vehicleregistry.AddCompany(400,"Company2",44556456); //testing adding owner with already existing id
    vehicleregistry.PrintVehicle(10); //testing printing non-existent vehicle
    vehicleregistry.PrintOwner(10); //testing printing non-existent owner
    vehicleregistry.PrintLogs(10); //testing printing logs of non-existent vehicle
    vehicleregistry.RemoveVehicle(10,"13 april 2019 8:00"); //testing removing non-existent vehicle
    vehicleregistry.RemoveOwner(10,"13 april 2019 8:00"); //testing removing non-existent owner
    vehicleregistry.FreeVehicle(10,"13 april 2019 8:00"); //testing freeing non-existent vehicle
    vehicleregistry.Transfer(10,10,10,"13 april 2019 8:00");//testing transferring  non-existent vehicle

    vehicleregistry.RemoveOwner(100,"13 april 2019 9:50"); //testing removing of owner (testing if logs about freeing owners vehicles were added)
    vehicleregistry.PrintAll();

    vehicleregistry.Transfer(100007,400,200,"13 april 2019 10:00"); //testing transferring vehicle between owners and checking logs after that
    vehicleregistry.PrintAll();

    vehicleregistry.RemoveVehicle(100007,"13 april 2019 10:10");//testing removing vehicle and checking logs if it was also deleted from owner
    vehicleregistry.PrintAll();
    vehicleregistry.PrintLogs(100007);

    return 0;
}