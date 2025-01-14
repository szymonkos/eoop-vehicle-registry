#include "Log.h"

Log::Log(string date, int vehicle_id, string log){
    this->date = date;
    this->vehicle_id = vehicle_id;
    this->log = log;
}

Log::~Log(){

}

void Log::Print(){
    cout << "[" << date << "]" << " Vehicle with ID: " << vehicle_id << " -- Log: " << log << endl;
}
