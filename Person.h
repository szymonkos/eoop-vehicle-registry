#ifndef CPP_PROJECT2019_PERSON_H
#define CPP_PROJECT2019_PERSON_H

#include "Owner.h"
class Person : public Owner{
public:
    string name;
    string surname;
    long int pesel;
    Person();
    Person(int id, string name, string surname, long int pesel);
    ~Person();
    void Print()override;
};
#endif //CPP_PROJECT2019_PERSON_H
