#include "LogList.h"

LogList::LogList(){

}

LogList::~LogList(){
    logs.clear();
}

bool LogList::IsEmpty(){
    return logs.empty();
}

void LogList::Print() {
    cout << endl << "LogList:" << endl;
    if(!IsEmpty()){
        for (int i = 0; i < logs.size(); i++)
        {
            logs[i]->Print();
        }
        cout << "---End of LogList---" << endl;
    }else{
        cout << "No logs to print. LogList is empty." << endl;
    }
}

void LogList::AddLog(string date, int vehicle_id, string log){
    logs.push_back(new Log(date, vehicle_id, log));
}

void LogList::PrintOne(int vehicle_id) {
    cout << "Logs for Vehicle with ID: " << vehicle_id << " :" << endl;
    for (int i=0 ; i < logs.size() ; i++){
        if(logs[i]->vehicle_id == vehicle_id){
            logs[i]->Print();
        }
    }
    cout << "***End of Logs for vehicle with ID: " << vehicle_id << " ***" << endl;
}
