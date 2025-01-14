#ifndef CPP_PROJECT2019_LOGLIST_H
#define CPP_PROJECT2019_LOGLIST_H

#include "log.h"
#include <vector>

class LogList{
public:
    vector<Log*> logs; //list of logs
    LogList(); //constructor
    ~LogList(); //destructor
    bool IsEmpty(); //checks if list of logs is empty
    void Print(); //prints full list of logs
    void PrintOne(int vehicle_id); //prints logs related to vehicle of given id
    void AddLog(string date, int vehicle_id, string log); //adds log to the list
};

#endif //CPP_PROJECT2019_LOGLIST_H
