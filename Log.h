#ifndef CPP_PROJECT2019_LOG_H
#define CPP_PROJECT2019_LOG_H

#include <string>
#include <iostream>
using namespace std;

class Log{
public:
    string date; //date when log was added
    int vehicle_id; //id of vehicle that this log is about
    string log; //content of the log (description what happened at this date)
    Log(string date, int vehicle_id, string log); //constructor
    ~Log(); //destructor
    void Print(); //prints log
};

#endif //CPP_PROJECT2019_LOG_H
